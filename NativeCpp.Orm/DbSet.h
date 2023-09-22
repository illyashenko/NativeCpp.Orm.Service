#pragma once
#include "IEntity.h"
#include "Jobs.h"
#include "Customers.h"
#include "std_service.h"
#include "DBContext.h"
#include "DbContextOptionsBuilder.h"
#include "QueryBuilder.h"
#include "SqlService.h"

template <class TEntity>
class DbSet
{
private:
	std::string db_query;
	DbContextOptionsBuilder* options_;

	std::vector<TEntity> executeQueryWithResultIEntity(const STRING query);
	void executeQuery(const STRING query);
	PROPERTIES_SET getEntityProperties(STRING& table_name);
	PROPERTIES_MAP getAddedValues(const rttr::array_range<rttr::property>& properties, const std::list<TEntity>& entities);
	
public:

	DbSet();

	void set_options(DbContextOptionsBuilder* options);

	bool add(TEntity& entity);
	bool add_range(std::list<TEntity>& entities);
	bool create();
	bool remove();
	TEntity where(std::function<bool()> expression);
	TEntity single(int id);
	TEntity single(const STRING expression);
	std::vector<TEntity> all();
	bool update(TEntity& entity);

	TEntity _value;
};

template<class TEntity>
inline DbSet<TEntity>::DbSet()
{
}

template<class TEntity>
inline void DbSet<TEntity>::set_options(DbContextOptionsBuilder* options)
{
	this->options_ = options;
}

template<typename TEntity>
inline bool DbSet<TEntity>::add(TEntity& entity)
{
	return add_range(std::list<TEntity> {entity});
}

template<class TEntity>
inline bool DbSet<TEntity>::add_range(std::list<TEntity>& entities)
{
	const rttr::type instance = rttr::type::get<TEntity>();
	var properties = instance.get_properties();
	var table_name = instance.get_name().to_string();

	var fields = getAddedValues(properties, entities);
	var query = QueryBuilder::add(table_name, fields);

	try
	{
		executeQuery(query);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}

	return true;
}

template<typename TEntity>
inline bool DbSet<TEntity>::create()
{
}

template<typename TEntity>
inline bool DbSet<TEntity>::remove()
{
	return true;
}

template<class TEntity>
inline TEntity DbSet<TEntity>::where(std::function<bool()> expression)
{
	return TEntity();
}

template<class TEntity>
inline TEntity DbSet<TEntity>::single(int id)
{
	const rttr::type instance = rttr::type::get<TEntity>();

	var expression = Simbols::LEFT;
	expression += instance.get_name().to_string();
	expression += Simbols::RIGHT;
	expression += Simbols::POINT;
	expression += "Id";
	expression += Simbols::EQUALLY;
	expression += std::to_string(id);

	return single(expression);
}

template<class TEntity>
inline TEntity DbSet<TEntity>::single(const STRING expression)
{
	STRING table_name;

	var properties = getEntityProperties(table_name);

	var query = QueryBuilder::single_build(table_name, expression, properties);

	std::vector<TEntity> result = executeQueryWithResultIEntity(query);

	if (!result.empty())
	{
		return result[0];
	}

	return TEntity();
}

template<class TEntity>
inline std::vector<TEntity> DbSet<TEntity>::all()
{
	STRING table_name;

	var properties = getEntityProperties(table_name);

	var query = QueryBuilder::all_build(table_name, properties);

	return executeQueryWithResultIEntity(query);
}

template<class TEntity>
inline bool DbSet<TEntity>::update(TEntity& entity)
{
	return false;
}

template<class TEntity>
inline std::vector<TEntity> DbSet<TEntity>::executeQueryWithResultIEntity(const STRING query)
{
	std::vector<TEntity> listEntity;

	switch (options_->get_provider())
	{
	case SqlProvider::MS_SQL:
		listEntity = SqlService().executeToSqlResult<TEntity>(this->options_->_variant, query);
	default:
		break;
	}
	return listEntity;
}

template<class TEntity>
inline void DbSet<TEntity>::executeQuery(const STRING query)
{
	switch (options_->get_provider())
	{
	case SqlProvider::MS_SQL:
		SqlService().executeToSql(this->options_->_variant, query);
	default:
		break;
	}

}

template<class TEntity>
inline PROPERTIES_SET DbSet<TEntity>::getEntityProperties(STRING& table_name)
{
	const rttr::type instance = rttr::type::get<TEntity>();

	PROPERTIES_SET properties;

	for (auto& el : instance.get_properties()) {
		properties.insert(el.get_name().to_string());
	}

	table_name = instance.get_name().to_string();

	return properties;
}

template<class TEntity>
inline PROPERTIES_MAP DbSet<TEntity>::getAddedValues(const rttr::array_range<rttr::property>& properties, const std::list<TEntity>& entities)
{
	PROPERTIES_MAP fields;

	if (entities.empty() || properties.empty())
	{
		return fields;
	}

	for (TEntity entity : entities) 
	{
		var num_properties = properties.size();
		var columns = Simbols::LEFTROUND;
		var values = Simbols::LEFTROUND;

		for (var& prop : properties) 
		{
			--num_properties;
			if (prop.get_name() == "id" && entity.idHasPrimaryKey()) { continue; }

			columns += Simbols::LEFT;
			columns += prop.get_name().to_string();
			columns += Simbols::RIGHT;

			var value = prop.get_value(entity);
			var type_ = prop.get_type().get_name();

			if (type_ == "int") 
			{
				values += std::to_string(value.to_int());
			}
			else if (type_ == "std::string") 
			{
				values += Simbols::SINGLEQUOTES;
				values += value.to_string();
				values += Simbols::SINGLEQUOTES;
			}
			else if (type_ == "float") 
			{
				values += std::format("{:.6f}", value.to_float());
			}

			if (num_properties > 0) {
				values += Simbols::COMMA;
				values += Simbols::SPACE;

				columns += Simbols::COMMA;
				columns += Simbols::SPACE;
			}
		}

		values += Simbols::RIGHTROUND;
		columns += Simbols::RIGHTROUND;

		fields.insert(std::pair(columns, values));
	}

	return fields;
}



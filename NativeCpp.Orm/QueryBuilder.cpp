#include "QueryBuilder.h"

QueryBuilder QueryBuilder::create(STRING table_name)
{
	return QueryBuilder(table_name);
}

QueryBuilder::QueryBuilder(STRING table_name)
{
	this->table_ = table_name;
}

STRING QueryBuilder::all_build(STRING table, PROPERTIES_SET& properties)
{
	var query = QueryBuilder::create(table)
		.select()
		.set_column(properties)
		.from_table()
		.orber_by_id().Query;

	return query;
}

STRING QueryBuilder::single_build(STRING table_name, STRING expression, PROPERTIES_SET& properties)
{
	var query = QueryBuilder::create(table_name)
		.select()
		.set_column(properties)
		.from_table()
		.where(expression).Query;

	return query;
}

QueryBuilder QueryBuilder::create()
{
	return *this;
}

QueryBuilder QueryBuilder::insert()
{
	Query += Words::INSERTINTO;
	Query += Simbols::SPACE;
	Query += Simbols::LEFT;
	Query += table_;
	Query += Simbols::RIGHT;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::remove()
{
	return *this;
}

STRING QueryBuilder::add(STRING table_name, PROPERTIES_MAP columns_values)
{
	if (table_name.empty() || columns_values.empty())
	{
		return Simbols::EMPTY;
	}

	var query = QueryBuilder::create(table_name)
		.insert()
		.set_values(columns_values)
		.Query;
	
	return query;
}


QueryBuilder QueryBuilder::select()
{
	Query += Words::SELECT;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::select_top(int number)
{
	Query += Words::SELECT;
	Query += Simbols::SPACE;
	Query += Words::TOP;
	Query += Simbols::LEFTROUND;
	Query += std::to_string(number);
	Query += Simbols::RIGHTROUND;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::select_distinct()
{
	Query += Words::SELECT;
	Query += Simbols::SPACE;
	Query += Words::DISTINCT;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::set_column(PROPERTIES_SET& properties, STRING table_name)
{
	var el_count = properties.size();

	if (el_count == 0)
	{
		return *this;
	}

	for (auto& el : properties)
	{
		--el_count;
		Query += table_name.empty() ? this->table_ : table_name;
		Query += Simbols::POINT;
		Query += Simbols::LEFT;
		Query += el;
		Query += Simbols::RIGHT;

		if (el_count > 0)
		{
			Query += Simbols::COMMA;
			Query += Simbols::SPACE;
		}
	}

	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::set_values(PROPERTIES_MAP columns_values)
{
	if (!columns_values.empty())
	{
		var columns_values_size = columns_values.size();

		var it = columns_values.begin();
		std::advance(it, 0);

		Query += it->first;
		Query += Simbols::SPACE;
		Query += Words::VALUES;
		Query += Simbols::SPACE;

		for (var& el : columns_values) {

			--columns_values_size;
			Query += el.second;

			if (columns_values_size > 0)
			{
				Query += Simbols::COMMA;
			}
		}
	}

	return *this;
}

QueryBuilder QueryBuilder::from_table(STRING table_name)
{
	Query += Words::FROM;
	Query += Simbols::SPACE;
	Query += Simbols::LEFT;
	Query += table_name.empty() ? this->table_: table_name;
	Query += Simbols::RIGHT;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::join(STRING join_table_name, PROPERTIES_SET& join_expression)
{
	return QueryBuilder();
}

QueryBuilder QueryBuilder::left_join(STRING join_table_name, PROPERTIES_SET& join_expression)
{
	return QueryBuilder();
}

QueryBuilder QueryBuilder::where(STRING expression)
{
	Query += Words::WHERE;
	Query += Simbols::SPACE;
	Query += expression;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::where_and(STRING expression)
{
	Query += Words::AND;
	Query += Simbols::SPACE;
	Query += expression;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::where_or(STRING expression)
{
	Query += Words::OR;
	Query += Simbols::SPACE;
	Query += expression;
	Query += Simbols::SPACE;

	return *this;
}

QueryBuilder QueryBuilder::orber_by_id(bool desc)
{
	Query += Words::ORDERBY;
	Query += Simbols::SPACE;
	Query += "[Id]";
	Query += Simbols::SPACE;
	Query += desc ? Words::DESC : Simbols::EMPTY;
	Query += desc ? Simbols::SPACE : Simbols::EMPTY;

	return *this;
}

QueryBuilder QueryBuilder::order_by(STRING expression)
{
	Query += Words::ORDERBY;
	Query += Simbols::SPACE;
	Query += expression;
	Query += Simbols::SPACE;

	return *this;
}

STRING QueryBuilder::get_query()
{
	return this->query_;
}

void QueryBuilder::set_query(STRING value)
{
	this->query_ = value;
}

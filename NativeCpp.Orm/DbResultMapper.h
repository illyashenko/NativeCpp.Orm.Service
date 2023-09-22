#pragma once
#include "std_service.h"

class DbMapper
{
public:
	template <typename T> static std::vector<T> to_array(nanodbc::result& result);
private:
	static TIMESTAMP timestamp_null();
	static DATE date_null();
	static TIME time_null();
};

template<typename T>
inline std::vector<T> DbMapper::to_array(nanodbc::result& result)
{
	std::vector<T> repos;

	while (result.next())
	{
		IEntity entity;
		auto data = static_cast<T*>(&entity)->create<T>();
		{
			const rttr::type instance = rttr::type::get(data);

			for (auto& el : instance.get_properties())
			{
				auto type_ = el.get_type().get_name();
				auto name = el.get_name();

				rttr::property prop = instance.get_property(name);

				if (type_ == "int")
				{
					prop.set_value(data, result.get<int>(name.to_string(), NULL));
				}
				else if (type_ == "std::string")
				{
					prop.set_value(data, result.get<std::string>(name.to_string(), "null"));
				}
				else if (type_ == "float")
				{
					prop.set_value(data, result.get<float>(name.to_string(), NULL));
				}
				else if (type_ == "structnanodbc::timestamp")
				{ 
					prop.set_value(data, result.get<nanodbc::timestamp>(name.to_string(), timestamp_null()));
				}
				else if (type_ == "structnanodbc::date")
				{
					prop.set_value(data, result.get<nanodbc::date>(name.to_string(), date_null()));
				}

			};

			repos.push_back(data);
		}
	}

	return repos;
}

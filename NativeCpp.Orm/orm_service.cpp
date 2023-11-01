#pragma once
#include <cstdint>
#include <sstream>
#include <iostream>
#include "Jobs.h"
#include "Customers.h"
#include "IEntity.h"
#include "DbModelBuilder.h"
#include "DbContextOptionsBuilder.h"
#include "DBContext.h"
#include <functional>
#include <stdarg.h>
#include <typeinfo>
#include "QueryBuilder.h"


template <typename T>
std::vector<T> print_type(nanodbc::result& result) {

	std::vector<T> repos;

	while (result.next())
	{
		IEntity entity;
		auto data = static_cast<T*>(&entity)->create<T>();
		{
			const rttr::type instance = rttr::type::get(data);

			var properties = instance.get_properties();
			var num = properties.size();

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

			};

			repos.push_back(data);
		}
	}

	return repos;
}

bool test(std::function<bool()> expression) {
	return std::invoke(expression);
}

struct Context : DBContext {
	// model create database
	DbSet<Customers> customer;
	DbSet<Jobs> job;
	DbSet<CustomersAttributes> attributes;

	Context(DbContextOptionsBuilder option) : DBContext(option)
	{
		//set database options on model
		customer.set_options(&option);
		job.set_options(&option);
		attributes.set_options(&option);
	};
};

int main() {

	DbContextOptionsBuilder option;
	option.useSqlserver("Driver={ODBC Driver 17 for SQL Server};Server=localhost;DataBase=monitoring;Uid=sa;Pwd=17101030;");

	Context context(option);

	try 
	{
		var job = context.job.all();
	}
	catch (const std::exception* ex) {
		std::cout << ex->what();
	}

	PROPERTIES_SET prop{ "id", "data" };

	var str = QueryBuilder::create("jobs")
		.select()
		.set_column(prop)
		.from_table()
		.where("[id] in(1,5)")
		.orber_by_id(true)
		.Query;

	return 0;
};
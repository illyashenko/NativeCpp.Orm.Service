#pragma once
#include "std_service.h"

class QueryBuilder
{
public:
	QueryBuilder(){}
	QueryBuilder(STRING table_name);

	static QueryBuilder create(STRING table_name);

	static STRING all_build(STRING table_name, PROPERTIES_SET& properties);
	static STRING single_build(STRING table_name, STRING expression, PROPERTIES_SET& properties);

	_declspec(property(get = get_query, put = set_query)) STRING Query;

	QueryBuilder create();
	QueryBuilder insert();
	QueryBuilder remove();

	static STRING add(STRING table_name, PROPERTIES_MAP columns_values);
	//QueryBuilder add_range();

	QueryBuilder select();
	QueryBuilder select_top(int number = 1);
	QueryBuilder select_distinct();

	QueryBuilder set_column(PROPERTIES_SET& properties, STRING table_name = "");
	QueryBuilder set_values(PROPERTIES_MAP columns_values);

	QueryBuilder from_table(STRING table_name = "");

	QueryBuilder join(STRING join_table_name, PROPERTIES_SET& join_expression);
	QueryBuilder left_join(STRING join_table_name, PROPERTIES_SET& join_expression);

	QueryBuilder where(STRING expression);
	QueryBuilder where_and(STRING expression);
	QueryBuilder where_or(STRING expression);

	QueryBuilder orber_by_id(bool desc = false);
	QueryBuilder order_by(STRING expression);


	STRING get_query();
	void set_query(STRING value);

private:
	STRING table_;
	STRING query_;
};


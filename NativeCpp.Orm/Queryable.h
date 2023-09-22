#pragma once
#include "std_service.h"

class Queryable
{
public:
	void set_query(STRING query);
	STRING get_query();

	_declspec(property(get = get_query, put = set_query)) STRING Query;
private:
	STRING query;
};


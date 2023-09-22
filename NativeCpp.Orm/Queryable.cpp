#include "Queryable.h"

void Queryable::set_query(STRING query)
{
	this->query = query;
}

STRING Queryable::get_query()
{
	return this->query;
}

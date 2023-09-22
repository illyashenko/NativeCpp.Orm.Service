#pragma once
#include "IEntity.h"

struct CustomersAttributes : public IEntity
{
	CustomersAttributes(){}

	int id;
    int customer_id;
    STRING post_code;
    STRING city;
    int region;
    STRING address;
};

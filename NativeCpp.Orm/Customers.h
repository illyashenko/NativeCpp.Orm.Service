#pragma once
#include "IEntity.h"

struct Customers : public IEntity
{
    int id;
    int age;
    std::string first_name;
    std::string last_name;
    std::string email;
    std::string phone;
    float weight;

    Customers(){}
};



#pragma once
#include "IEntity.h"

struct Jobs : public IEntity
{
    Jobs(int id, TIMESTAMP create_date, STRING data) {
        this->id = id;
        this->data = data;
        this->create_date = create_date;
    }

    int id;
    TIMESTAMP create_date;
    STRING data;

    bool idHasPrimaryKey() override {
        return true;
    }

    Jobs(){}
};


#include "IEntity.h"

IEntity IEntity::ToTable(std::string table_name)
{
	this->table_name = table_name;
	return *this;
}

bool IEntity::idHasPrimaryKey()
{
	return false;
}

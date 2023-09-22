#pragma once
#include "std_service.h"

class IEntity
{
public:
	IEntity ToTable(std::string table_name);
	template<typename T> T create();
	virtual bool idHasPrimaryKey();
private:
	std::string table_name;
protected:

};

template<typename T>
inline T IEntity::create()
{
	return T();
}

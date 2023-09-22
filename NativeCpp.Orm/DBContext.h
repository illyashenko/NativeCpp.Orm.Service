#pragma once
#include"std_service.h"
#include"DbContextOptionsBuilder.h"
#include"DbSet.h"

class DBContext {
public:
	DBContext(DbContextOptionsBuilder options);

	_declspec(property(get = get_options)) DbContextOptionsBuilder Options;

	DbContextOptionsBuilder get_options();

private:
	DbContextOptionsBuilder db_options;
protected:
};

class ContextBuilder {
public:
private:
};

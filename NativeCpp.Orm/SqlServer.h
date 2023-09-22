#pragma once
#include "std_service.h"
#include <nanodbc/nanodbc.h>

using SQL_SERVER = nanodbc::connection;
using SQL_RESULT = nanodbc::result;

class SqlServer 
{

public:

	SqlServer() = default;
	SqlServer(std::string connection_string);

	SQL_RESULT ExecuteToSqlResult(std::string query);
	SqlServer* Execute(std::string query);
	std::vector<std::unordered_map<std::string, std::string>> ToList();
	SqlServer* Add();

private:

	SQL_SERVER _sql;
	SQL_RESULT _result;

};


#include "SqlServer.h"

SqlServer::SqlServer(std::string connection_string)
{
	this->_sql = SQL_SERVER(connection_string);
}

SQL_RESULT SqlServer::ExecuteToSqlResult(std::string query)
{
	return nanodbc::execute(this->_sql, query);
}

SqlServer* SqlServer::Execute(std::string query)
{
	this->_result = nanodbc::execute(this->_sql, query);
	return this;
}

std::vector<std::unordered_map<std::string, std::string>> SqlServer::ToList()
{
	return std::vector<std::unordered_map<std::string, std::string>>();
}

SqlServer* SqlServer::Add()
{
	return this;
}

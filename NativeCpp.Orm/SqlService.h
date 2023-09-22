#pragma once
#include "std_service.h"
#include "DbContextOptionsBuilder.h"
#include "DbResultMapper.h"

class SqlService
{
public:
	template <typename T> std::vector<T> executeToSqlResult(const CONNECTION_VAR& wrapped_connection,const STRING query);
	void executeToSql(const CONNECTION_VAR& wrapped_connection, const STRING query);
private:

};

template<typename T>
inline std::vector<T> SqlService::executeToSqlResult(const CONNECTION_VAR& wrapped_connection,const STRING query)
{
	var connection = get<0>(wrapped_connection);
	var result = nanodbc::execute(connection, query);

	return DbMapper::to_array<T>(result);
}

#include "SqlService.h"

void SqlService::executeToSql(const CONNECTION_VAR& wrapped_connection, const STRING query)
{
	var connection = get<0>(wrapped_connection);
	var result = nanodbc::execute(connection, query);
}

#pragma once
#include "std_service.h"
#include <nanodbc/nanodbc.h>

using CONNECTION_VAR = std::variant<nanodbc::connection, std::string>;

enum SqlProvider
{
	MS_SQL = 0,
	POSTRGRE_SQL = 1,
	MY_SQL = 2
};

class DbContextOptionsBuilder
{
public:
	void useSqlserver(STRING connection_string);
	void useSqlserver(STRING data_source, STRING user, STRING password);

	void UsePostgresServer(STRING connection_string);
	SqlProvider get_provider();
	CONNECTION_VAR _variant;
private:
	SqlProvider provider;
protected:
};


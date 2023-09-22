#include "DbContextOptionsBuilder.h"

void DbContextOptionsBuilder::useSqlserver(STRING connection_string)
{
	this->provider = SqlProvider::MS_SQL;
	this->_variant = nanodbc::connection(connection_string);
}

void DbContextOptionsBuilder::useSqlserver(STRING data_source, STRING user, STRING password)
{
	this->provider = SqlProvider::MS_SQL;
	this->_variant = nanodbc::connection(data_source, user, password);
}

void DbContextOptionsBuilder::UsePostgresServer(STRING connection_string)
{
	this->provider = SqlProvider::POSTRGRE_SQL;
	this->_variant = STRING();
}

SqlProvider DbContextOptionsBuilder::get_provider()
{
	return this->provider;
}

#include "DBContext.h"

//void DBContext::OnConfiguring(DbContextOptionsBuilder options)
//{
//	this->db_options = options;
//}

DBContext::DBContext(DbContextOptionsBuilder options)
{
	this->db_options = options;
}

DbContextOptionsBuilder DBContext::get_options()
{
	return this->db_options;
}

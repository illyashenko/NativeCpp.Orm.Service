#pragma once
#include <iostream>
#include <unordered_map>

template <typename T>
struct DbConfiguration
{
	 std::unordered_map<std::string, T*> make_table;
	void SetTable(std::string table_name, T* class_table);

};

template <typename T>
inline void DbConfiguration<T>::SetTable(std::string table_name, T* class_table)
{
	this->make_table[table_name] = class_table;
}


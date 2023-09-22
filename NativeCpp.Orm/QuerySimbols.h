#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>

class Simbols {
public:
	inline static const std::string LEFT{ "[" };
	inline static const std::string RIGHT{ "]" };
	inline static const std::string LEFTROUND{ "(" };
	inline static const std::string RIGHTROUND{ ")" };
	inline static const std::string SPACE{ " " };
	inline static const std::string POINT{ "." };
	inline static const std::string COMMA{ "," };
	inline static const std::string SINGLEQUOTES{ "'" };
	inline static const std::string EQUALLY{ "=" };
	inline static const std::string EMPTY{ "" };
};


class Words {
public:
	inline static const std::string SELECT{ "SELECT" };
	inline static const std::string FROM{ "FROM" };
	inline static const std::string ORDERBY{ "ORDER BY" };
	inline static const std::string JOIN{ "JOIN" };
	inline static const std::string LEFTJOIN{ "LEFT JOIN" };
	inline static const std::string WHERE{ "WHERE" };
	inline static const std::string AND{ "AND" };
	inline static const std::string OR{ "OR" };
	inline static const std::string GROUPBY{ "GROUP BY" };
	inline static const std::string DESC{ "DESC" };
	inline static const std::string DISTINCT{ "DISTINCT" };
	inline static const std::string TOP{ "TOP" };
	inline static const std::string TOP1{ "TOP (1)" };
	inline static const std::string TOP100{ "TOP (100)" };
	inline static const std::string TOP1000{ "TOP (1000)" };
	inline static const std::string LIMIT100{ "LIMIT 100" };
	inline static const std::string LIMIT1000{ "LIMIT 1000" };
	inline static const std::string CREATETABLE{ "CREATE TABLE" };
	inline static const std::string ALTERTABLE{ "ALTER TABLE" };
	inline static const std::string INSERTINTO{ "INSERT INTO" };
	inline static const std::string VALUES{ "VALUES" };
	inline static const std::string UPDATE{ "UPDATE" };
	inline static const std::string SET{ "SET" };
	inline static const std::string AS{ "AS" };
	inline static const std::string IN{ "IN" };
	inline static const std::string DELETE{ "DELETE" };
	inline static const std::string INTERSECT{ "INTERSECT" };
};

//
// SQL function
//
class Expressions {

public:
	//
	// IIF(condition, value_1, value_2)
	//
	inline static std::string iif(std::string condition, std::string value_1, std::string value_2) {

		std::string result = "IIF";
		result += Simbols::LEFTROUND;
		result += condition;
		result += Simbols::COMMA;
		result += Simbols::SPACE;
		result += value_1;
		result += Simbols::COMMA;
		result += Simbols::SPACE;
		result += value_2;
		result += Simbols::RIGHTROUND;

		return result;
	};

	//
	// CASE expression
	//	  WHEN value_1 THEN result_1
	//	  WHEN value_2 THEN result_2
	//	  .................................
	//	  WHEN value_N THEN result_N
	//	 [ELSE alternative_result]
	// END
	//
	inline static std::string case_when() {
		return "";
	}
};

#endif
#pragma once
#include <iostream>
#include <sstream>
#include <variant>
#include <unordered_map>
#include <list>
#include <functional>
#include <format>
#include "nanodbc/nanodbc.h"
#include "QuerySimbols.h"
#include "rttr/registration.h"

#define var auto

using STRING = std::string;
using PROPERTIES_SET = std::unordered_multiset<STRING>;
using PROPERTIES_MAP = std::unordered_map<STRING, STRING>;
using DATE = nanodbc::date;
using TIMESTAMP = nanodbc::timestamp;
using TIME = nanodbc::time;
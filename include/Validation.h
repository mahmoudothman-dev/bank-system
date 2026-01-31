#pragma once
#include <string>

class Validation {
public:
	static bool isAlphabatic(const std::string& name);
	static bool validName(const std::string& name);
	static bool validPassword(const std::string& password);
	static bool validBalance(const double balance);
	static bool validSalary(const double salary);   
};
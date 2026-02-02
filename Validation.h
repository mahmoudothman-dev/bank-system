#pragma once
#include <iostream>
#include <string>

class Validation {
public:
	static bool validName(std::string name);
	static bool validPassword(std::string password);
	static bool validBalance(double balance);
	static bool validSalary(double salary);
};

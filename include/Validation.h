#pragma once
#include <iostream>
using namespace std;

class Validation {
public:
	static bool validName(string name);
	static bool validPassword(string password);
	static bool validBalance(double balance);
	static bool validSalary(double salary);
};

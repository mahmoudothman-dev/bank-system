#pragma once
#include <iostream>
using namespace std;


class Validation {
public:
	static bool validName(string name);
	static bool validPassword(string password);
	static bool validBalance(double balance);
	static bool validSalary(double salary);
	static double validDouble(string msg);
	static int validInt(string msg);
	static string enterName(string msg);
	static string enterPassword(string msg);
	static double enterBalance(string msg);
	static double enterSalary(string msg);
	static string getPassword();
	
};

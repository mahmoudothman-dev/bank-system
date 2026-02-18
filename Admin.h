#pragma once
#include<iostream>
#include<string>
#include "Employee.h"
using namespace std;

class Admin :public Employee {


public:
	//Def const
	Admin();

	Admin(int id, string name, string password, double salary);
    
	

};



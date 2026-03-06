#pragma once
#include "Employee.h"
#include "Client.h"
#include <vector>

class Admin :public Employee {


public:
	//Def const
	Admin();

	Admin(int id, string name, string password, double salary);
    
	//Employee
	void addEmployee(Employee& employee);
	Employee* searchEmployee(int id);
	void editEmployee(int id, string name, string password, double salary) ;
	void listEmployee() ;
};



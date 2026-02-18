#include "Admin.h"
#include "Employee.h"
#include <iostream>
using namespace std;


//def const
Admin::Admin() : Employee() {}

//para const
Admin::Admin(int id, string name, string password, double salary) 
	:Employee(id, name, password, salary) {}


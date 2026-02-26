#include "Admin.h"

//def const
Admin::Admin() : Employee() {}

//para const
Admin::Admin(int id, string name, string password, double salary) 
	:Employee(id, name, password, salary) {}


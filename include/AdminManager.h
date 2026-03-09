#pragma once
#include "Admin.h"
#include "EmployeeManager.h"

class AdminManager {
public:
	static void printAdminMenu();
	
	static Admin* login(int id, string password);

	static bool adminOptions(Admin* admin);

	static void newEmployee(Admin* admin);

	static void listAllEmployees(Admin* admin);

	static void searchForEmployee(Admin* admin);

	static void editEmployeeInfo(Admin* admin);

};


#pragma once
#include "Employee.h"
#include "ClientManager.h"

class EmployeeManager {
public:

	static void printEmployeeMenu();

	static void newClient(Employee* employee);

	static void listAllClients(Employee* employee);

	static Client* searchForClient(Employee* employee);

	static void editClientInfo(Employee* employee);

	static Employee* login(int id, string password);

	static bool employeeOptions(Employee* employee);

	static void backOrExit(Employee* employee);

	static void deleteTheClient(Employee* employee);

};


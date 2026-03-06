#pragma once
#include "Employee.h"
#include <fstream>
#include "Parser.h"

#define clientsFile "data/clients.txt"
#define employeesFile "data/employees.txt"
#define adminsFile "data/admins.txt"

#define lastClientId "data/lastClientId"
#define lastEmployeeId "data/lastEmployeeId"
#define lastAdminId "data/lastAdminId"

class FilesHelper {
public:
	static void saveLast(string fileName, int id);
	static int getLast(string fileName);
	static void saveClient(Client c);
	static void saveEmployee(Employee e);
	static void saveAdmin(Admin a);
	static void getClients();
	static void getEmployees();
	static void getAdmins();
	static void clearFile(string fileName, string lastIdFile);
};


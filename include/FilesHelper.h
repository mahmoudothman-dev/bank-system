#pragma once
#include "Employee.h"
#include <fstream>
#include "Parser.h"

class FilesHelper {
public:
	static void saveLast(string fileName, int id);
	static int getLast(string fileName);
	static void saveClient(Client c);
	static void saveEmployee(string fileName, string lastIdFile, Employee e);
	static vector<Client> getClients();
	static vector<Employee> getEmployees();
	static vector<Admin> getAdmins();
	static void clearFile(string fileName, string lastIdFile);
};


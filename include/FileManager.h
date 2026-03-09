#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface {
public:

	static void addClient(Client obj);

	static void addEmployee(Employee obj);

	static void addAdmin(Admin obj);

	static void getAllClients();

	static void getAllEmployees();

	static void getAllAdmins();

	static void removeAllClients();

	static void removeAllEmployees();

	static void removeAllAdmins();

};




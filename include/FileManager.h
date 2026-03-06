#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface {
public:

	void addClient(Client obj);

	void addEmployee(Employee obj);

	void addAdmin(Admin obj);

	void getAllClients();

	void getAllEmployees();

	void getAllAdmins();

	void removeAllClients();

	void removeAllEmployees();

	void removeAllAdmins();

};




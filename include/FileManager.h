#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include "Validation.h"

class FileManager : public DataSourceInterface {
public:

	static void addClient(Client obj);

	static void addEmployee(Employee obj);

	static void addAdmin(Admin obj);

	static void addTransaction(Transaction t);

	static void getAllClients();

	static void getAllEmployees();

	static void getAllAdmins();

	static void getAllTransactions();

	static void removeAllClients();

	static void removeAllEmployees();

	static void removeAllAdmins();

	static void getAllData();

	static void updateClients();

	static void updateEmployees();

	static void updateAdmins();

	
};




#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface {
	void addClient(Client obj) {
		FilesHelper::saveClient(obj);
	}
	void addEmployee(Employee obj) {
		FilesHelper::saveEmployee(obj);
	}
	void addAdmin(Admin obj) {
		FilesHelper::saveAdmin(obj);
	}
	void getAllClients() {
		FilesHelper::getClients();
	}
	void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	void removeAllClients() {
		FilesHelper::clearFile(clientsFile, lastClientId);
	}
	void removeAllEmployees() {
		FilesHelper::clearFile(employeesFile, lastEmployeeId);
	}
	void removeAllAdmins() {
		FilesHelper::clearFile(adminsFile, lastAdminId);
	}
};

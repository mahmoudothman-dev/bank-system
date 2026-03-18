#include "FileManager.h"

void FileManager::addClient(Client obj) {
	FilesHelper::saveClient(obj);
}
void FileManager::addEmployee(Employee obj) {
	FilesHelper::saveEmployee(obj);
}

void FileManager::addTransaction(Transaction t) {
	FilesHelper::saveTransaction(t);
}

void FileManager::addAdmin(Admin obj) {
	FilesHelper::saveAdmin(obj);
}
void FileManager::getAllClients() {
	FilesHelper::getClients();
}
void FileManager::getAllEmployees() {
	FilesHelper::getEmployees();
}

void FileManager::getAllTransactions() {
	FilesHelper::getTransactions();
}

void FileManager::getAllAdmins() {
	FilesHelper::getAdmins();
}
void FileManager::removeAllClients() {
	FilesHelper::clearFile(clientsFile, lastClientId);
}
void FileManager::removeAllEmployees() {
	FilesHelper::clearFile(employeesFile, lastEmployeeId);
}
void FileManager::removeAllAdmins() {
	FilesHelper::clearFile(adminsFile, lastAdminId);
}

void FileManager::getAllData() {
	getAllClients();
	getAllEmployees();
	getAllAdmins();
	getAllTransactions();
}

void FileManager::updateClients() {
	removeAllClients();
	for (int i = 0; i < Client::allClients.size(); i++) {
		addClient(Client::allClients[i]);
	}
}

void FileManager::updateEmployees() {
	removeAllEmployees();
	for (int i = 0; i < Employee::allEmployees.size(); i++) {
		addEmployee(Employee::allEmployees[i]);
	}
}

void FileManager::updateAdmins() {
	removeAllAdmins();
	for (int i = 0; i < Admin::allAdmins.size(); i++) {
		addAdmin(Admin::allAdmins[i]);
	}
}



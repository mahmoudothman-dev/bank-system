#include "FileManager.h"

void FileManager::addClient(Client obj) {
	FilesHelper::saveClient(obj);
}
void FileManager::addEmployee(Employee obj) {
	FilesHelper::saveEmployee(obj);
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

#include "FilesHelper.h"

void FilesHelper::saveLast(string fileName, int id) {
	ofstream file(fileName);
	file << id;
	file.close();
}

int FilesHelper::getLast(string fileName) {
	int id = 0;
	ifstream file(fileName);
	if (file.is_open()) {
		file >> id;
	}
	file.close();
	return id;
}

void FilesHelper::saveClient(Client c) {
	ofstream file("data/clients.txt", ios::app);

	file << c.getId() << ','
		<< c.getName() << ','
		<< c.getPassword() << ','
		<< c.getBalance() << endl;

	file.close();
}

void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e) {
	ofstream file(fileName, ios::app);

	file << e.getId() << ','
		<< e.getName() << ','
		<< e.getPassword() << ','
		<< e.getSalary() << endl;
	file.close();

	saveLast(lastIdFile, e.getId());
}

vector<Client> FilesHelper::getClients() {
	vector<Client> clients;
	ifstream file("data/clients.txt");
	string line;

	while (getline(file, line)) {
		
		clients.push_back(Parser::parseToClient(line));
		
	}
	
	file.close();
	return clients;
}

vector<Employee> FilesHelper::getEmployees() {
	vector<Employee> employees;
	ifstream file("data/employees.txt");
	string line;

	while (getline(file, line)) {

		employees.push_back(Parser::parseToEmployee(line));

	}

	file.close();
	return employees;
}

vector<Admin> FilesHelper::getAdmins() {
	vector<Admin> admins;
	ifstream file("data/admins.txt");
	string line;

	while (getline(file, line)) {

		admins.push_back(Parser::parseToAdmin(line));

	}

	file.close();
	return admins;
}

void FilesHelper::clearFile(string fileName, string lastIdFile) {
	ofstream file(fileName, ios::trunc);
	file.clear();
	file.close();
	ofstream file2(lastIdFile, ios::trunc);
	file2.clear();
	file2.close();
}
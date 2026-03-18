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
	ofstream file(clientsFile, ios::app);

	file << c.getId() << ','
		<< c.getName() << ','
		<< c.getPassword() << ','
		<< c.getBalance() << endl;

	file.close();
	
	saveLast(lastClientId, c.getId());

}

void FilesHelper::saveEmployee(Employee e) {
	ofstream file(employeesFile, ios::app);

	file << e.getId() << ','
		<< e.getName() << ','
		<< e.getPassword() << ','
		<< e.getSalary() << endl;
	file.close();

	saveLast(lastEmployeeId, e.getId());
}

void FilesHelper::saveAdmin(Admin a) {
	ofstream file(adminsFile, ios::app);

	file << a.getId() << ','
		<< a.getName() << ','
		<< a.getPassword() << ','
		<< a.getSalary() << endl;
	file.close();

	saveLast(lastAdminId, a.getId());
}

void FilesHelper::getClients() {
	
	ifstream file(clientsFile);
	string line;

	while (getline(file, line)) {
		
		Client::allClients.push_back(Parser::parseToClient(line));
		
	}
	
	file.close();
	
}

void FilesHelper::getEmployees() {

	ifstream file(employeesFile);
	string line;

	while (getline(file, line)) {

		Employee::allEmployees.push_back(Parser::parseToEmployee(line));

	}

	file.close();
	
}

void FilesHelper::getTransactions() {
	ifstream file(transactionFile);
	string line;
	while (getline(file, line)) {
		Transaction::allTransactions.push_back(Parser::parseToTransaction(line));
	}
	file.close();
}

void FilesHelper::getAdmins() {
	
	ifstream file(adminsFile);
	string line;

	while (getline(file, line)) {

		Admin::allAdmins.push_back(Parser::parseToAdmin(line));

	}

	file.close();
	
}


void FilesHelper::clearFile(string fileName, string lastIdFile) {
	ofstream file(fileName, ios::out);
	file.close();
	ofstream file2(lastIdFile, ios::out);
	
	file2.close();
}

void FilesHelper::saveTransaction(Transaction t) {
	ofstream file(transactionFile, ios::app);
	file << t.getId() << ','
		<< t.getType() << ','
		<< t.getAmount() << ','
		<< t.getDate().getDay() << ','
		<< t.getDate().getMonth() << ','
		<< t.getDate().getYear() << ','
		<< t.getDate().getHour() << ','
		<< t.getDate().getMinute() << ','
		<< t.getDate().getSecond() << endl;

	file.close();
}

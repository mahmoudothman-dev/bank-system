#include "Employee.h"
#include "Validation.h"

vector<Employee> Employee::allEmployees;

Employee::Employee() : Person() {
	salary = 5000;
}
Employee::Employee(int id, string name, string password, double salary)
	: Person(id, name, password) {
	setSalary(salary);
}

void Employee::setSalary(double salary) {
	if (Validation::validSalary(salary)) {
		this->salary = salary;
	}
}

double Employee::getSalary() {
	return salary;
}

void Employee::display() {
	Person::display();
	cout << "Salary: " << salary << endl;
}

void Employee::addClient(Client& client) {
	Client::allClients.push_back(client);
}

Client* Employee::searchClient(int id) {
	for (int i = 0; i < Client::allClients.size(); i++) {
		if (Client::allClients[i].getId() == id) {
			return &Client::allClients[i];
		}
	}
	return nullptr;
}

void Employee::listClient() {
	for (int i = 0; i < Client::allClients.size(); i++) {
		Client::allClients[i].display();
		cout << "====================================" << endl;
	}
}

void Employee::editClient(int id, string name, string password, double balance) {
	
	for (int i = 0; i < Client::allClients.size(); i++) {
		if (Client::allClients[i].getId() == id) {
			Client::allClients[i].setName(name);
			Client::allClients[i].setPassword(password);
			Client::allClients[i].setBalance(balance);
		}
	}
	
	
}
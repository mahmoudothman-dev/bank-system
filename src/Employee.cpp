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
	cout << "Salary: " << salary << " EGP" << endl;
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
	
	cout << "Total clients: " << Client::allClients.size() << endl << endl;
	cout << fixed << setprecision(2);

	cout << left << setw(6) << "ID"
		<< setw(30) << "Name"
		<< setw(30) << "Password"
		<< setw(10) << "Balance" << endl;

	cout << string(76, '-') << endl;


	for (auto client : Client::allClients) {
		cout << left << setw(6) << client.getId()
			<< setw(30) << client.getName()
			<< setw(30) << client.getPassword()
			<< setw(10) << client.getBalance() << " EGP" << endl << endl;
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

void Employee::deleteClient(int id) {

	for (int i = 0; i < Client::allClients.size(); i++) {
		 

		if (id == Client::allClients[i].getId()) {
			for (int j = i; j < Client::allClients.size() - 1; j++) {
				Client::allClients[j] = Client::allClients[j + 1];
			}
			Client::allClients.pop_back();

			return;
		}
		
	}
}
#pragma once

#include "Client.h"
#include <iomanip>

class Employee : public Person {
private:
	double salary;

public:
	
	static vector<Employee> allEmployees;
	Employee();

	Employee(int id, string name, string password, double salary);

	void setSalary(double salary);

	double getSalary();

	void display();

	void addClient(Client& client);

	Client* searchClient(int id);

	void listClient();

	void editClient(int id, string name, string password, double balance);

	void deleteClient(int id);

};



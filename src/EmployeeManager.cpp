#include "EmployeeManager.h"

void EmployeeManager::printEmployeeMenu() {
	cout << "(1) Display my info" << endl;
	cout << "(2) Add new client" << endl;
	cout << "(3) List all clients" << endl;
	cout << "(4) Search for Client" << endl;
	cout << "(5) Edit client info" << endl;
	cout << "(6) Logout" << endl;

	for (int i = 0; i < 4; i++) {
		cout << endl;
	}
}

void EmployeeManager::newClient(Employee* employee) {

	int id;
	string name, password;
	double balance;
	cout << "Enter client id: ";
	cin >> id;
	cout << "Enter client name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter client password: ";
	cin >> password;
	cout << "Enter client balance: ";
	cin >> balance;
	Client* c = new Client(id, name, password, balance);
	employee->addClient(*c);

}

void EmployeeManager::listAllClients(Employee* employee) {
	employee->listClient();
}

void EmployeeManager::searchForClient(Employee* employee) {
	int id;
	cout << "Enter client id: ";
	cin >> id;

	Client* c = employee->searchClient(id);
	if (c != nullptr) {
		c->display();
	}
	else {
		cout << "There is no client with this id" << endl;
	}
}

void EmployeeManager::editClientInfo(Employee* employee) {
	int id;
	string name, password;
	double balance;
	cout << "Enter id: ";
	cin >> id;
	
	cout << "Enter new name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter new password: ";
	cin >> password;
	cout << "Enter new balance: ";
	cin >> balance;

	employee->editClient(id, name, password, balance);
}

Employee* EmployeeManager::login(int id, string password) {
	for (int i = 0; i < Employee::allEmployees.size(); i++) {
		if (Employee::allEmployees[i].getId() == id) {
			if (Employee::allEmployees[i].getPassword() == password) {
				return &Employee::allEmployees[i];
			}
			else {
				cout << "Wrong password" << endl;
			}
		}
		else {
			cout << "There is no employee with this id" << endl;
		}

	}
	return nullptr;
}

bool EmployeeManager::employeeOptions(Employee* employee) {
	cout << "\t\t\t\t\t==================\n";
	cout << "\t\t\t\t\t    EMPLOYEE MENU    \n";
	cout << "\t\t\t\t\t==================\n";

	printEmployeeMenu();
	int num;
	cout << "Enter your choice: ";
	cin >> num;
	system("cls");

	switch (num) {
	case 1:
		employee->display();
		break;
	case 2:
		newClient(employee);
		break;
	case 3:
		listAllClients(employee);
		break;
	case 4:

		searchForClient(employee);
		break;
	case 5: {
		int id;
		cout << "Enter client id: ";
		cin >> id;
		Client* c = employee->searchClient(id);
		if (c != nullptr) {
			for (int i = 0; i < 2; i++) {
				cout << endl;
			}
			cout << "CLIENT INFO:" << endl;
			c->display();
			for (int i = 0; i < 2; i++) {
				cout << endl;
			}

			editClientInfo(employee);

			for (int i = 0; i < 2; i++) {
				cout << endl;
			}
			cout << "CLIENT INFO:" << endl;
			c->display();
			for (int i = 0; i < 2; i++) {
				cout << endl;
			}
		}
		else {
			cout << "There is no client with this id" << endl;
		}
		break;
	}
		

	case 6:
		return false;

	}
	return true;
}


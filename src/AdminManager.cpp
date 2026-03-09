#include "AdminManager.h"

void AdminManager::printAdminMenu() {
	cout << "(1) Display my info" << endl;
	cout << "(2) Add new client" << endl;
	cout << "(3) List all clients" << endl;
	cout << "(4) Search for Client" << endl;
	cout << "(5) Edit client info" << endl;
	cout << "(6) Add new employee" << endl;
	cout << "(7) List all employees" << endl;
	cout << "(8) Search for employee" << endl;
	cout << "(9) Edit employee info" << endl;
	cout << "(10) Logout" << endl;

	for (int i = 0; i < 4; i++) {
		cout << endl;
	}
}

Admin* AdminManager::login(int id, string password) {
	for (int i = 0; i < Admin::allAdmins.size(); i++) {
		if (Admin::allAdmins[i].getId() == id) {
			if (Admin::allAdmins[i].getPassword() == password) {
				return &Admin::allAdmins[i];
			}
			else {
				cout << "Wrong password" << endl;
			}
		}
		else {
			cout << "There is no admin with this id" << endl;
		}

	}
	return nullptr;
	
}

void AdminManager::newEmployee(Admin* admin) {
	int id;
	string name, password;
	double salary;
	cout << "Enter employee id: ";
	cin >> id;
	cout << "Enter employee name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter employee password: ";
	cin >> password;
	cout << "Enter employee balance: ";
	cin >> salary;
	Employee* e = new Employee(id, name, password, salary);
	admin->addEmployee(*e);
}

void AdminManager::listAllEmployees(Admin* admin) {
	admin->listEmployee();
}

void AdminManager::searchForEmployee(Admin* admin) {
	int id;
	cout << "Enter employee id: ";
	cin >> id;

	Employee* e = admin->searchEmployee(id);
	if (e != nullptr) {
		e->display();
	}
	else {
		cout << "There is no employee with this id" << endl;
	}
}

void AdminManager::editEmployeeInfo(Admin* admin) {
	int id;
	string name, password;
	double salary;

	cout << "Enter id: ";
	cin >> id;
	cout << "Enter new name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter new password: ";
	cin >> password;
	cout << "Enter new salary: ";
	cin >> salary;

	admin->editEmployee(id, name, password, salary);
}

bool AdminManager::adminOptions(Admin* admin) {
	cout << "\t\t\t\t\t==================\n";
	cout << "\t\t\t\t\t    ADMIN MENU    \n";
	cout << "\t\t\t\t\t==================\n";

	printAdminMenu();
	int num;
	cout << "Enter your choice: ";
	cin >> num;
	system("cls");


	switch (num) {
	case 1:
		admin->display();
		break;
	case 2:
		EmployeeManager::newClient(admin);
		break;
	case 3:
		EmployeeManager::listAllClients(admin);
		break;
	case 4:

		EmployeeManager::searchForClient(admin);
		break;
	case 5: {
		int id;
		cout << "Enter client id: ";
		cin >> id;
		Client* c = admin->searchClient(id);
		if (c != nullptr) {
			EmployeeManager::editClientInfo(admin);
		}
		else {
			cout << "There is no client with this id" << endl;
		}
		break;
	}
		

	case 6:
		newEmployee(admin);
		break;
	case 7:
		listAllEmployees(admin);
		break;
	case 8:
		searchForEmployee(admin);
		break;
	case 9: {
		int id;
		cout << "Enter employee id: ";
		cin >> id;
		Employee* e = admin->searchEmployee(id);
		if (e != nullptr) {
			for (int i = 0; i < 2; i++) {
				cout << endl;
			}
			cout << "EMPLOYEE INFO:" << endl;
			e->display();
			for (int i = 0; i < 2; i++) {
				cout << endl;
			}

			editEmployeeInfo(admin);

			for (int i = 0; i < 2; i++) {
				cout << endl;
			}
			cout << "EMPLOYEE INFO:" << endl;
			e->display();
			for (int i = 0; i < 2; i++) {
				cout << endl;
			}
		}
		else {
			cout << "There is no employee with this id" << endl;
		}
		break;
	}
		
	case 10:
		return false;

	}
	return true;
}

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
	cout << "(10) Update password" << endl;
	cout << "(11) Logout" << endl;
	cout << "(12) Delete Employee" << endl;
	cout << "(13) Delete Client" << endl;
	cout << "(14) Total money" << endl;
	cout << "(0) Exit\n" << endl;


	
}

void AdminManager::backOrExit(Admin* admin) {
	cout << "\n\n(1) Options\t\t\t\t(0) Exit\n";
	int choice = Validation::validInt("Enter your choice: ");
	switch (choice) {
	case 1:
		system("cls");
		adminOptions(admin);
		break;
	case 0:
		exit(0);

	default:
		cout << "Invalid choice, try again";
		backOrExit(admin);
	}
}

Admin* AdminManager::login(int id, string password) {
	for (int i = 0; i < Admin::allAdmins.size(); i++) {
		if (Admin::allAdmins[i].getId() == id && 
			Admin::allAdmins[i].getPassword() == password) {
			
				return &Admin::allAdmins[i];
			
			
		}
		

	}
	return nullptr;
	
}

void AdminManager::showTotalMoney() {
	
	double money = 0;
	for (auto client : Client::allClients) {
		money += client.getBalance();
	}

	cout << "Total money: " << money << endl;
}

void AdminManager::deleteTheEmployee(Admin* admin) {
	int id = Validation::validInt("Enter id: ");
	if (admin->searchEmployee(id)) {
		admin->deleteEmployee(id);
		cout << "Employee deleted successfully" << endl;
	}
}

void AdminManager::newEmployee(Admin* admin) {
	Employee e;
	e.setId(FilesHelper::getLast(lastEmployeeId) + 1);
	e.setName(Validation::enterName("Enter name: "));
	string password = Validation::enterPassword("Enter password: ");

	while (true) {
		string password2 = Validation::enterPassword("Confirm password: ");
		if (password == password2) {
			e.setPassword(password);
			break;

		}
		cout << "Passwords don't match" << endl;
	}
	e.setSalary(Validation::enterSalary("Enter salary: "));
	admin->addEmployee(e);
	FileManager::addEmployee(e);
	cout << "Employee added successfully";
}

void AdminManager::listAllEmployees(Admin* admin) {
	
	admin->listEmployee();
}

Employee* AdminManager::searchForEmployee(Admin* admin) {
	int id = Validation::validInt("Enter id: ");


	Employee* e = admin->searchEmployee(id);
	if (e) {
		cout << endl;
		e->display();
		cout << endl;
	}
	else {
		cout << "There is no employee with this id" << endl;
	}
	return e;
}

void AdminManager::editEmployeeInfo(Admin* admin) {
	Employee* e = searchForEmployee(admin);
	if (e) {
		e->setName(Validation::enterName("Enter new name: "));
		e->setPassword(Validation::enterPassword("Enter new password: "));
		e->setSalary(Validation::enterSalary("Enter new salary: "));

	}
	FileManager::updateEmployees();
	cout << "Employee data updated successfully" << endl;
}

bool AdminManager::adminOptions(Admin* admin) {
	
	system("cls");

	cout << "\t\t\t\t\t==================\n";
	cout << "\t\t\t\t\t    ADMIN MENU    \n";
	cout << "\t\t\t\t\t==================\n\n";



	cout << "---------" << admin->getName() << "---------\n\n";


	printAdminMenu();
	int num = Validation::validInt("Enter your choice: ");
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
		EmployeeManager::editClientInfo(admin);
		FileManager::updateClients();
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
		editEmployeeInfo(admin);
		FileManager::updateEmployees();
		break;
	}
	case 10:
		ClientManager::updatePassword(admin);
		FileManager::updateAdmins();
		break;

	case 11:
		return false;

	case 12:
		deleteTheEmployee(admin);
		FileManager::updateEmployees();
		break;

	case 13:
		EmployeeManager::deleteTheClient(admin);
		FileManager::updateClients();
		break;

	case 14:
		showTotalMoney();
		break;

	case 0:
		exit(0);

	default:
		system("cls");
		adminOptions(admin);
	}
	backOrExit(admin);

	return true;
}

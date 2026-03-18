#include "EmployeeManager.h"

void EmployeeManager::printEmployeeMenu() {
	cout << "(1) Display my info" << endl;
	cout << "(2) Add new client" << endl;
	cout << "(3) List all clients" << endl;
	cout << "(4) Search for Client" << endl;
	cout << "(5) Edit client info" << endl;
	cout << "(6) Update password" << endl;
	cout << "(7) Logout" << endl;
	cout << "(8) Delete client" << endl;
	cout << "(0) Exit\n" << endl;


	
}

void EmployeeManager::backOrExit(Employee* employee) {
	cout << "\n\n(1) Options\t\t\t\t(0) Exit\n";
	int choice = Validation::validInt("Enter your choice: ");
	switch (choice) {
	case 1:
		system("cls");
		employeeOptions(employee);
		break;
	case 0:
		exit(0);

	default:
		cout << "Invalid choice, try again";
		backOrExit(employee);
	}
}

void EmployeeManager::deleteTheClient(Employee* employee) {
	int id = Validation::validInt("Enter id: ");
	if (employee->searchClient(id)) {
		employee->deleteClient(id);
		cout << "Client deleted successfully" << endl;
	}
	
}


void EmployeeManager::newClient(Employee* employee) {
	Client c;
	c.setId(FilesHelper::getLast(lastClientId) + 1);
	c.setName(Validation::enterName("Enter name: "));
	string password = Validation::enterPassword("Enter password: ");

	while (true) {
		string password2 = Validation::enterPassword("Confirm password: ");
		if (password == password2) {
			c.setPassword(password);
			break;

		}
		cout << "Passwords don't match" << endl;
	}

	
	
	c.setBalance(Validation::enterBalance("Enter balance: "));
	employee->addClient(c);
	FileManager::addClient(c);
	cout << "Client added successfully";
	

}

void EmployeeManager::listAllClients(Employee* employee) {
	
	employee->listClient();
}

Client*  EmployeeManager::searchForClient(Employee* employee) {
	int id = Validation::validInt("Enter id: ");
	

	Client* c = employee->searchClient(id);
	if (c) {
		cout << endl;
		c->display();
		cout << endl;
	}
	else {
		cout << "There is no client with this id" << endl;
	}
	return c;
}

void EmployeeManager::editClientInfo(Employee* employee) {
	Client* c = searchForClient(employee);
	if (c) {
		c->setName(Validation::enterName("Enter new name: "));
		c->setPassword(Validation::enterPassword("Enter new password: "));
		c->setBalance(Validation::enterBalance("Enter new balance: "));

	}
	FileManager::updateClients();
	cout << "Client data updated successfully" << endl;
}

Employee* EmployeeManager::login(int id, string password) {
	for (int i = 0; i < Employee::allEmployees.size(); i++) {
		if (Employee::allEmployees[i].getId() == id && 
			Employee::allEmployees[i].getPassword() == password) {
			
				return &Employee::allEmployees[i];
			
			
		}
		

	}
	return nullptr;
}

bool EmployeeManager::employeeOptions(Employee* employee) {

	system("cls");

	cout << "\t\t\t\t\t==================\n";
	cout << "\t\t\t\t\t    EMPLOYEE MENU   \n";
	cout << "\t\t\t\t\t==================\n\n";



	cout << "---------" << employee->getName() << "---------\n\n";

	printEmployeeMenu();
	int num = Validation::validInt("Enter your choice: ");
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
		editClientInfo(employee);
		FileManager::updateClients();
		break;
	}
	case 6:
		ClientManager::updatePassword(employee);
		FileManager::updateEmployees();
		break;

	case 7:
		return false;

	case 8:
		deleteTheClient(employee);
		FileManager::updateClients();
		break;

	case 0:
		exit(0);

	default:
		system("cls");
		employeeOptions(employee);

	}
	backOrExit(employee);

	return true;
}


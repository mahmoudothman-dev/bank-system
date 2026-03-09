#include "ClientManager.h"

void ClientManager::printClientMenu() {
	cout << "(1) Display my info" << endl;
	cout << "(2) Update my password" << endl;
	cout << "(3) Deposite money" << endl;
	cout << "(4) Withdraw money" << endl;
	cout << "(5) Transfer money" << endl;
	cout << "(6) Display my balance" << endl;
	cout << "(7) Logout" << endl;

	for (int i = 0; i < 4; i++) {
		cout << endl;
	}
}

void ClientManager::updatePassword(Person* person) {
	string password;
	
	
	while (true) {
		cout << "Enter new Password: ";
		cin >> password;
		if (password != person->getPassword()) {
			if (person->setPassword(password)) {
				cout << "Password changed successfully";

				break;
			}
			
			
		}
		else if (password == person->getPassword()) {
			cout << "It's already your old password, please enter new password" 
				<< endl;
		}
	}
	
}

Client* ClientManager::login(int id, string password) {
	for (int i = 0; i < Client::allClients.size(); i++) {
		if (Client::allClients[i].getId() == id) {
			if (Client::allClients[i].getPassword() == password) {
				return &Client::allClients[i];
			}
			else {
				cout << "Wrong password" << endl;
				break;
			}
		}
		else {
			cout << "There is no client with this id, try again" << endl;
			break;
		}
		
	}
	return nullptr;
}

bool ClientManager::clientOptions(Client* client) {
	cout << "\t\t\t\t\t==================\n";
	cout << "\t\t\t\t\t    CLIENT MENU    \n";
	cout << "\t\t\t\t\t==================\n";

	printClientMenu();
	int num;
	cout << "Enter your choice: ";
	cin >> num;
	system("cls");

	switch (num) {
	case 1:

		client->display();
		//cout << "=================================";
		break;
	case 2:
		updatePassword(client);
		
		break;
	case 3: {
		int money;
		cout << "Balance: " << client->getBalance() << endl;
		cout << "Enter money amount you want to deposit: ";
		cin >> money;
		client->deposit(money);
		cout << "Balance: " << client->getBalance() << endl;
		break;
	}
		
	case 4: {
		int money;
		cout << "Balance: " << client->getBalance() << endl;

		cout << "Enter money amout you want to withdraw: ";
		cin >> money;
		client->withdraw(money);
		cout << "Balance: " << client->getBalance() << endl;

		break;
	}
		
		
	case 5: {
		int id, money = 0;
		cout << "Enter client id: ";
		cin >> id;
		Employee* e = nullptr;
		Client* c = e->searchClient(id);
		if (c != nullptr) {
			client->transfer(*c, money);
		}
		else {
			cout << "There is no client with this id" << endl;
		}
		//cout << "=================================";

		break;
	}
		
	case 6:
		cout << "Balance: " << client->getBalance();
		//cout << "=================================";
		break;
	case 7:
		return false;
	
	}
	

	
	return true;
}
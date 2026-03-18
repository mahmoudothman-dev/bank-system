#include "ClientManager.h"

void ClientManager::printClientMenu() {
	cout << "(1) Display my info" << endl;
	cout << "(2) Update my password" << endl;
	cout << "(3) Deposite money" << endl;
	cout << "(4) Withdraw money" << endl;
	cout << "(5) Transfer money" << endl;
	cout << "(6) Display my balance" << endl;
	cout << "(7) Logout" << endl;
	cout << "(8) View my transactions" << endl;
	cout << "(0) Exit\n" << endl;

	
}

void ClientManager::backOrExit(Client* client) {
	cout << "\n\n(1) Options\t\t\t\t(0) Exit\n";
	int choice = Validation::validInt("Enter your choice: ");
	switch (choice) {
	case 1:
		system("cls");
		clientOptions(client);
		break;
	case 0:
		exit(0);

	default:
		cout << "Invalid choice, try again";
		backOrExit(client);
	}
}

void ClientManager::updatePassword(Person* person) {
	while (true) {
		string password = Validation::enterPassword("Enter password: ");
		if (password == person->getPassword()) {
			cout << "It's already your password, try again" << endl;
			continue;

		}
		
		while (true) {
			string password2 = Validation::enterPassword("Confirm password: ");
			if (password == password2) {
				person->setPassword(password);
				cout << "Password updated successfully" << endl;
				return;

			}
		}
		
	}
	
	
	
}

void ClientManager::viewTransaction(Client* client) {
	
	cout << fixed << setprecision(2);

	cout << left << setw(30) << "Type"
		<< setw(20) << "Amount"
		<< setw(30) << "Date" << endl;
		

	cout << string(76, '-') << endl;


	for (int i = Transaction::allTransactions.size() - 1; i > 0; i--) {
		Transaction t = Transaction::allTransactions[i];
		Date d = t.getDate();

		if (client->getId() == t.getId()) {
			cout << left << setw(30) << t.getType()
				<< setw(20) << t.getAmount()
				<< setw(30) 
				<< (to_string(d.getDay()) + '/' +
					to_string(d.getMonth()) + '/' +
					to_string(d.getYear()) + ' ' +
					to_string(d.getHour()) + ':' +
					to_string(d.getMinute()) + ':' +
					to_string(d.getSecond())) << endl << endl;
				
				
				



		}
	}
	
	
	

}

Client* ClientManager::login(int id, string password) {
	for (int i = 0; i < Client::allClients.size(); i++) {
		if (Client::allClients[i].getId() == id && 
			Client::allClients[i].getPassword() == password) {
			
				return &Client::allClients[i];
		
			
		}
		
		
	}
	return nullptr;
}

bool ClientManager::clientOptions(Client* client) {
	
	cout << system("cls");

	cout << "\t\t\t\t\t==================\n";
	cout << "\t\t\t\t\t    CLIENT MENU    \n";
	cout << "\t\t\t\t\t==================\n\n";



	cout << "---------" << client->getName() << "---------\n\n";


	printClientMenu();
	int num = Validation::validInt("Enter your choice: ");

	system("cls");

	switch (num) {
	case 1:

		client->display();
		
		break;
	case 2:
		updatePassword(client);
		FileManager::updateClients();
		break;
	case 3: {
		double money = Validation::validDouble("Enter amount: ");
		client->deposit(money);
		FileManager::updateClients();
		Transaction t(client->getId(), "Deposite", money, Date::getCurrentDate());
		Transaction::allTransactions.push_back(t);
		FileManager::addTransaction(t);

		break;
	}

	case 4: {
		double money = Validation::validDouble("Enter amount: ");
		client->withdraw(money);
		FileManager::updateClients();
		Transaction t(client->getId(), "Withdraw", money, Date::getCurrentDate());
		Transaction::allTransactions.push_back(t);

		FileManager::addTransaction(t);

		break;
	}


	case 5: {
		int id = Validation::validInt("Enter recipient id: ");

		double money = Validation::validDouble("Enter amount: ");
		Employee* e = nullptr;
		Client* c = e->searchClient(id);
		if (c) {
			client->transfer(*c, money);
		}
		else {
			cout << "There is no client with this id" << endl;
		}
		FileManager::updateClients();
		Transaction t1(client->getId(), "Transfer to " + c->getName(), money, 
			Date::getCurrentDate());

		Transaction t2(c->getId(), "Recieve from " + client->getName(), money, 
			Date::getCurrentDate());

		Transaction::allTransactions.push_back(t1);
		FileManager::addTransaction(t1);

		Transaction::allTransactions.push_back(t2);
		FileManager::addTransaction(t2);

		break;
	}

	case 6:
		cout << "Balance: " << client->getBalance();
		//cout << "=================================";
		break;

	case 7:
		return false;

	case 8:
		viewTransaction(client);
		break;

	case 0:
		exit(0);

	default:
		system("cls");
		clientOptions(client);
	}


	backOrExit(client);

	return true;
}
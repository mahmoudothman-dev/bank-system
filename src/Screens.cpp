#include "Screens.h"

void Screens::bankName() {
	
		for (int i = 0; i < 4; i++) {
			cout << endl;

		}
		cout << "                   #########     #########    #########     #######     #       #    #########\n";
		cout << "                   #        #    #       #    #            #       #    ##     ##    #        \n";
		cout << "                   #        #    #       #    #            #       #    # #   # #    #        \n";
		cout << "                   #        #    #########    #            #       #    #  # #  #    #        \n";
		cout << "                   #        #    #    #       #########    #########    #   #   #    #########\n";
		cout << "                   #        #    #     #      #            #       #    #       #            #\n";
		cout << "                   #        #    #      #     #            #       #    #       #            #\n";
		cout << "                   #        #    #       #    #            #       #    #       #            #\n";
		cout << "                   #########     #        #   #########    #       #    #       #    #########\n";

		for (int i = 0; i < 4; i++) {
			cout << endl;
		}

		cout << "                                  ########      #######     #       #    #    #   \n";
		cout << "                                  #       #    #       #    ##      #    #   #    \n";
		cout << "                                  #       #    #       #    # #     #    #  #     \n";
		cout << "                                  #       #    #       #    #  #    #    # #      \n";
		cout << "                                  #########    #########    #   #   #    ##       \n";
		cout << "                                  #       #    #       #    #    #  #    # #      \n";
		cout << "                                  #       #    #       #    #     # #    #  #     \n";
		cout << "                                  #       #    #       #    #      ##    #   #    \n";
		cout << "                                  ########     #       #    #       #    #    #   \n";
	
}
void Screens::welcome() {
	
	
	for (int i = 0; i < 8; i++) {
		cout << endl;
	}
	cout << "                    #       #    #########    #             ########     #######     #       #    #########\n";
	cout << "                    #       #    #            #            #            #       #    ##     ##    #        \n";
	cout << "                    #       #    #            #            #            #       #    # #   # #    #        \n";
	cout << "                    #       #    #            #            #            #       #    #  # #  #    #        \n";
	cout << "                    #   #   #    #########    #            #            #       #    #   #   #    #########\n";
	cout << "                    #  # #  #    #            #            #            #       #    #       #    #        \n";
	cout << "                    # #   # #    #            #            #            #       #    #       #    #        \n";
	cout << "                    ##     ##    #            #            #            #       #    #       #    #        \n";
	cout << "                    #       #    #########    #########     ########     #######     #       #    #########\n";
	
}
void Screens::loginOptions() {
	cout << "(1) Client" << endl;
	cout << "(2) Employee" << endl;
	cout << "(3) Admin" << endl;
	cout << "(0) Exit\n" << endl;
}


int Screens::loginAs() {
	loginOptions();

	int num = Validation::validInt("Enter choice: ");
	

	while (true) {
		
		if (num == 1 || num == 2 || num == 3) {
			system("cls");
			return num;
		}
		else if (num == 0) {
			exit(0);
		}
		
		else {
			system("cls");
			
			loginAs();

		}

	}
	
}

void Screens::invalid(int c) {
	system("cls");
	cout << "Incorrect id or password\n" << endl;
	loginScreen(c);
}

void Screens::logout() {
	system("cls");
	loginScreen(loginAs());
}

void Screens::loginScreen(int c) {
	cout << "\t\t\t\t\t==================\n";
	cout << "\t\t\t\t\t    LOGIN PAGE    \n";
	cout << "\t\t\t\t\t==================\n\n";

	int id = Validation::validInt("Enter id: ");

	string password = Validation::enterPassword("Enter password: ");

	switch (c) {
	case 1: {
		Client* client = ClientManager::login(id, password);
		if (client) {
			while (ClientManager::clientOptions(client));
			logout();
		}
		else {
			invalid(c);
		}
		break;
	}
		

	case 2: {
		Employee* employee = EmployeeManager::login(id, password);
		if (employee) {
			while (EmployeeManager::employeeOptions(employee));
			logout();

		}
		else {
			invalid(c);
		}
		break;
	}
		

	case 3: {
		Admin* admin = AdminManager::login(id, password);
		if (admin) {
			while (AdminManager::adminOptions(admin));
			logout();

		}
		else {
			invalid(c);
		}
		break;


	}
	
	}


}


void Screens::runApp() {
	FileManager::getAllData();

	
	bankName();
	this_thread::sleep_for(chrono::seconds(3));
	system("cls");

	welcome();
	this_thread::sleep_for(chrono::seconds(3));
	system("cls");

	loginScreen(loginAs());
		
		

	

}
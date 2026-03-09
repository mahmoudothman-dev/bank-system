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
}


int Screens::loginAs() {
	int num;
	for (int i = 0; i < 4; i++) {
		cout << endl;
	}


	while (true) {
		cout << "Login as: ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3) {
			return num;
		}
		else if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice, please choose between 1, 2, or 3" << endl;

		}
		else {
			cout << "Invalid choice, please choose between 1, 2, or 3" << endl;

		}

	}
	
}



void Screens::loginScreen(int c) {
	
	int id;
	string password;
	
	while (true) {
		cout << "\t\t\t\t\t==================\n";
		cout << "\t\t\t\t\t    LOGIN PAGE    \n";
		cout << "\t\t\t\t\t==================\n";


		for (int i = 0; i < 4; i++) {
			cout << endl;
		}

		cout << "Enter your id: ";
		cin >> id;
		cout << "Enter your password: ";
		cin >> password;

		system("cls");
		

		if (c == 1) {
			
			while (true) {
				Client* c = ClientManager::login(id, password);
				if (c != nullptr) {
					bool result = ClientManager::clientOptions(c);
					if (!result) return;

					for (int i = 0; i < 2; i++) {
						cout << endl;
					}
					cout << "=========================================";
					for (int i = 0; i < 2; i++) {
						cout << endl;
					}
					
				}
				else if (c == nullptr) {
					break;
				}
				int num;
				cout << "(1) Options\t\t\t(0) Exit" << endl;
				cout << "Enter your choice: ";
				cin >> num;
				system("cls");
				if (num == 0) return;
				
			}
			
			
		}
		else if (c == 2) {
			while (true) {
				Employee* e = EmployeeManager::login(id, password);
				if (e != nullptr) {
					bool result = EmployeeManager::employeeOptions(e);
					if (!result) return;


					for (int i = 0; i < 2; i++) {
						cout << endl;
					}

					cout << "=========================================";
					for (int i = 0; i < 2; i++) {
						cout << endl;
					}
				}
				else if (e == nullptr) {
					break;
				}
				int num;
				cout << "(1) Options\t\t\t(0) Exit" << endl;
				cout << "Enter your choice: ";
				cin >> num;
				system("cls");
				if (num == 0) return;

			}
			
		}
		else if (c == 3) {
			while (true) {
				Admin* a = AdminManager::login(id, password);
				if (a != nullptr) {
					bool result = AdminManager::adminOptions(a);
					if (!result) return;

					
					for (int i = 0; i < 2; i++) {
						cout << endl;
					}

					cout << "=========================================";
					for (int i = 0; i < 2; i++) {
						cout << endl;
					}
				}
				else if (a == nullptr) {
					break;
				}
				int num;
				cout << "(1) Options\t\t\t(0) Exit" << endl;
				cout << "Enter your choice: ";
				cin >> num;
				system("cls");
				if (num == 0) return;


			}
			
		}
	}
	
}



void Screens::runApp() {
	
	bankName();
	this_thread::sleep_for(chrono::seconds(3));
	system("cls");
	welcome();
	this_thread::sleep_for(chrono::seconds(3));
	

	system("cls");
	loginOptions();
	int num = loginAs();
	system("cls");
	loginScreen(num);
		
		

	

}
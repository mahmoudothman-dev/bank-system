//#include "Screens.h"
//
//void bankName() {
//	for (int i = 0; i < 4; i++) {
//		cout << endl;
//
//	}
//	cout << "                   #########     #########    #########     #######     #       #    #########\n";
//	cout << "                   #        #    #       #    #            #       #    ##     ##    #        \n";
//	cout << "                   #        #    #       #    #            #       #    # #   # #    #        \n";
//	cout << "                   #        #    #########    #            #       #    #  # #  #    #        \n";   
//	cout << "                   #        #    #    #       #########    #########    #   #   #    #########\n";
//	cout << "                   #        #    #     #      #            #       #    #       #            #\n";
//	cout << "                   #        #    #      #     #            #       #    #       #            #\n";
//	cout << "                   #        #    #       #    #            #       #    #       #            #\n";
//	cout << "                   #########     #        #   #########    #       #    #       #    #########\n";
//
//	for (int i = 0; i < 4; i++) {
//		cout << endl;
//	}
//
//	cout << "                                  ########      #######     #       #    #    #   \n";
//	cout << "                                  #       #    #       #    ##      #    #   #    \n";
//	cout << "                                  #       #    #       #    # #     #    #  #     \n";
//	cout << "                                  #       #    #       #    #  #    #    # #      \n";
//	cout << "                                  #########    #########    #   #   #    ##       \n";
//	cout << "                                  #       #    #       #    #    #  #    # #      \n";
//	cout << "                                  #       #    #       #    #     # #    #  #     \n";
//	cout << "                                  #       #    #       #    #      ##    #   #    \n";
//	cout << "                                  ########     #       #    #       #    #    #   \n";
//}
//
//void welcome() {
//	for (int i = 0; i < 8; i++) {
//		cout << endl;
//	}
//	cout << "                    #       #    #########    #             ########     #######     #       #    #########\n";
//	cout << "                    #       #    #            #            #            #       #    ##     ##    #        \n";
//	cout << "                    #       #    #            #            #            #       #    # #   # #    #        \n";
//	cout << "                    #       #    #            #            #            #       #    #  # #  #    #        \n";
//	cout << "                    #   #   #    #########    #            #            #       #    #   #   #    #########\n";
//	cout << "                    #  # #  #    #            #            #            #       #    #       #    #        \n";
//	cout << "                    # #   # #    #            #            #            #       #    #       #    #        \n";
//	cout << "                    ##     ##    #            #            #            #       #    #       #    #        \n";
//	cout << "                    #       #    #########    #########     ########     #######     #       #    #########\n";
//}
//
//void loginOptions() {
//	cout << "(1) Client" << endl;
//	cout << "(2) Employee" << endl;
//	cout << "(3) Admin" << endl;
//}
//
//int loginAs() {
//	int num;
//	for (int i = 0; i < 4; i++) {
//		cout << endl;
//	}
//
//	
//	while (true) {
//		cout << "Login as: ";
//		cin >> num;
//		if (num == 1 || num == 2 || num == 3) {
//			return num;
//		}
//		else {
//			cout << "Invalid choice, please choose between 1, 2, or 3";
//		}
//
//	}
//
//}
//
//void loginScreen(int num) {
//	if (num == 1) {
//		AdminManager::login()
//	}
//}
//
//void runApp() {
//	bankName();
//	this_thread::sleep_for(chrono::seconds(3));
//	system("cls");
//	welcome();
//	this_thread::sleep_for(chrono::seconds(3));
//	system("cls");
//	loginOptions();
//	int num = loginAs();
//	loginScreen(num);
//}
//
//int main() {
//	runApp();
//
//}

#include "Screens.h"
#include "FileManager.h"

int main() {
	FileManager::getAllClients();
	FileManager::getAllEmployees();
	FileManager::getAllAdmins();

	

	Screens::runApp();
	FileManager::removeAllClients();
	FileManager::removeAllEmployees();
	FileManager::removeAllAdmins();

	for (int i = 0; i < Client::allClients.size(); i++) {
		FileManager::addClient(Client::allClients[i]);
	}
	for (int i = 0; i < Employee::allEmployees.size(); i++) {
		FileManager::addEmployee(Employee::allEmployees[i]);
	}
	for (int i = 0; i < Admin::allAdmins.size(); i++) {
		FileManager::addAdmin(Admin::allAdmins[i]);
	}
}

//#include <iostream>
//using namespace std;
//
//int main() {
//	
//
//	while (true) {
//		int x;
//		cout << "Enter your number: ";
//		cin >> x;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "try again" << endl;
//		}
//		else {
//			cout << "good number" << endl;
//		}
//	}
//
//	
//}
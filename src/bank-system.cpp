#include "Screens.h"


int main() {
	Screens::runApp();
}


//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//string getPassword() {
//	string password;
//	char ch;
//
//	while (true) {
//		ch = _getch();
//		if (ch == 13) break;
//		else if (ch == 8) {
//			if (!password.empty()) {
//				password.pop_back();
//				cout << "\b \b";
//			}
//		}
//		else {
//			password += ch;
//			cout << '*';
//		}
//		
//	}
//
//	return password;
//}
//
//int main() {
//	cout << "Password: ";
//	string password = getPassword();
//	cout << password;
//
//}
//

#include "Client.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Client c;
	Client b(0, "mahmoud", "12sQ$345u", 2000);
	cout << c.getBalance() << endl;
	cout << c.getName() << endl;
	cout << c.getPassword() << endl;

	cout << b.getBalance() << endl;
	cout << b.getName() << endl;
	cout << b.getPassword() << endl;
	b.transfer(c, 500);
	cout << b.getBalance() << endl;
	cout << c.getBalance() << endl;

}
#include "Client.h"
#include "Validation.h"

vector<Client> Client::allClients;

Client::Client() : Person() {
	balance = 1500;
};
Client::Client(int id, string name, string password,double balance) 
	: Person(id,name,password) {
	setBalance( balance);
}

void Client:: setBalance(double balance) {
	if (Validation::validBalance(balance)) {
		this->balance = balance;
	}
}
//depo
void Client:: deposit(double amount) {
	this->balance += amount;
	cout << "Deposit successful" << endl;
	cout << "Balance: " << balance << " EGP" << endl;

}

//with
void Client::withdraw(double amount) {
	if (balance >= amount) {
		this->balance -= amount;

		cout << "Withdraw successful" << endl;
	}
	else {
		cout << "Your balance is insufficient for this transaction" << endl;
		
	}
	cout << "Balance: " << balance << " EGP" << endl;

}

//transferto
void Client::transfer(Client& another, double amount) {
	if (balance >= amount) {
		another.balance += amount;
		balance -= amount;
		cout << "Transaction was successful" << endl;
	}
	else {
		cout << "Your balance is insufficient for this transaction" << endl;
	}
	cout << "Balance: " << balance << " EGP" << endl;
}

double Client::getBalance() {
	return this->balance;
}
//meth
void Client::display() {
	Person::display();
	cout << "Balance: " << balance << " EGP" << endl;
	
	
}


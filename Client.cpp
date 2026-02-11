#include "Client.h"
#include "Validation.h"


Client::Client() : Person() {
	balance = 1500;
};
Client::Client(int id, string name, string password,double balance) 
	: Person(id,name,password) {
	setbalance( balance);
}

void Client:: setbalance(double balance) {
	if (Validation::validBalance(balance)) {
		this->balance = balance;
	}
}
//depo
void Client:: deposit(double amount) {
	this->balance += amount;
}

//with
void Client::withdraw(double amount) {
	if (balance >= amount) {
		this->balance -= amount;
		cout << "You withdrew " << amount << " successfully" << endl;
	}
	else {
		cout << "Your balance is insufficient for this transaction" << endl;
		
	}
	
}

//transferto
void Client::transfer(Client& another, double amount) {
	if (balance >= amount) {
		another.deposit(amount);
		balance -= amount;
		cout << "Transaction was successful" << endl;
	}
	else {
		cout << "Your balance is insufficient for this transaction" << endl;
	}
}


//gett
string Client:: getName() {
	return this->name;
}
string Client::getPassword() {
	return this->password;
}

double Client::getBalance() {
	return this->balance;
}
//meth
void Client::display() {
	Person::display();
	cout << "Balance: " << balance << "\n";
	
}


#include "Client.h"
#include "Validation.h"
Client::Client():Person() {
	setbalance(1500);
};
Client::Client(int id, string name, string password,double balance):Person(id,name,password) {
	setbalance( balance);
}

void Client:: setbalance(double balance) {
	if (Validation::validBalance(balance)) {
		this->balance = balance;
	}
}
//depo
double Client:: deposit(double amount) {
	this->balance += amount;
	return this->balance;
}

//with
double Client::withdraw(double amount) {
	this->balance -= amount;
	return this->balance;
}

//transferto
bool Client::transfer(Client& client, double amount) {
	if (withdraw(amount)) {
		client.deposit(amount);
		return true;
	}
	return false;
}


//gett
string Client:: getname() {
	return this->name;
}
string Client::getpassword() {
	return this->password;
}

double Client::getbalance() {
	return this->balance;
}
//meth
void Client::display() {
	Person::display();
	cout << "BALANCE =" << balance << "\n";
	cout << "-------------------------------------" << "\n";
}


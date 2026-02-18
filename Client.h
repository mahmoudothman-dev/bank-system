#pragma once
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;


class Client : public Person {
private:
	double balance;

public:
	Client();
		
	
	Client(int id, string name, string password, double balance);

	void setBalance(double balance);
	//depo
	void deposit(double amount);


	//with
	void withdraw(double amount);

	//transferto
	void transfer(Client & client, double amount);

	//gett
	string getName();
			
	string getPassword();
			
	double getBalance();
			
	void display();

};


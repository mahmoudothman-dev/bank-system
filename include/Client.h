#pragma once
#include "Person.h"

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

	
	double getBalance();
			
	void display();
	
};


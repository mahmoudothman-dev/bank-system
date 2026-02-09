#pragma once
#include "Person.h"
using namespace std;
class Client :public Person {
private:
	double balance;
public:
	    Client() :Person();
		
	
	    Client(int id, string name, string password, double balance) :Person(id, name, password);

		void setbalance(double balance);
		//depo
		double deposit(double amount);


		//with
		double withdraw(double amount);

		//transferto
		bool transfer(Client & client, double amount);

		//gett
		string getname();
			
		string getpassword();
			
		double getbalance();
			
		void display();
			
			
			
		

};






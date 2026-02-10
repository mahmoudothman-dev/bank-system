#include <iostream>
#include <string>
using namespace std;

class Person {

protected://attr
	int id;
	string name;
	string password;
public:
	//cons
	Person() {
		this->id = 0;
	}
	Person(int id, string name, string password) {
		this->id = id;
		this->name = name;
		this->password = password;
	}


	//sett
	void setid(int id){
		this->id = id;
	}
	void setname(string name) {
		this->name = name;
	}
	void setpassword(string password) {
		this->password = password;
	}

	//gett
	int getid() {
		return this->id;
	}
	string getname() {
		return this->name;
	}
	string getpassword() {
		return this->password;
	}

	//meth
	void display() {
		cout << "NAME = " << name << "\n";
		cout << "PASSWORD = " << password << "\n";
		cout << "ID = " << id << "\n";
	}
};



class Client :public Person {

private://attr
	double balance;

public://cons
	Client() {
		this->balance = 0;
	}
	Client(int id, string name, string password, double balance) {
		this->id = id;
		this->name = name;
		this->password = password;
		this->balance = balance;
	}
	//sett
	void setbalance(double balance) {
		this->balance = balance;
	}
	//gett
	double getbalance() {
		return this->balance;
	}




	//depo
	double deposit(double amount) {
		this->balance += amount;
		return this->balance;
	}

	//with
	double withdraw(double amount) {
		this->balance -= amount;
		return this->balance;
	}

	//transferto
	bool transfer(Client &client,double amount ) {
		if (withdraw(amount)) {
			client.deposit(amount);
			return true;
		}
		return false;
	}


	//meth
	void display() {
		Person::display();
		cout << "BALANCE =" << balance << "\n";
		cout << "-------------------------------------" << "\n";
	}

	

};






int main() {


	Client a,b,c;


	a.setname("ali");
	a.setpassword("1445454798");
	a.setid(777);
	a.setbalance(17000);
	
	b.setname("ahmed");
	b.setpassword("454545454");
	b.setid(555);
	b.setbalance(18000);






	//a.deposit(3000);
	//b.withdraw(3000);


	a.transfer(b, 3000);




	a.display();
	b.display();



	




	return  0;
}
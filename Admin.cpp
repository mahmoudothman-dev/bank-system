#include "Admin.h"
#include "Validation.h"
#include <iostream>
using namespace std;


//def const
Admin::Admin() :Person() {
	this->salary = 5000;
}

//para const
Admin::Admin(int id, string name, string password, double salary) :Person(id, name, password) {
	set_salary(salary);
}

//setter
void Admin::set_salary(double salary) {
	if (Validation::validSalary(salary)) {
		this->salary = salary;
	}

	else {
		cout << "Invalid ! Minimum Salary is 5000 ";
		this->salary = 5000;
	}
}
//getter
string Admin::getName() {
	return this->name;
}

string Admin::getPassword() {
	return this->password;
}


double Admin::get_salary() {
	return salary;
}
//Display
void Admin::display() {
	Person::display();
	cout << "Salary: " << salary << endl;
}

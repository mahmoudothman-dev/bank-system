#include "Person.h"
#include "Validation.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() {
	this->id = 0;
	
}

Person::Person(int id, string name, string password) {
	this->id = id;
	setName(name);
	setPassword(password);
}

void Person::setName(string name) {
	if (Validation::validName(name)) {
		this->name = name;
	}
}
void Person::setPassword(string password) {
	if (Validation::validPassword(password)) {
		this->password = password;
	}
}


void Person::display() {
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	
}



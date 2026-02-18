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

void Person::setId(int id) {
	this->id = id;
}

void Person::setName(string name) {
	if (Validation::validName(name)) {
		name[0] = toupper(name[0]);
		for (int i = 0; i < name.size(); i++) {
			if (name[i] == ' ') {
				name[i + 1] = toupper(name[i + 1]);
			}
		}
		this->name = name;
	}
}
void Person::setPassword(string password) {
	if (Validation::validPassword(password)) {
		this->password = password;
	}
}

int Person::getId() {
	return id;
}


void Person::display() {
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	
}



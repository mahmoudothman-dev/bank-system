#include "Person.h"
#include "Validation.h"

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

bool Person::setName(string name) {
	if (Validation::validName(name)) {
		name[0] = toupper(name[0]);
		for (int i = 0; i < name.size(); i++) {
			if (name[i] == ' ') {
				name[i + 1] = toupper(name[i + 1]);
			}
		}
		this->name = name;
		
		return true;
	}
	return false;
}
bool Person::setPassword(string password) {
	if (Validation::validPassword(password)) {
		this->password = password;
		return true;
	}
	return false;
}

int Person::getId() {
	return id;
}

string Person::getName() {
	return name;
}

string Person::getPassword() {
	return password;
}


void Person::display() {
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Password: " << password << endl;
}



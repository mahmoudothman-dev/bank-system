#pragma once
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;


class Employee : public Person {
private:
	double salary;

public:
	Employee();

	Employee(int id, string name, string password, double salary);

	void setSalary(double salary);

	string getName();

	string getPassword();

	double getSalary();

	void display();

};


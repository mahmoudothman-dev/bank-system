#pragma once
#include<iostream>
#include<string>
#include "Person.h"
using namespace std;

class Admin :public Person {

private:
	//Att
	double salary;
public:
	//Def const
	Admin();

	Admin(int id, string name, string password, double salary);
    
	//Setters
	void set_salary(double salary);
	
    //Getters
	double get_salary();
	string getName();
	string getPassword();
	//Display

	void display();

};



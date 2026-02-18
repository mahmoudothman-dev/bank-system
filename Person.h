#pragma once
#include <iostream>
#include <string>

class Person {
protected:
	int id;
	std::string name, password;

public:
	Person();
	
	Person(int id, std::string name, std::string password);

	void setId(int id);
	void setName(std::string name);
	void setPassword(std::string password);
	int getId();
	virtual std::string getName() = 0;
	virtual std::string getPassword() = 0;
	virtual void display();

	
};

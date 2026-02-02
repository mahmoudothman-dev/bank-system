#include "Validation.h"
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool Validation::validName(string name) {
	if (name.size() < 5) {
		cout << "Your name can't be less than 5 letters" << endl;
		return false;
	}
	else if (name.size() > 20) {
		cout << "Your name can't be more than 20 letters" << endl;
		return false;
	}
	bool space = false;
	for (char c : name) {
		if (isalpha(c)) {
			space = false;
		}
		else if (c == ' ') {
			if (space) {
				cout << "You should not write spaces in your name" << endl;
				return false;
			}
			space = true;
		}
		else {
			cout << "Your name should not include symbos or numbers" << endl;
			return false;
		}
	}
	return true;
}

bool Validation::validPassword(string password) {
	if (password.size() < 8) {
		cout << "Passowrd should not be less than 8 characters" << endl;
		return false;
	}
	else if (password.size() > 20) {
		cout << "Password should not be more than 20 characters" << endl;
		return false;
	}

	bool upper = false;
	bool lower = false;
	bool digit = false;
	for (char c : password) {
		if (c == ' ') {
			cout << "Spaces are not allowed in password" << endl;
			return false;
		}
		if (isupper(c)) upper = true;
		if (islower(c)) lower = true;
		if (isdigit(c)) digit = true;

	}
	if (!upper) {
		cout << "Password should have at least one uppercase" << endl;
		return false;
	}
	if (!lower) {
		cout << "Password should have at least one lowercase" << endl;
		return false;
	}
	if (!digit) {
		cout << "Password should have has at least one digit" << endl;
		return false;
	}
	return true;
}

bool validBalance(double balance) {
	if (balance < 1500) {
		cout << "Minumum balance should be 1500";
		return false;
	}
	return true;
}

bool validSalary(double salary) {
	if (salary < 5000) {
		cout << "Minimum salary should be 5000";
		return false;
	}
	return true;
}
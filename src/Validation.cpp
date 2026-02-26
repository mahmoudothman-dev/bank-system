#include "Validation.h"
#include <cctype>
#include <algorithm>

bool Validation::validName(string name) {
	if (name.size() < 3 || name.size() > 20) {
		cout << "Your name should be between 3 and 20 letters" << endl;
		return false;
	}
	
	else if (name.front() == ' ') {
		cout << "Your name should not begin with space" << endl;
		return false;
	}
	else if (name.back() == ' ') {
		cout << "Your name should not end with space" << endl;
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
			cout << "Your name should not include symbols or numbers" << endl;
			return false;
		}
	}

	
	
	
	return true;
}

bool Validation::validPassword(string password) {
	if (password.size() < 8 || password.size() > 20) {
		cout << "Your password should be between 8 and 20 digits" << endl;
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

bool Validation::validBalance(double balance) {
	if (balance < 1500) {
		cout << "Minimum balance should be 1500" << endl;
		return false;
	}
	return true;
}

bool Validation::validSalary(double salary) {
	if (salary < 5000) {
		cout << "Minimum salary should be 5000" << endl;
		return false;
	}
	return true;
}
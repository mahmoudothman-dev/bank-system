#include <Validation.h>
#include <string>
#include <cctype>
using namespace std;

bool Validation::isAlphabatic(const string& name) {
	for (char c in name) {
		if (!isalpha(c) && c != ' ') {
			return false;
		}
	}
	return true;
}

bool Validation::validName(const string& name) {
	return isAlphabatic(name) && name.size() >= 5 && name.size() <= 20;
}

bool Validation::validPassword(const string& password) {
	return password.size() >= 8 && password.size <= 20;
}

bool Validation::validBalance(const double balance) {
	return balance >= 1500;
}

bool Validatoin::validSalary(const double salary) {
	return salary >= 5000;
}
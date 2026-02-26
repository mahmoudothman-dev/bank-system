#include "Parser.h"

vector<string> Parser::split(string line) {
	vector<string> result;
	string part;

	stringstream ss(line);
	while (getline(ss, part, ',')) {
		result.push_back(part);
		
	}
	return result;
}

Client Parser::parseToClient(string line) {
	vector<string> data = split(line);
	return Client(stoi(data[0]), data[1], data[2], stod(data[3]));

}

Employee Parser::parseToEmployee(string line) {
	vector<string> data = split(line);
	return Employee(stoi(data[0]), data[1], data[2], stod(data[3]));

}

Admin Parser::parseToAdmin(string line) {
	vector<string> data = split(line);
	return Admin(stoi(data[0]), data[1], data[2], stod(data[3]));

}
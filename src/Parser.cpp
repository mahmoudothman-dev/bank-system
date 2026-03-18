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

Transaction Parser::parseToTransaction(string line) {
	vector<string> data = split(line);
	Date date(stoi(data[3]), stoi(data[4]), stoi(data[5]), 
		stoi(data[6]), stoi(data[7]), stoi(data[8]));

	return Transaction(stoi(data[0]), data[1], stod(data[2]), date);

}
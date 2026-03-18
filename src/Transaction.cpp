#include "Transaction.h"

Transaction::Transaction() {
	id = 0;
	amount = 0;
}

Transaction::Transaction(int id, string type, double amount, Date date) 
	: id(id), type(type), amount(amount), date(date) { }


vector<Transaction> Transaction::allTransactions;

int Transaction::getId() {
	return id;
}
string Transaction::getType() {
	return type;
}
double Transaction::getAmount() {
	return amount;
}
Date Transaction::getDate() {
	return date;
}
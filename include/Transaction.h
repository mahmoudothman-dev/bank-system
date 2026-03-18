#pragma once
#include "Date.h"
#include <vector>


class Transaction {
	int id;
	string type;
	double amount;
	Date date;

public:
	static vector<Transaction> allTransactions;

	Transaction();
	Transaction(int id, string type, double amount, Date date);

	int getId();
	string getType();
	double getAmount();
	Date getDate();
};

#pragma once
#include "Employee.h"
#include "Validation.h"
#include "FileManager.h"
#include "Transaction.h"

class ClientManager {
public:

	static void printClientMenu();

	static void updatePassword(Person* person);

	static Client* login(int id, string password);

	static bool clientOptions(Client* client);

	static void backOrExit(Client* client);

	static void viewTransaction(Client* client);

};


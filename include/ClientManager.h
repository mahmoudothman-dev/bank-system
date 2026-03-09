#pragma once
#include "Employee.h"

class ClientManager {
public:

	static void printClientMenu();

	static void updatePassword(Person* person);

	static Client* login(int id, string password);

	static bool clientOptions(Client* client);

};


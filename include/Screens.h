#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
using namespace std;

class Screens {
public:

	static void bankName();

	static void welcome();

	static void loginOptions();

	static int loginAs();

	

	static void loginScreen(int c);

	static void runApp();

};

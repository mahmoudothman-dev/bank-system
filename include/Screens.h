#pragma once
#include <chrono>
#include <thread>
#include "AdminManager.h"
#include "Validation.h"
#include "FileManager.h"


class Screens {
public:

	static void bankName();

	static void welcome();

	static void loginOptions();

	static int loginAs();

	static void invalid(int c);

	static void logout();

	static void loginScreen(int c);

	static void runApp();

};

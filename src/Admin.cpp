#include "Admin.h"
#include "FilesHelper.h"
#include "Validation.h"


vector<Admin> Admin::allAdmins;

Admin::Admin() : Employee() {}

//para const
Admin::Admin(int id, string name, string password, double salary)
	:Employee(id, name, password, salary) {
}

//Add Employee

void Admin::addEmployee(Employee& e) {
	Employee::allEmployees.push_back(e);

}
//Search
Employee* Admin::searchEmployee(int id) {
	for (int i = 0; i < Employee::allEmployees.size(); i++) {
		if (Employee::allEmployees[i].getId() == id) {
			return &Employee::allEmployees[i];
		}
	}
	return nullptr;
}

//List employee
void Admin::listEmployee() {
	for (int i = 0; i < Employee::allEmployees.size(); i++) {
		Employee::allEmployees[i].display();
	}
}

//Edit Employee
void Admin::editEmployee(int id , string name , string password , double salary) {
	for (int i = 0; i < Employee::allEmployees.size(); i++) {
		if (Employee::allEmployees[i].getId() == id) {
			Employee::allEmployees[i].setName(name);
			Employee::allEmployees[i].setPassword(password);
			Employee::allEmployees[i].setSalary(salary);
		}
	}
}

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
	cout << "Total employees: " << Employee::allEmployees.size() << endl << endl;

	cout << fixed << setprecision(2);

	cout << left << setw(6) << "ID"
		<< setw(30) << "Name"
		<< setw(30) << "Password"
		<< setw(10) << "Salary" << endl;

	cout << string(76, '-') << endl;


	for (auto employee : Employee::allEmployees) {
		cout << left << setw(6) << employee.getId()
			<< setw(30) << employee.getName()
			<< setw(30) << employee.getPassword()
			<< setw(10) << employee.getSalary() << " EGP" << endl << endl;
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

void Admin::deleteEmployee(int id) {

	for (int i = 0; i < Employee::allEmployees.size(); i++) {


		if (id == Employee::allEmployees[i].getId()) {
			for (int j = i; j < Employee::allEmployees.size() - 1; j++) {
				Employee::allEmployees[j] = Employee::allEmployees[j + 1];
			}
			Employee::allEmployees.pop_back();
			
			return;
		}

	} 
}

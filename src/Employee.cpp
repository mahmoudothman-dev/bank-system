#include "Employee.h"
#include "Validation.h"


Employee::Employee() : Person() {
	salary = 5000;
}
Employee::Employee(int id, string name, string password, double salary)
	: Person(id, name, password) {
	setSalary(salary);
}

void Employee::setSalary(double salary) {
	if (Validation::validSalary(salary)) {
		this->salary = salary;
	}
}

double Employee::getSalary() {
	return salary;
}

void Employee::display() {
	Person::display();
	cout << "Salary: " << salary << endl;
}
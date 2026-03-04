#include "Admin.h"
#include "FilesHelper.h"
#include "Client.h"
#include "Employee.h"
#include <vector>
#include "Validation.h"
using namespace std;
//def const
Admin::Admin() : Employee() {}

	//para const
	Admin::Admin(int id, string name, string password, double salary)
		:Employee(id, name, password, salary) {
	}

	//Add Employee

	void Admin::addEmployee(Employee & e) {
		if(Validation::validName(e.getName())&&
			Validation::validPassword(e.getPassword())&&
			Validation::validSalary(e.getSalary()))
		{

		ofstream file("data/employees.txt", ios::app);
		file << e.getId() << ',' << e.getName() << ',' << e.getPassword() << ',' << e.getSalary()<<endl ;
		file.close();
		cout << "Employee is added Successfully" << endl;
	}
		else {
			cout << "Invalid porcess" << endl;
		}
	
	}
	//Search
	Employee* Admin::searchEmployee(int id) {
		vector<Employee> Employees = FilesHelper::getEmployees();
		if (Employees.empty()) {
			return nullptr;
		}

		for (int i = 0; i < Employees.size(); i++) {
			if (Employees[i].getId() == id) {
				Employees[i].display();
				return new Employee(Employees[i]);
			}

		}
		cout << "Employee Not Found" << endl;
		return nullptr;
	}

	//List employee
	void Admin::listEmployee() {
		vector<Employee> Employees = FilesHelper::getEmployees();
		cout << "--- Employee List ---" << endl;
		if (Employees.empty()) {
			cout << "NO Employee Found in the system." << endl;
		}
		for (int i = 0; i < Employees.size(); i++) {
			Employees[i].display();
			cout << "\n__________________" << endl;
		}
	}

	//Edit Employee
	void Admin::editEmployee(int id , string name , string password , double salary) {
		vector<Employee> Employees = FilesHelper::getEmployees();
		bool found = false;
		if (Validation::validName(name) &&
			Validation::validPassword(password) &&
			Validation::validSalary(salary))
		{
			for (int i = 0; i < Employees.size(); i++) {
				if (Employees[i].getId() == id) {
					Employees[i].setName(name);
					Employees[i].setPassword(password);
					Employees[i].setSalary(salary);
					found = true;
					break;
				}
			}
		}
		else {
			cout << "Invalid process" << endl;
			return;
		}
		
		if (found) {
			//Remove old version
			ofstream file("Data/employees.txt", ios::out);
			file.close();


			
			for (int i = 0; i < Employees.size(); i++) {
				FilesHelper::saveEmployee("Data/employees.txt", "Data/lastEmployeeId.txt", Employees[i]);
			}
			cout << "Employee is updated Successfully" << endl;
		}
			else {
			cout << "Not Found" << endl;
			}

	}

#pragma once
#include "datasourceinterface.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Client.h"
#include "admin.h"
#include "FilesHelper.h"
class filemanager :public datasourceinterface
{
private:
    const string clientsFile = "clients.txt";
    const string employeesFile = "employees.txt";
    const string adminsFile = "admins.txt";

    // دالة مساعدة لقراءة ملف وإرجاع كل الأسطر
    vector<string> readFile(string fileName) {
        vector<string> data;
        ifstream file(fileName);
        string line;

        while (getline(file, line)) {
            if (!line.empty())
                data.push_back(line);
        }

        file.close();
        return data;
    }

    // دالة مساعدة لمسح محتوى ملف
    void clearFile(string fileName) {
        ofstream file(fileName, ios::trunc);
        file.close();
    }

public:

    // add client
    void addClient(Client object)  {
        ofstream file("data/clients.txt", ios::app);
        file << object.getId() << ',' << object.getName() << ',' << object.getPassword() << ',' << object.getBalance() ;
        file.close();
    }

    // add employee
    void addEmployee(Employee object )  {
        ofstream file("data/employees.txt", ios::app);
        file << object.getId() << ',' << object.getName() << ',' << object.getPassword() << ',' << object.getSalary() ;
        file.close();
    }

    // add admin
    void addAdmin(Admin object)  {
        ofstream file("data/admins.txt", ios::app);
        file << object.getId()<<','<<object.getName()<<','<<object.getPassword()<<','<<object.getSalary();
        file.close();
    }

    // استرجاع كل العملاء
    static vector<Client> getAllClients() {
        vector<Client>v = FilesHelper::getClients();
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].display() << endl;
        }
    }

    // استرجاع كل الموظفين
     vector<string> getAllEmployees()  {
         vector<Employee>v = FilesHelper::getEmployees();

    }

    // استرجاع كل الأدمن
    vector<string> getAllAdmins()  {
        vector<Admin>v = FilesHelper::getAdmins();

    }

    // return all client
    void removeAllClients()  {
        clearFile(clientsFile);
    }

    // return all employee
    void removeAllEmployees()  {
        clearFile(employeesFile);
    }
    // return all admin
    void removeAllAdmins()  {
        clearFile(adminsFile);
    }
};


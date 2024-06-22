#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Employee {
public:
    Employee(const std::string& name, int id, const std::string& department, double salary)
        : name(name), id(id), department(department), salary(salary) {}

    std::string getName() const { return name; }
    int getId() const { return id; }
    std::string getDepartment() const { return department; }
    double getSalary() const { return salary; }

private:
    std::string name;
    int id;
    std::string department;
    double salary;
};

std::vector<Employee> parseJSON(const std::string &filename);
std::vector<Employee> parseXML(const std::string &filename);
double calculateAverageSalary(const std::vector<Employee> &employees);
Employee findHighestPaidEmployee(const std::vector<Employee> &employees);
void sortEmployeesById(std::vector<Employee> &employees);
void displayResults(std::vector<Employee> &employees);

#endif // EMPLOYEE_H
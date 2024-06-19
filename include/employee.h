#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

class Employee {
public:
    std::string name;
    int id;
    std::string department;
    double salary;

    Employee(std::string n, int i, std::string d, double s);
};

double calculateAverageSalary(const std::vector<Employee>& employees);
Employee findHighestPaidEmployee(const std::vector<Employee>& employees);
std::vector<Employee> sortEmployeesById(std::vector<Employee>& employees);

#endif

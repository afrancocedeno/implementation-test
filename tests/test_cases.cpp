#include <iostream>
#include <cassert>
#include <vector>
#include "../include/employee.h"


void displayResults(std::vector<Employee>& employees) {
    for (const auto& employee : employees) {
        std::cout << "Name: " << employee.getName() << ", "
                  << "ID: " << employee.getId() << ", "
                  << "Department: " << employee.getDepartment() << ", "
                  << "Salary: " << employee.getSalary() << std::endl;
    }
}

// Sample test case for Employee class
void testEmployee() {
    Employee emp("John Doe", 101, "HR", 50000);

    assert(emp.getName() == "John Doe");
    assert(emp.getId() == 101);
    assert(emp.getDepartment() == "HR");
    assert(emp.getSalary() == 50000);

    std::cout << "All Employee tests passed!" << std::endl;
}

// Additional test case for displayResults
void testDisplayResults() {
    std::vector<Employee> employees = {
        Employee("John Doe", 101, "HR", 50000),
        Employee("Jane Smith", 102, "Engineering", 60000)
    };

    displayResults(employees);
    std::cout << "displayResults test passed!" << std::endl;
}

int main() {
    testEmployee();
    testDisplayResults();
    return 0;
}

#include <cassert>
#include "../include/employee.h"

// Sample test case for Employee class
void testEmployee()
{
    Employee emp("John Doe", 101, "HR", 50000);

    assert(emp.getName() == "John Doe");
    assert(emp.getId() == 101);
    assert(emp.getDepartment() == "HR");
    assert(emp.getSalary() == 50000);

    std::cout << "employee passed!" << std::endl;
}

void testDisplayResults()
{
    std::vector<Employee> employees = {
        Employee("John Doe", 101, "HR", 50000),
        Employee("Jane Smith", 102, "Engineering", 60000)};

    displayResults(employees);
    std::cout << "displayResults test passed!" << std::endl;
}
/*

void test_negative_salaries()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "Engineering", -50000},
        {"Jane Smith", 2, "HR", 60000}};
    displayResults(employees);
}

void test_empty_json()
{
    std::vector<Employee> employees = parseJSON("test_data/empty.json");
    assert(employees.empty());
}
 */
/*
void test_empty_xml()
{
    std::vector<Employee> employees = parseXML("test_data/empty.xml");
    assert(employees.empty());
}

void test_empty_name()
{
    std::vector<Employee> employees = {
        {"", 1, "Engineering", 50000},
        {"Jane Smith", 2, "HR", 60000}};
    displayResults(employees);
}

void test_empty_department()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "", 50000},
        {"Jane Smith", 2, "HR", 60000}};
    displayResults(employees);
}

void test_empty_id()
{
    std::vector<Employee> employees = {
        {"John Doe", 0, "Engineering", 50000},
        {"Jane Smith", 2, "HR", 60000}};
    displayResults(employees);
}

void test_empty_salary()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "Engineering", 0},
        {"Jane Smith", 2, "HR", 60000}};
    displayResults(employees);
}

void test_empty_employees_json()
{
    std::vector<Employee> employees = parseJSON("test_data/empty_employees.json");
    assert(employees.empty());
}

void test_empty_employees_xml()
{
    std::vector<Employee> employees = parseXML("test_data/empty_employees.xml");
    assert(employees.empty());
}

void test_empty_employee()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "Engineering", 50000},
        {"", 0, "", 0},
        {"Jane Smith", 2, "HR", 60000}};
    displayResults(employees);
}

void test_empty_vector()
{
    std::vector<Employee> employees;
    displayResults(employees);
}

void test_empty_vector_of_employees_with_negative_salary()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "Engineering", -50000},
        {"Jane Smith", 2, "HR", -60000}};
    displayResults(employees);
}

void test_different_input_json_file()
{
    std::vector<Employee> employees = parseJSON("test_data/different_input.json");
    displayResults(employees);
}

void test_different_input_xml_file()
{
    std::vector<Employee> employees = parseXML("test_data/different_input.xml");
    displayResults(employees);
}
 */
void run_all_tests()
{
    testEmployee();
    testDisplayResults();

    /*
    test_negative_salaries();
    test_empty_json();
        test_empty_xml();
        test_empty_name();
        test_empty_department();
        test_empty_id();
        test_empty_salary();
        test_empty_employees_json();
        test_empty_employees_xml();
        test_empty_employee();
        test_empty_vector();
        test_empty_vector_of_employees_with_negative_salary();
        test_different_input_json_file();
        test_different_input_xml_file(); */
}

int main() {
    run_all_tests();
    std::cout << "All tests passed" << std::endl;
    // Your existing main function logic
    return 0;
}
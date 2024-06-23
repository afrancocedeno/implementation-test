#include "../include/employee.h"

void test_employee()
{
    Employee emp("John Doe", 101, "HR", 50000);

    assert(emp.getName() == "John Doe");
    assert(emp.getId() == 101);
    assert(emp.getDepartment() == "HR");
    assert(emp.getSalary() == 50000);

    std::cout << "employee passed!" << std::endl;
}

void test_display_results()
{
    std::vector<Employee> employees = {
        Employee("John Doe", 101, "HR", 50000),
        Employee("Jane Smith", 102, "Engineering", 60000)};

    auto first_employee = employees[0];
    auto second_employee = employees[1];

    assert(employees.size() == 2);
    assert(first_employee.getId() == 101);
    assert(second_employee.getId() == 102);
    assert(first_employee.getName() == "John Doe");
    assert(second_employee.getName() == "Jane Smith");
    assert(first_employee.getDepartment() == "HR");
    assert(second_employee.getDepartment() == "Engineering");
    assert(first_employee.getSalary() == 50000);
    assert(second_employee.getSalary() == 60000);

    std::cout << "test display results test passed!" << std::endl;
}

void test_negative_salaries()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "Engineering", -50000},
        {"Jane Smith", 2, "HR", 60000}};

    auto max_salary = std::max_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
                                       { return a.getSalary() < b.getSalary(); })
                          ->getSalary();
    auto min_salary = std::min_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
                                       { return a.getSalary() < b.getSalary(); })
                          ->getSalary();

    assert(max_salary == 60000);
    assert(min_salary == -50000);
    std::cout << "negative salaries test passed!" << std::endl;
}

void test_empty_json()
{
    std::vector<Employee> employees = parseJSON("tests/data/json/empty_format1.json");
    assert(employees.empty());
    employees = parseJSON("tests/data/json/empty_format2.json");
    assert(employees.empty());
    std::cout << "empty json test passed!" << std::endl;
}

void test_empty_xml()
{
    std::vector<Employee> employees = parseXML("tests/data/xml/empty_format1.xml");
    assert(employees.empty());
    employees = parseXML("tests/data/xml/empty_format2.xml");
    assert(employees.empty());
    std::cout << "empty xml test passed!" << std::endl;
}

void test_empty_name()
{
    std::vector<Employee> employees = {
        {"", 1, "Engineering", 50000},
        {"Jane Smith", 2, "HR", 60000}};
    assert(employees[0].getName() == "");
    assert(employees[1].getName() == "Jane Smith");
    std::cout << "empty name test passed!" << std::endl;
}

void test_empty_department()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "", 50000},
        {"Jane Smith", 2, "HR", 60000}};
    assert(employees[0].getDepartment() == "");
    assert(employees[1].getDepartment() == "HR");
    std::cout << "empty department test passed!" << std::endl;
}

void test_empty_id()
{
    std::vector<Employee> employees = {
        {"John Doe", 0, "Engineering", 50000},
        {"Jane Smith", 2, "HR", 60000}};
    assert(employees[0].getId() == 0);
    assert(employees[1].getId() == 2);
    std::cout << "empty id test passed!" << std::endl;
}

void test_empty_salary()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "Engineering", 0},
        {"Jane Smith", 2, "HR", 60000}};
    assert(employees[0].getSalary() == 0);
    assert(employees[1].getSalary() == 60000);
    std::cout << "empty salary test passed!" << std::endl;
}

void test_empty_employee()
{
    std::vector<Employee> employees = {
        {"John Doe", 1, "Engineering", 50000},
        {"", 0, "", 0},
        {"Jane Smith", 2, "HR", 60000}};
    assert(employees[0].getName() == "John Doe");
    assert(employees[1].getId() == 0);
    assert(employees[2].getDepartment() == "HR");
    assert(employees[2].getSalary() == 60000);
    std::cout << "empty employee test passed!" << std::endl;
}

void test_empty_vector()
{
    std::vector<Employee> employees;
    assert(employees.empty());
    std::cout << "empty vector test passed!" << std::endl;
}

void test_different_input_file()
{
    std::string filename = "tests/data/json/no_formatjson";
    assert(filename.find(".json") == std::string::npos);

    filename = "tests/data/json/no_format.jon";
    assert(filename.find(".json") == std::string::npos);

    filename = "tests/data/json/no_formatxml";
    assert(filename.find(".xml") == std::string::npos);

    filename = "tests/data/json/no_format.xl";
    assert(filename.find(".xml") == std::string::npos);

    filename = "tests/data/no_format";
    assert(filename.find(".xml") == std::string::npos);

    std::cout << "invalid input file format tests passed!" << std::endl;
}

void run_all_tests()
{
    test_employee();
    test_display_results();
    test_negative_salaries();
    test_empty_json();
    test_empty_xml();
    test_empty_name();
    test_empty_department();
    test_empty_id();
    test_empty_salary();
    test_empty_employee();
    test_empty_vector();
    test_different_input_file();
}

int main()
{
    run_all_tests();

    std::cout << "All tests passed" << std::endl;

    return 0;
}

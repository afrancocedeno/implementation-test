#include <iostream>
#include <cassert>
#include <vector>
#include "../include/employee.h"
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function to parse JSON file
std::vector<Employee> parseJSON(const std::string &filename)
{
    std::vector<Employee> employees;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return employees;
    }

    json j;
    file >> j;

    if (j.contains("employees"))
    {
        for (const auto &employee : j["employees"])
        {
            employees.push_back({employee["name"].get<std::string>(),
                                 employee["id"].get<int>(),
                                 employee["department"].get<std::string>(),
                                 employee["salary"].get<double>()});
        }
    }
    else
    {
        for (const auto &item : j)
        {
            employees.push_back({item["name"].get<std::string>(),
                                 item["id"].get<int>(),
                                 item["department"].get<std::string>(),
                                 item["salary"].get<double>()});
        }
    }
    return employees;
}

// Function to parse XML file with validation for empty file
std::vector<Employee> parseXML(const std::string &filename) {
    std::vector<Employee> employees;
    xmlDoc *document = xmlReadFile(filename.c_str(), NULL, 0);
    if (document == NULL) {
        std::cerr << "Failed to parse document or document is empty: " << filename << std::endl;
        return employees;
    }
    xmlNode *root = xmlDocGetRootElement(document);
    if (root == NULL) {
        std::cerr << "No root element in XML file: " << filename << std::endl;
        xmlFreeDoc(document);
        return employees;
    }
    xmlNode *cur_node = NULL;

    for (cur_node = root->children; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE && 
            (xmlStrcmp(cur_node->name, (const xmlChar *)"employee") == 0 ||
             xmlStrcmp(cur_node->name, (const xmlChar *)"record") == 0)) {
            Employee emp;
            for (xmlNode *child = cur_node->children; child; child = child->next) {
                if (xmlStrcmp(child->name, (const xmlChar *)"name") == 0) {
                    emp.name = (char *)xmlNodeGetContent(child);
                } else if (xmlStrcmp(child->name, (const xmlChar *)"id") == 0) {
                    emp.id = std::stoi((char *)xmlNodeGetContent(child));
                } else if (xmlStrcmp(child->name, (const xmlChar *)"department") == 0) {
                    emp.department = (char *)xmlNodeGetContent(child);
                } else if (xmlStrcmp(child->name, (const xmlChar *)"salary") == 0) {
                    emp.salary = std::stod((char *)xmlNodeGetContent(child));
                }
            }
            employees.push_back(emp);
        }
    }
    xmlFreeDoc(document);
    xmlCleanupParser();
    return employees;
}

void displayResults(std::vector<Employee> &employees)
{
    for (const auto &employee : employees)
    {
        std::cout << "Name: " << employee.getName() << ", "
                  << "ID: " << employee.getId() << ", "
                  << "Department: " << employee.getDepartment() << ", "
                  << "Salary: " << employee.getSalary() << std::endl;
    }
}

// Sample test case for Employee class
void testEmployee()
{
    Employee emp("John Doe", 101, "HR", 50000);

    assert(emp.getName() == "John Doe");
    assert(emp.getId() == 101);
    assert(emp.getDepartment() == "HR");
    assert(emp.getSalary() == 50000);

    std::cout << "All Employee tests passed!" << std::endl;
}

// Additional test case for displayResults
void testDisplayResults()
{
    std::vector<Employee> employees = {
        Employee("John Doe", 101, "HR", 50000),
        Employee("Jane Smith", 102, "Engineering", 60000)};

    displayResults(employees);
    std::cout << "displayResults test passed!" << std::endl;
}

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
    test_negative_salaries();
    test_empty_json();
    /*
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

int main()
{
    run_all_tests();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

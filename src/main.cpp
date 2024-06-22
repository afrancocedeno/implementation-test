#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "nlohmann/json.hpp"
#include "../include/employee.h"

using json = nlohmann::json;

// Function to parse JSON file
std::vector<Employee> parseJSON(const std::string &filename)
{
    std::vector<Employee> employees;
    std::ifstream file(filename);

    if (!file.good())
    {
        std::cerr << "File does not exists " << filename << std::endl;
        exit(1);
    }

    // Check if the file is empty
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "JSON file " << filename << " is empty." << std::endl;
        exit(1);
    }

    // guard to handle empty file from parser function

    json j;
    try
    {
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
    }
    catch (json::parse_error &e)
    {
        std::cerr << "Error parsing JSON file " << filename << ": " << e.what() << std::endl;
    }
    return employees;
}

// Function to parse XML file
std::vector<Employee> parseXML(const std::string &filename) {
    std::vector<Employee> employees;
    xmlDoc *document = xmlReadFile(filename.c_str(), NULL, 0);
    
    // Check if the document was parsed successfully
    if (document == nullptr) {
        std::cerr << "Failed to parse XML file " << filename << std::endl;
        return employees;
    }
    
    xmlNode *root = xmlDocGetRootElement(document);
    
    // Check if the root element is null (empty file) or if there are no child nodes
    if (root == nullptr || root->children == nullptr) {
        std::cerr << "XML file " << filename << " is empty or contains no employee data." << std::endl;
        xmlFreeDoc(document);
        return employees;
    }
    
    xmlNode *cur_node = nullptr;
    for (cur_node = root->children; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE && xmlStrcmp(cur_node->name, (const xmlChar *)"employee") == 0) {
            Employee emp;
            bool hasName = false, hasId = false, hasDepartment = false, hasSalary = false;
            for (xmlNode *child = cur_node->children; child; child = child->next) {
                if (child->type != XML_ELEMENT_NODE) {
                    continue;
                }
                if (xmlStrcmp(child->name, (const xmlChar *)"name") == 0) {
                    emp.name = (char *)xmlNodeGetContent(child);
                    hasName = true;
                } else if (xmlStrcmp(child->name, (const xmlChar *)"id") == 0) {
                    emp.id = std::stoi((char *)xmlNodeGetContent(child));
                    hasId = true;
                } else if (xmlStrcmp(child->name, (const xmlChar *)"department") == 0) {
                    emp.department = (char *)xmlNodeGetContent(child);
                    hasDepartment = true;
                } else if (xmlStrcmp(child->name, (const xmlChar *)"salary") == 0) {
                    emp.salary = std::stod((char *)xmlNodeGetContent(child));
                    hasSalary = true;
                }
            }
            if (hasName && hasId && hasDepartment && hasSalary) {
                employees.push_back(emp);
            } else {
                std::cerr << "Incomplete employee data in XML file " << filename << std::endl;
            }
        }
    }
    xmlFreeDoc(document);
    return employees;
}

// Function to calculate the average salary
double calculateAverageSalary(const std::vector<Employee> &employees)
{
    double total = 0;
    for (const auto &emp : employees)
    {
        total += emp.salary;
    }
    return total / employees.size();
}

// Function to find the highest paid employee
Employee findHighestPaidEmployee(const std::vector<Employee> &employees)
{
    return *std::max_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
                             { return a.salary < b.salary; });
}

// Function to sort employees by ID
void sortEmployeesById(std::vector<Employee> &employees)
{
    std::sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
              { return a.id < b.id; });
}

// Function to display results
void displayResults(std::vector<Employee> &employees)
{
    std::cout << "Average Salary: " << calculateAverageSalary(employees) << std::endl;
    Employee highestPaid = findHighestPaidEmployee(employees);
    std::cout << "Highest Paid Employee: " << highestPaid.name << ", ID: " << highestPaid.id
              << ", Department: " << highestPaid.department << ", Salary: " << highestPaid.salary << std::endl;
    sortEmployeesById(employees);
    std::cout << "Sorted Employees by ID:" << std::endl;
    for (const auto &emp : employees)
    {
        std::cout << "ID: " << emp.id << ", Name: " << emp.name << ", Department: " << emp.department
                  << ", Salary: " << emp.salary << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename1> [<filename2> ...]" << std::endl;
        return 1;
    }

    std::vector<Employee> allEmployees;

    for (int i = 1; i < argc; ++i)
    {
        std::string filename = argv[i];
        std::vector<Employee> employees;
        if (filename.find(".json") != std::string::npos)
        {
            employees = parseJSON(filename);
            if (employees.empty())
            {
                std::cerr << "No employees found in JSON file " << filename << std::endl;
                exit(1);
            }
        }
        else if (filename.find(".xml") != std::string::npos)
        {
            employees = parseXML(filename);
        }
        else
        {
            std::cerr << "Unsupported file format: " << filename << std::endl;
            return 1;
        }
        allEmployees.insert(allEmployees.end(), employees.begin(), employees.end());
    }

    displayResults(allEmployees);
    return 0;
}

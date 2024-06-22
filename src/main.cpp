#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "nlohmann/json.hpp"


using json = nlohmann::json;

struct Employee {
    std::string name;
    int id;
    std::string department;
    double salary;
};

// Function to parse JSON file
std::vector<Employee> parseJSON(const std::string &filename) {
    std::vector<Employee> employees;
    std::ifstream file(filename);
    json j;
    file >> j;

    if (j.contains("employees")) {
        for (const auto &employee : j["employees"]) {
            employees.push_back({
                employee["name"].get<std::string>(),
                employee["id"].get<int>(),
                employee["department"].get<std::string>(),
                employee["salary"].get<double>()
            });
        }
    } else {
        for (const auto &item : j) {
            employees.push_back({
                item["name"].get<std::string>(),
                item["id"].get<int>(),
                item["department"].get<std::string>(),
                item["salary"].get<double>()
            });
        }
    }
    return employees;
}

// Function to parse XML file
std::vector<Employee> parseXML(const std::string &filename) {
    std::vector<Employee> employees;
    xmlDoc *document = xmlReadFile(filename.c_str(), NULL, 0);
    xmlNode *root = xmlDocGetRootElement(document);
    xmlNode *cur_node = NULL;

    for (cur_node = root->children; cur_node; cur_node = cur_node->next) {
        if ((cur_node->type == XML_ELEMENT_NODE && xmlStrcmp(cur_node->name, (const xmlChar *)"employee") == 0) || 
            (cur_node->type == XML_ELEMENT_NODE && xmlStrcmp(cur_node->name, (const xmlChar *)"record") == 0)) {
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

// Function to calculate the average salary
double calculateAverageSalary(const std::vector<Employee> &employees) {
    double total = 0;
    for (const auto &emp : employees) {
        total += emp.salary;
    }
    return total / employees.size();
}

// Function to find the highest paid employee
Employee findHighestPaidEmployee(const std::vector<Employee> &employees) {
    return *std::max_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.salary < b.salary;
    });
}

// Function to sort employees by ID
void sortEmployeesById(std::vector<Employee> &employees) {
    std::sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.id < b.id;
    });
}

// Function to display results
void displayResults(std::vector<Employee> &employees) {
    std::cout << "Average Salary: " << calculateAverageSalary(employees) << std::endl;
    Employee highestPaid = findHighestPaidEmployee(employees);
    std::cout << "Highest Paid Employee: " << highestPaid.name << ", ID: " << highestPaid.id
              << ", Department: " << highestPaid.department << ", Salary: " << highestPaid.salary << std::endl;
    sortEmployeesById(employees);
    std::cout << "Sorted Employees by ID:" << std::endl;
    for (const auto &emp : employees) {
        std::cout << "ID: " << emp.id << ", Name: " << emp.name << ", Department: " << emp.department
                  << ", Salary: " << emp.salary << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename1> [<filename2> ...]" << std::endl;
        return 1;
    }

    std::vector<Employee> allEmployees;

    for (int i = 1; i < argc; ++i) {
        std::string filename = argv[i];
        std::vector<Employee> employees;
        if (filename.find(".json") != std::string::npos) {
            employees = parseJSON(filename);
        } else if (filename.find(".xml") != std::string::npos) {
            employees = parseXML(filename);
        } else {
            std::cerr << "Unsupported file format: " << filename << std::endl;
            return 1;
        }
        allEmployees.insert(allEmployees.end(), employees.begin(), employees.end());
    }

    displayResults(allEmployees);
    return 0;
}

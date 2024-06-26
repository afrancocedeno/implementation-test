#include "../include/employee.h"

int main(int argc, char *argv[])
{
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
            if (employees.empty())
            {
                std::cerr << "No employees found in XML file " << filename << std::endl;
                exit(1);
            }
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

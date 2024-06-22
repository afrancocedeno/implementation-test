// Function to parse XML file
std::vector<Employee> parseXML(const std::string &filename)
{
    std::vector<Employee> employees;
    xmlDoc *document = xmlReadFile(filename.c_str(), NULL, 0);

    // Check if the document was parsed successfully
    if (document == nullptr)
    {
        std::cerr << "Failed to parse XML file " << filename << std::endl;
        return employees;
    }

    xmlNode *root = xmlDocGetRootElement(document);

    // Check if the root element is null (empty file) or if there are no child nodes
    if (root == nullptr || root->children == nullptr)
    {
        std::cerr << "XML file " << filename << " is empty or contains no employee data." << std::endl;
        xmlFreeDoc(document);
        return employees;
    }

    xmlNode *cur_node = nullptr;
    for (cur_node = root->children; cur_node; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE && xmlStrcmp(cur_node->name, (const xmlChar *)"employee") == 0)
        {
            Employee emp;
            bool hasName = false, hasId = false, hasDepartment = false, hasSalary = false;
            for (xmlNode *child = cur_node->children; child; child = child->next)
            {
                if (child->type != XML_ELEMENT_NODE)
                {
                    continue;
                }
                if (xmlStrcmp(child->name, (const xmlChar *)"name") == 0)
                {
                    emp.name = (char *)xmlNodeGetContent(child);
                    hasName = true;
                }
                else if (xmlStrcmp(child->name, (const xmlChar *)"id") == 0)
                {
                    emp.id = std::stoi((char *)xmlNodeGetContent(child));
                    hasId = true;
                }
                else if (xmlStrcmp(child->name, (const xmlChar *)"department") == 0)
                {
                    emp.department = (char *)xmlNodeGetContent(child);
                    hasDepartment = true;
                }
                else if (xmlStrcmp(child->name, (const xmlChar *)"salary") == 0)
                {
                    emp.salary = std::stod((char *)xmlNodeGetContent(child));
                    hasSalary = true;
                }
            }
            if (hasName && hasId && hasDepartment && hasSalary)
            {
                employees.push_back(emp);
            }
            else
            {
                std::cerr << "Incomplete employee data in XML file " << filename << std::endl;
            }
        }
    }
    xmlFreeDoc(document);
    return employees;
}

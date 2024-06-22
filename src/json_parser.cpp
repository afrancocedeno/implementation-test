// Function to parse JSON file
std::vector<Employee> parseJSON(const std::string &filename)
{
    std::vector<Employee> employees;
    std::ifstream file(filename);

    // Check if the file is empty
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "JSON file " << filename << " is empty." << std::endl;
        return employees;
    }

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

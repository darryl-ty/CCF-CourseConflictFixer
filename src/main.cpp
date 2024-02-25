#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void readCoursesCSV(const std::string&);

int main() {
    const std::string coursesFile = "courses.csv";

    std::cout << "Welcome to the CCF - Course Conflict Fixer!" << std::endl;
    readCoursesCSV(coursesFile);


    return 0;
}

void readCoursesCSV(const std::string& input) {
    std::ifstream file(input);
    std::vector<std::vector<std::string>> data;

    // Read and print each line
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, '|')) {
            row.push_back(value);
        }

        data.push_back(row);
    }


    data.erase(data.begin());
    file.close();


    for (const auto& row : data) {
        for (const auto& value : row) {
            std::cout << value << "|";
        }
        std::cout << std::endl;
    }
}

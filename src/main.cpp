#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::string collectCourseFile();
void readCoursesCSV(const std::string&);

int main() {
    std::cout << "Welcome to the CCF - Course Conflict Fixer! Please input the name of the course csv below:" << std::endl;
    std::string userInput = collectCourseFile();
    readCoursesCSV(userInput);


    return 0;
}

std::string collectCourseFile(){
    std::string userFileString;
    std::cin >> userFileString;

    return userFileString;
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


    file.close();


    for (const auto& row : data) {
        for (const auto& value : row) {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}

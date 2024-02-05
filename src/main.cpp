#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void readCoursesCSV();

int main() {
    readCoursesCSV();


    return 0;
}

void readCoursesCSV() {
    std::ifstream file("courses.csv");
    std::vector<std::vector<std::string>> data;

    // Read and print each line
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) {
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

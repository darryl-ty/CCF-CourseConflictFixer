#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "courses.h"

std::string collectCourseFile();
std::vector<Courses> readCoursesCSV(const std::string&);

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

std::vector<Courses> readCoursesCSV(const std::string& input) {
    std::ifstream file(input);
    std::vector<Courses> courses;

    // Read and print each line
    std::string line;
    while (std::getline(file, line)) {
        std::string semester, department, classNum, sectionNum, className, enrollLimit;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, '|')) {

        }

        Courses(semester, department, classNum, sectionNum, className, enrollLimit, ) course;
        courses.push_back(course);
    }


    courses.erase(courses.begin());
    file.close();


    for (const auto& row : courses) {
        for (const auto& value : row) {
            std::cout << value << "|";
        }
        std::cout << std::endl;
    }
}

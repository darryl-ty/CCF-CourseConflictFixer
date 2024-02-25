#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Course.h"

void readCoursesCSV(const std::string&);

int main() {
    const std::string coursesFile = "courses.csv";

    std::cout << "Welcome to the CCF - Course Conflict Fixer!" << std::endl;
    readCoursesCSV(coursesFile);


    return 0;
}

void readCoursesCSV(const std::string& input) {
    std::ifstream file(input);
    std::string line;

    std::getline(file,line); //skips header
    while(std::getline(file, line)){
        std::string semester;
        std::string dept;
        std::string classNum;
        std::string section;
        std::string className;

        std::string next;
        std::vector<std::string> result;
        for (char itr : line) {
            if (itr == '|') {
                if (!next.empty()) {
                    result.push_back(next);
                    next.clear();
                }
            } else {
                next += itr;
            }
        }
        if (!next.empty())
            result.push_back(next);

        for (auto& entry : result){
            for (auto& value : entry){
                std::cout << value << "";
            }
        }
    }


}

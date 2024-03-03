#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

#include "Course.h"

std::vector<Course> readCoursesCSV(const std::string&);

void testCourses(const std::vector<Course>& courses);

int main() {
    const std::string coursesFile = "courses.csv";

    std::cout << "Welcome to the CCF - Course Conflict Fixer!" << std::endl;
    auto courses = readCoursesCSV(coursesFile);

    testCourses(courses);


    return 0;
}

std::vector<Course> readCoursesCSV(const std::string& input) {
    std::ifstream file(input);
    std::string line;
    std::vector<Course> courses;

    std::getline(file,line); //skips header
    while(std::getline(file, line)){
        std::string semester;
        std::string dept;
        std::string classNum;
        std::string section;
        std::string className;
        std::vector<std::string> enrollLimit;
        std::vector<std::string> days;
        std::vector<std::string> time;
        std::vector<std::string> building;
        std::vector<std::string> room;
        std::vector<std::string> teachers;

        std::string value;
        std::vector<std::string> courseValues;
        for (char itr : line) {
            if (itr == '|') {
                if (!value.empty()) {
                    courseValues.push_back(value);
                    value.clear();
                }
            } else {
                value += itr;
            }
        }
        if (!value.empty())
            courseValues.push_back(value);


        for (size_t i = 0; i < courseValues.size(); i++){
            switch (i) {
                case 0:
                    semester = courseValues[i];
                    break;
                case 1:
                    dept = courseValues[i];
                    break;
                case 2:
                    classNum = courseValues[i];
                    break;
                case 3:
                    section = courseValues[i];
                    break;
                case 4:
                    className = courseValues[i];
                    break;
                case 5:
                    days.push_back(courseValues[i]);
                    break;
                case 6:
                    time.push_back(courseValues[i]);
                    break;
                case 7:
                    building.push_back(courseValues[i]);
                    break;
                case 8:
                    room.push_back(courseValues[i]);
                    break;
                case 9:
                    enrollLimit.push_back(courseValues[i]);
                    break;
                case 10:
                    teachers.push_back(courseValues[i]);
                    break;
            }
        }

        courses.emplace_back(semester,dept,classNum,section,className,enrollLimit,days,time,building,room,teachers);

    }


    return courses;
}


void testCourses(const std::vector<Course>& courses) {

    assert(!courses.empty());

    assert(!courses[0].getSemesterOffered().empty());
    assert("202301" != courses[0].getSemesterOffered());
    assert("202408" == courses[0].getSemesterOffered());

    assert(!courses[1].getSemesterOffered().empty());
    assert("202408" != courses[1].getSemesterOffered());
    assert("202501" == courses[1].getSemesterOffered());

}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

#include "Course.h"

std::vector<Course> readCoursesCSV(const std::string&);

void compareCourseEntries(const std::vector<Course> &courses);
void testCourses(const std::vector<Course> &courses);

int main() {
    const std::string coursesFile = "courses.csv";

    std::cout << "Welcome to the CCF - Course Conflict Fixer!" << std::endl;
    std::vector<Course> *coursePtr;
    std::vector<Course> courses = readCoursesCSV(coursesFile);
    coursePtr = &courses;

    compareCourseEntries(*coursePtr);


    testCourses(*coursePtr);


    return 0;
}

void compareCourseEntries(const std::vector<Course> &courses) {

    for (size_t i = 0; i < courses.size(); i++) {
        for (size_t j = i+1; j < courses.size(); j++) {
            courses[i].compareCourses(courses[j]);
            std::cout << "Course " << i << " and Course " << j << std::endl;
        }
    }
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


void testCourses(const std::vector<Course> &courses) {
    std::ostringstream output;
    std::streambuf *outputBuffer = std::cout.rdbuf(); // Create ptr for cout buffer we can reference later on.

    std::cout.rdbuf(output.rdbuf()); // Change cout to a "local" output buffer that we can test.

    assert(!courses.empty());

    assert(!courses[0].getSemesterOffered().empty());
    assert("202301" != courses[0].getSemesterOffered());
    assert("202408" == courses[0].getSemesterOffered());
    assert("PSYCH" != courses[0].getDepartment());
    assert("CPSC" == courses[0].getDepartment());

    assert(!courses[1].getSemesterOffered().empty());
    assert("202408" != courses[1].getSemesterOffered());
    assert("202501" == courses[1].getSemesterOffered());
    assert("ENGR" != courses[0].getDepartment());
    assert("CPSC" == courses[0].getDepartment());


    courses[0].compareCourses(courses[1]);
    std::cout.rdbuf(outputBuffer); // Change cout back to its original buffer
    assert(output.str() == "No detected course conflicts. ");
    output.str(""); // Set output to be empty.
    output.clear(); // Clear state of output for next assertion.
    std::cout.rdbuf(output.rdbuf()); // Change cout back to a "local" output buffer that we can test for next assertion.

    courses[0].compareCourses(courses[4]);
    std::cout.rdbuf(outputBuffer);
    assert(output.str() == "Non-critical course conflict detected. ");
    output.str("");
    output.clear();
    std::cout.rdbuf(output.rdbuf());

    courses[4].compareCourses(courses[5]);
    std::cout.rdbuf(outputBuffer);
    assert(output.str() == "Time-Room conflict detected! ");
    output.str("");
    output.clear();


}
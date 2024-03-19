#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

#include "courses.h"
#include "course.h"

Courses readCoursesCSV(const std::string&);

void compareCourseEntries(const Courses &courses);
void testCourses(const Courses &courses);

int main() {
    const std::string coursesFile = "courses.csv";

    std::cout << "Welcome to the CCF - Course Conflict Fixer!" << std::endl;
    Courses courses = readCoursesCSV(coursesFile);
    Courses *coursePtr = &courses;

    compareCourseEntries(*coursePtr);

    testCourses(*coursePtr);


    return 0;
}

void compareCourseEntries(const Courses &courses) {

    for (size_t i = 0; i < courses.getCourses().size(); i++) {
        for (size_t j = i+1; j < courses.getCourses().size(); j++) {
            courses.getCourses()[i].compareCourses(courses.getCourses()[j]);
            std::cout << "Course " << i << " and Course " << j << std::endl;
        }
    }
}

Courses readCoursesCSV(const std::string& input) {
    std::ifstream file(input);
    std::string line;
    Courses courses;
    std::vector<std::string> vectorValue;
    uint8_t value = 0;
    size_t pos = 0;

    std::getline(file,line); //skips header
    while(std::getline(file, line)){
        Course course;
        while((pos = line.find('|')) != std::string::npos){
            auto courseValue = line.substr(0, pos);
            switch (value) {
                case 0:
                    course.setSemesterOffered(courseValue);
                    break;
                case 1:
                    course.setDepartment(courseValue);
                    break;
                case 2:
                    course.setClassNum(courseValue);
                    break;
                case 3:
                    course.setSectionNum(courseValue);
                    break;
                case 4:
                    course.setClassName(courseValue);
                    break;
                case 5:
                    vectorValue.emplace_back(courseValue);
                    course.setDays(vectorValue);
                    vectorValue.clear();
                    break;
                case 6:
                    vectorValue.emplace_back(courseValue);
                    course.setTime(vectorValue);
                    vectorValue.clear();
                    break;
                case 7:
                    vectorValue.emplace_back(courseValue);
                    course.setBuilding(vectorValue);
                    vectorValue.clear();
                    break;
                case 8:
                    vectorValue.emplace_back(courseValue);
                    course.setRoom(vectorValue);
                    vectorValue.clear();
                    break;
                case 9:
                    vectorValue.emplace_back(courseValue);
                    course.setEnrollLimit(vectorValue);
                    vectorValue.clear();
                    break;
                case 10:
                    vectorValue.emplace_back(courseValue);
                    course.setTeachers(vectorValue);
                    vectorValue.clear();
                    break;
            }

            line.erase(0, pos + 1);
            value++;
        }

        courses.addCourse(course);
        value = 0;
        pos = 0;

    }


    return courses;
}


void testCourses(const Courses &courses) {
    std::ostringstream output;
    std::streambuf *outputBuffer = std::cout.rdbuf(); // Create ptr for cout buffer we can reference later on.

    std::cout.rdbuf(output.rdbuf()); // Change cout to a "local" output buffer that we can test.

    assert(!courses.getCourses().empty());

    assert(!courses.getCourses()[0].getSemesterOffered().empty());
    assert("202301" != courses.getCourses()[0].getSemesterOffered());
    assert("202408" == courses.getCourses()[0].getSemesterOffered());
    assert("PSYCH" != courses.getCourses()[0].getDepartment());
    assert("CPSC" == courses.getCourses()[0].getDepartment());

    assert(!courses.getCourses()[1].getSemesterOffered().empty());
    assert("202408" != courses.getCourses()[1].getSemesterOffered());
    assert("202501" == courses.getCourses()[1].getSemesterOffered());
    assert("ENGR" != courses.getCourses()[0].getDepartment());
    assert("CPSC" == courses.getCourses()[0].getDepartment());


    courses.getCourses()[0].compareCourses(courses.getCourses()[1]);
    std::cout.rdbuf(outputBuffer); // Change cout back to its original buffer
    assert(output.str() == "No detected course conflicts. ");
    output.str(""); // Set output to be empty.
    output.clear(); // Clear state of output for next assertion.
    std::cout.rdbuf(output.rdbuf()); // Change cout back to a "local" output buffer that we can test for next assertion.

    courses.getCourses()[0].compareCourses(courses.getCourses()[4]);
    std::cout.rdbuf(outputBuffer);
    assert(output.str() == "Non-critical course conflict detected. ");
    output.str("");
    output.clear();
    std::cout.rdbuf(output.rdbuf());

    courses.getCourses()[4].compareCourses(courses.getCourses()[5]);
    std::cout.rdbuf(outputBuffer);
    assert(output.str() == "Time-Room conflict detected! ");
    output.str("");
    output.clear();


}
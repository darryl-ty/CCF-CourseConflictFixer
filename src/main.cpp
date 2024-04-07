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
    courses.compareCourseObjects();
}

Courses readCoursesCSV(const std::string& input) {
    Courses courses;
    courses.readCourseCSV(input);


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
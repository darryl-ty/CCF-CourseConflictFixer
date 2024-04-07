#include <fstream>
#include "Courses.h"


Courses::Courses() = default;


Courses::~Courses() = default;


void Courses::addCourse(const Course &course) {
    m_courses.push_back(course);

}

std::vector<Course> Courses::getCourses() const {
    return m_courses;
}

void Courses::readCourseCSV(const std::string& input){
    std::ifstream file(input);
    std::string line;
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

        this->addCourse(course);
        value = 0;
        pos = 0;

    }
}

void Courses::compareCourseObjects() const {
    for (size_t i = 0; i < this->getCourses().size(); i++) {
        for (size_t j = i+1; j < this->getCourses().size(); j++) {
            this->getCourses()[i].compareCourses(this->getCourses()[j]);
            std::cout << "Course " << i << " and Course " << j << std::endl;
        }
    }
}

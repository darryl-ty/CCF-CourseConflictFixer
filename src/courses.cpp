#include "Courses.h"


Courses::Courses() = default;


Courses::~Courses() = default;


void Courses::addCourse(const Course &course) {
    m_courses.push_back(course);

}

std::vector<Course> Courses::getCourses() const {
    return m_courses;
}

void Courses::compareCourseObjects() const {
    for (size_t i = 0; i < this->getCourses().size(); i++) {
        for (size_t j = i+1; j < this->getCourses().size(); j++) {
            this->getCourses()[i].compareCourses(this->getCourses()[j]);
            std::cout << "Course " << i << " and Course " << j << std::endl;
        }
    }
}

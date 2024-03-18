#include "Courses.h"


Courses::Courses() {
}


Courses::~Courses() {

}


void Courses::addCourse(const Course &course) {
    m_courses.push_back(course);

}

std::vector<Course> Courses::getCourses() const {
    return m_courses;
}
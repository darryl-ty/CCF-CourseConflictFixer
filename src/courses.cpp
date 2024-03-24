#include "Courses.h"


Courses::Courses() = default;


Courses::~Courses() = default;


void Courses::addCourse(const Course &course) {
    m_courses.push_back(course);

}

std::vector<Course> Courses::getCourses() const {
    return m_courses;
}

void Courses::compareCourseObjects() {

}

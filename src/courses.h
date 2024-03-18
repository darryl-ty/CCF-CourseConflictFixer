#pragma once
#ifndef COURSES_H
#define COURSES_H

#include <vector>
#include "course.h"

class Courses {

    std::vector<Course> m_courses;

public:

    Courses();
    ~Courses();

    void addCourse(const Course &course);
};


#endif

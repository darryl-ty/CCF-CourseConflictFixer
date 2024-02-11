#pragma once
#ifndef COURSES_H
#define COURSES_H

#include <string_view>
#include <vector>


class Courses {
    std::string_view m_semesterOffered, m_department, m_classNum, m_sectionNum, m_className, m_enrollLimit;
    std::vector<std::string_view> m_days, m_time, m_building, m_room, m_teachers;

public:
    Courses(std::string_view semesterOffered, std::string_view department, std::string_view classNum, std::string_view sectionNum,
            std::string_view className, std::string_view enrollLimit, std::vector<std::string_view>& days,
            std::vector<std::string_view>& time, std::vector<std::string_view>& building,
            std::vector<std::string_view>& room, std::vector<std::string_view>& teachers):
            m_semesterOffered(semesterOffered), m_department(department),
            m_classNum(classNum), m_sectionNum(sectionNum), m_className(className),
            m_enrollLimit(enrollLimit), m_days(days), m_time(time), m_building(building), m_room(room), m_teachers(teachers){

    }



};


#endif

#pragma once
#ifndef COURSES_H
#define COURSES_H

#include <string_view>
#include <string>
#include <vector>


class Course {
    std::string m_semesterOffered, m_department, m_classNum, m_sectionNum, m_className;
    std::vector<std::string> m_enrollLimit, m_days, m_time, m_building, m_room, m_teachers;

public:
    Course(std::string semesterOffered, std::string department, std::string classNum, std::string sectionNum,
           std::string className, std::vector<std::string> enrollLimit, std::vector<std::string> days,
           std::vector<std::string> time, std::vector<std::string> building,
           std::vector<std::string> room, std::vector<std::string> teachers);
    Course();

//    void setSemesterOffered(const std::string& semester);
//
//    void setDepartment(const std::string& department);
//
//    void setMClassNum(const std::string &mClassNum);
//
//    void setMSectionNum(const std::string &mSectionNum);
//
//    void setMClassName(const std::string &mClassName);
//
//    void setMEnrollLimit(const std::string &mEnrollLimit);
//
//    void setMDays(const std::vector<std::string> &mDays);
//
//    void setMTime(const std::vector<std::string> &mTime);
//
//    void setMBuilding(const std::vector<std::string> &mBuilding);
//
//    void setMRoom(const std::vector<std::string> &mRoom);
//
//    void setMTeachers(const std::vector<std::string> &mTeachers);
//
    const std::string &getSemesterOffered() const;
//
//    const std::string &getMDepartment() const;
//
//    const std::string &getMClassNum() const;
//
//    const std::string &getMSectionNum() const;
//
//    const std::string &getMClassName() const;
//
//    const std::string &getMEnrollLimit() const;
//
//    const std::vector<std::string> &getMDays() const;
//
//    const std::vector<std::string> &getMTime() const;
//
//    const std::vector<std::string> &getMBuilding() const;
//
//    const std::vector<std::string> &getMRoom() const;
//
//    const std::vector<std::string> &getMTeachers() const;


};


#endif

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
//    void setClassNum(const std::string &mClassNum);
//
//    void setSectionNum(const std::string &mSectionNum);
//
//    void setClassName(const std::string &mClassName);
//
//    void setEnrollLimit(const std::string &mEnrollLimit);
//
//    void setDays(const std::vector<std::string> &mDays);
//
//    void setTime(const std::vector<std::string> &mTime);
//
//    void setBuilding(const std::vector<std::string> &mBuilding);
//
//    void setRoom(const std::vector<std::string> &mRoom);
//
//    void setTeachers(const std::vector<std::string> &mTeachers);
//
    const std::string &getSemesterOffered() const;

    const std::string &getDepartment() const;
//
//    const std::string &getClassNum() const;
//
//    const std::string &getSectionNum() const;
//
//    const std::string &getClassName() const;
//
//    const std::string &getEnrollLimit() const;
//
//    const std::vector<std::string> &getDays() const;
//
//    const std::vector<std::string> &getTime() const;
//
//    const std::vector<std::string> &getBuilding() const;
//
//    const std::vector<std::string> &getRoom() const;
//
//    const std::vector<std::string> &getTeachers() const;


};


#endif

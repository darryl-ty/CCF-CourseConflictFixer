
//#include <string_view> TODO - Refactor all strings later to be string_views, we only need to view and compare strings, not modify.
#include <string>
#include <utility>
#include "course.h"

Course::Course(std::string semesterOffered, std::string department, std::string classNum,
                 std::string sectionNum, std::string className, std::vector<std::string> enrollLimit,
                 std::vector<std::string> days, std::vector<std::string> time, std::vector<std::string> building,
                 std::vector<std::string> room, std::vector<std::string> teachers) : m_semesterOffered(std::move(semesterOffered)), m_department(std::move(department)),
                 m_classNum(std::move(classNum)), m_sectionNum(std::move(sectionNum)), m_className(std::move(className)),
                 m_enrollLimit(std::move(enrollLimit)), m_days(std::move(days)), m_time(std::move(time)), m_building(std::move(building)), m_room(std::move(room)), m_teachers(std::move(teachers)){};

Course::Course(){};



//void Courses::setSemesterOffered(const std::string& semester) {
//    m_semesterOffered = semester;
//}
//
//void Courses::setDepartment(const std::string& department) {
//    m_department = department;
//}
//
//void Courses::setClassNum(const std::string& mClassNum) {
//    m_classNum = mClassNum;
//}
//
//void Courses::setSectionNum(const std::string& mSectionNum) {
//    m_sectionNum = mSectionNum;
//}
//
//void Courses::setClassName(const std::string& mClassName) {
//    m_className = mClassName;
//}
//
//void Courses::setEnrollLimit(const std::string& mEnrollLimit) {
//    m_enrollLimit = mEnrollLimit;
//}
//
//void Courses::setDays(const std::vector<std::string>& mDays) {
//    m_days = mDays;
//}
//
//void Courses::setTime(const std::vector<std::string>& mTime) {
//    m_time = mTime;
//}
//
//void Courses::setBuilding(const std::vector<std::string>& mBuilding) {
//    m_building = mBuilding;
//}
//
//void Courses::setRoom(const std::vector<std::string>& mRoom) {
//    m_room = mRoom;
//}
//
//void Courses::setTeachers(const std::vector<std::string>& mTeachers) {
//    m_teachers = mTeachers;
//}
//
const std::string &Course::getSemesterOffered() const {
    return m_semesterOffered;
}

const std::string &Course::getDepartment() const {
    return m_department;
}

const std::string &Course::getClassNum() const {
    return m_classNum;
}

const std::string &Course::getSectionNum() const {
    return m_sectionNum;
}

const std::string &Course::getClassName() const {
    return m_className;
}

const std::vector<std::string> &Course::getEnrollLimit() const {
    return m_enrollLimit;
}

const std::vector<std::string> &Course::getDays() const {
    return m_days;
}

const std::vector<std::string> &Course::getTime() const {
    return m_time;
}

const std::vector<std::string> &Course::getBuilding() const {
    return m_building;
}

const std::vector<std::string> &Course::getRoom() const {
    return m_room;
}

const std::vector<std::string> &Course::getTeachers() const {
    return m_teachers;
}

void Course::compareCourses(const Course &course) const {
    std::bitset<6> conflictBitset;

    if (this->getSemesterOffered() == course.getSemesterOffered())
        conflictBitset.set(size_t(0), true);
    if (this->getDays() == course.getDays())
        conflictBitset.set(size_t(1), true);
    if(this->getTime() == course.getTime())
        conflictBitset.set(size_t(2), true);
    if (this->getBuilding() == course.getBuilding())
        conflictBitset.set(size_t(3), true);
    if (this->getRoom() == course.getRoom())
        conflictBitset.set(size_t(4), true);
    if (this->getTeachers() == course.getTeachers())
        conflictBitset.set(size_t(5), true);


//    std::cout << "conflictBitset: " << conflictBitset << std::endl;
    Course::calculateConflicts(conflictBitset);


//    return value;
}

uint8_t Course::calculateConflicts(const std::bitset<6> &conflictBitset) {
    uint8_t decimalValue = conflictBitset.to_ullong();
    switch (decimalValue) {
        case 0:
            std::cout << "No detected course conflicts. ";
            return decimalValue;
        case 7:
            std::cout << "Semester-Time conflict detected! ";
            return decimalValue;
        case 31:
            std::cout << "Time-Room conflict detected! ";
            return decimalValue;
        case 39:
            std::cout << "Teacher-Time conflict detected! ";
            return decimalValue;
        default:
            std::cout << "Non-critical course conflict detected. ";
            return 0;

    }
}
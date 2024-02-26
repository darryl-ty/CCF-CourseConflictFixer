
//#include <string_view> TODO - Refactor all strings later to be string_views, we only need to view and compare strings, not modify.
#include <string>
#include <utility>
#include "Course.h"

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
//
//const std::string &Courses::getDepartment() const {
//    return m_department;
//}
//
//const std::string &Courses::getClassNum() const {
//    return m_classNum;
//}
//
//const std::string &Courses::getSectionNum() const {
//    return m_sectionNum;
//}
//
//const std::string &Courses::getClassName() const {
//    return m_className;
//}
//
//const std::string &Courses::getEnrollLimit() const {
//    return m_enrollLimit;
//}
//
//const std::vector<std::string> &Courses::getDays() const {
//    return m_days;
//}
//
//const std::vector<std::string> &Courses::getTime() const {
//    return m_time;
//}
//
//const std::vector<std::string> &Courses::getBuilding() const {
//    return m_building;
//}
//
//const std::vector<std::string> &Courses::getRoom() const {
//    return m_room;
//}
//
//const std::vector<std::string> &Courses::getTeachers() const {
//    return m_teachers;
//}

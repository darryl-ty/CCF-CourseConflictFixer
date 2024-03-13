cmake_minimum_required(VERSION 3.25)
project(CourseConflictFixer)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp src/course.cpp src/courses.cpp)

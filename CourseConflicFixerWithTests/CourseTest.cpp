#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../CourseConflictFixer/src/Course.h"
#include "doctest.h"

Course testCourse = {"202408", "CPSC","1005","1","Intro to PCs and Software Appls",
                     std::vector<std::string>{"20"},std::vector<std::string>{"TR"},
                     std::vector<std::string>{"9:25-10:40 am"},std::vector<std::string>{"37"},
                     std::vector<std::string>{"570"},std::vector<std::string>{"Kun Zhang"}};

TEST_CASE("Test different variables of Course objects."){

    CHECK((testCourse.getSemesterOffered()) == ("202408"));
    CHECK((testCourse.getSemesterOffered()) == ("202301"));
}

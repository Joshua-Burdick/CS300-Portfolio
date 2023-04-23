#include "Course.h"

// Create Course with name and number, and possibly prerequisites
Course::Course() {
    this->courseNumber = "";
    this->courseName = "";
}

Course::Course(string number, string name) {
    this->courseNumber = number;
    this->courseName = name;
}

Course::Course(string number, string name, vector<string> preReqs) {
    this->courseNumber = number;
    this->courseName = name;
    this->prerequisites = preReqs;
}

// copy constructor
Course::Course(const Course& course) {
    this->courseNumber = course.courseNumber;
    this->courseName = course.courseName;
    this->prerequisites = course.prerequisites;
}

// print course information
void Course::print() {
    if (this->empty()) return;
    printf("%s, %s", this->courseNumber.c_str(), this->courseName.c_str());
}

// print the course's prerequisites
void Course::printPrerequisites() {
    if (this->prerequisites.size() == 0) return;
    printf("Prerequisites: ");
    for (int i = 0; i < this->prerequisites.size(); i++) {
        printf("%s", this->prerequisites[i].c_str());
        if (i < this->prerequisites.size() - 1) printf(", ");
    }
}

// return course number
string Course::readId() {
    return this->courseNumber;
}

// if the course is empty
bool Course::empty() {
    return this->courseNumber == "" && this->courseName == "";
}

// assignment operator
Course& Course::operator=(const Course& course) {
    this->courseNumber = course.courseNumber;
    this->courseName = course.courseName;
    this->prerequisites = course.prerequisites;

    return *this;
}

// less than operator
bool Course::operator<(const Course& course) {
    return this->courseNumber < course.courseNumber;
}

// greater than operator
bool Course::operator>(const Course& course) {
    return this->courseNumber > course.courseNumber;
}

// equal to operator
bool Course::operator==(const Course& course) {
    return this->courseNumber == course.courseNumber;
}

// less than or equal to operator
bool Course::operator<=(const Course& course) {
    return this->courseNumber <= course.courseNumber;
}

// greater than or equal to operator
bool Course::operator>=(const Course& course) {
    return this->courseNumber >= course.courseNumber;
}
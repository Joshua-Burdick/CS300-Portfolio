#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
    private:
        string courseNumber, courseName;
        vector<string> prerequisites;
    public:
        Course();
        Course(string number, string name);
        Course(string number, string name, vector<string> preReqs);
        Course(const Course& course);
        void print();
        void printPrerequisites();
        string readId();
        bool empty();
        Course& operator=(const Course& course);
        bool operator<(const Course& course);
        bool operator>(const Course& course);
        bool operator==(const Course& course);
        bool operator<=(const Course& course);
        bool operator>=(const Course& course);
};
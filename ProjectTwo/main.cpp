/// @author Joshua Burdick
/// @date 2023-04-23
/// @version 1.0
/// @brief ABCU Course Advising Asisstance System: Sorting and Alphanumerically Printing Courses

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Course.h"

using namespace std;

void merge(vector<Course>& list, int left, int mid, int right);
void mergeSort(vector<Course>& list, int begin, int end);
fstream openFile(string filepath);
vector<string> split(string str, char delim);
void readFile(fstream& file, vector<Course>& courses);
void printAlphanumeric(vector<Course>& courses);

int main(int argc, char* argv[]) {
    string filepath, searchId;
    fstream file;
    vector<Course> courses;

    // Select file
    if (argc < 2) {
        printf("Enter a file to read: ");
        cin >> filepath;
    }
    else filepath = argv[1];

    // Open file
    try {
        file = openFile(filepath);
    }
    catch(char* err) {
        printf("%s", err);
    }

    readFile(file, courses);
    mergeSort(courses, 0, courses.size() - 1);
    printAlphanumeric(courses);
}

void merge(vector<Course>& list, int left, int mid, int right) {
    int subLeft = mid - left + 1;
    int subRight = right - mid;
 
    // Create temp arrays
    Course *leftArr = new Course[subLeft], *rightArr = new Course[subRight];
 
    // Copy data to temp arrays
    for (int i = 0; i < subLeft; i++) leftArr[i] = list[left + i];
    for (int j = 0; j < subRight; j++) rightArr[j] = list[mid + 1 + j];
 
    int indexLeft = 0, indexRight = 0, indexMerged = left;
 
    // Merge the temp arrays back into array
    while (indexLeft < subLeft && indexRight < subRight) {
        if (leftArr[indexLeft] <= rightArr[indexRight]) {
            list[indexMerged] = leftArr[indexLeft];
            indexLeft++;
        }
        else {
            list[indexMerged] = rightArr[indexRight];
            indexRight++;
        }
        indexMerged++;
    }
    // Copy the remaining elements of left array
    while (indexLeft < subLeft) {
        list[indexMerged] = leftArr[indexLeft];
        indexLeft++;
        indexMerged++;
    }
    // Copy the remaining elements of right array
    while (indexRight < subRight) {
        list[indexMerged] = rightArr[indexRight];
        indexRight++;
        indexMerged++;
    }

    // Memory cleanup
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(vector<Course>& list, int begin, int end) {
    // Ensure there are elements to sort.
    if (begin >= end) return;
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(list, begin, mid);
    mergeSort(list, mid + 1, end);
    merge(list, begin, mid, end);
}

/// @brief Open a given file, and ensure it is open
/// @param filepath The file to open
/// @return The opened file
fstream openFile(string filepath) {
    fstream file;
    file.open(filepath);

    if (!file.is_open()) {
        throw "Error opening file " + filepath;
    }

    return file;
}

/// @brief Split a string at a given delimiter
/// @param str The string to split
/// @param delim The delimiter to split at
/// @return A list of strings split at the delimiter
vector<string> split(string str, char delim) {
    vector<string> tokens;
    int end = str.find(delim);
    
    // split the strnig at delimiter
    while (end != -1) {
        tokens.push_back(str.substr(0, end));
        str.erase(str.begin(), str.begin() + end + 1);
        end = str.find(delim);
    }

    // add the last token
    tokens.push_back(str.substr(0, end));

    return tokens;
}

/// @brief  Read data from file into courses vector
/// @param file The file to read from
/// @param courses The list of courses to add to
void readFile(fstream& file, vector<Course>& courses) {
    string line;
    vector<vector<string>> prereqs;
    bool exists = false;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        // skip lines with less than 2 tokens
        int size = tokens.size();
        if (size < 2) continue;
        // to determine if the course exists already
        exists = false;
        for (auto course : courses) {
            if (course.readId() == tokens[0]) {
                exists = true;
                break;
            }
        }

        // if the course exists, add to list of courses (including prerequisites)
        if (!exists) {
            if (size > 2) {
                vector<string> prereq;
                for (int i = 2; i < size; i++) {
                    prereq.push_back(tokens[i]);
                }
                prereqs.push_back(prereq);
                courses.push_back(Course(tokens[0], tokens[1], prereq));
            }
            else {
                courses.push_back(Course(tokens[0], tokens[1]));
            }
        }
    }

    // Verify prerequisites
    bool valid;
    for (int i = 0; i < prereqs.size(); i++) {
        for (int j = 0; j < prereqs[i].size(); j++) {
            valid = false;
            for (auto course : courses) {
                if (course.readId() == prereqs[i][j]) valid = true;
            }
            if (!valid) {
                courses.erase(courses.begin() + i);
                break;
            }
        }
    }

    // Ensure course list is sorted alphanumerically
    mergeSort(courses, 0, courses.size() - 1);
}

void printAlphanumeric(vector<Course>& courses) {
    for (auto course : courses) {
        course.print();
        printf("\n");
    }
}

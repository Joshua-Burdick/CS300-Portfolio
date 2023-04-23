# CS300 Portfolio

## Repository Contents
### [ProjectStructureAnalsysis.docx](https://github.com/Joshua-Burdick/CS300-Portfolio/blob/master/ProjectStructureAnalysis.docx)
This document contains my runtime analysis of each component of the project and for each data structure from Project 1.

### [ProjectTwo Folder](https://github.com/Joshua-Burdick/CS300-Portfolio/tree/master/ProjectTwo)
This folder contains the necessary code from project two to read a vector of courses from a file, sort the list, and print it in alphanumeric order.

## Reflection Questions
1. What was the problem you were solving in the projects for this course?
2. How did you approach the problem? Consider why data structures are important to understand.
3. How did you overcome any roadblocks you encountered while going through the activities or project?
4. How has your work on this project expanded your approach to designing software and developing programs?
5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

### Answers
1. The problem being solved in the projects for this course was to create a system for ABCU to manage access to their course information. Project 1 focused on the pseudocode and overall design of this system, while Project 2 dealt with the implementation, including validating the entries in the input file and displaying course information to the user.
2. I appraoched the problem by first determining all of the important aspects and functions that the program needed to implement. This helped me to determine how to construct them in actual code, and assisted me in determining which data structure to use (I chose to implement a vector for Project 2).
3. I overcame my challenges with this project mostly through external research and a few pivots in my approaches. The hardest parts were splitting the strings and ensuring the courses were valid. After extensive research I found a method to split strings in C++ that worked for the purposes of this project; the validation of courses is the most inefficient part of the program due to validating all of the prerequisites at the end. This could possibly be improved through an implementation of Regex or an algorithm to cut down on the number of prerequisites to check to avoid collisions. However, for the purposes of this program, I elected to use a straightforward check which served the intention of the program.
4. My work on this project has expanded my approach to designing software and developing programs by helping me work on building out my ability to dissect a problem statement and construct a viable solution from it. It also helped my ability to turn plans into functional code, through having to take the pseudocode from Project 1 and turn it into a functional program in Program 2.
5. My work on this project helped me in learning to implement a variety of functions and algorithms to accomplish the goal of the project. For example, determining how to split the strings from the file, and using merge sort in a full project to sort a list of Course objects. It was helpful to understanding how to implement many moving pieces together to create an end product.

#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>


//Accessors methods implementations
std::string Student::getStudentID() {
    return studentID;
}

std::string Student::getFirstName() {
    return fName;
}

std::string Student::getLastName() {
    return lName;
}

std::string Student::getEmailAddress() {
    return email;
}

int Student::getAge() {
    return age;
}

int* Student::getDaysFinishCourses() {
    return daysFinishCourses;
}

DegreeProgram Student::getDegreeProgram() {
    return degree;
}


// Mutators method implementations
void Student::setStudentID(std::string modifystudentID) {
    studentID = modifystudentID;
}

void Student::setFirstName(std::string modifyfName) {
    fName = modifyfName;
}

void Student::setLastName(std::string modifylName) {
    lName = modifylName;
}

void Student::setEmailAddress(std::string modifyemail) {
    email = modifyemail;
}

void Student::setAge(int modifyage) {
    age = modifyage;
}

void Student::setDaysFinishCourses(int modifydaysFinishCourses[3]) {
    for (int i = 0; i < 3; ++i) {
        daysFinishCourses[i] = modifydaysFinishCourses[i];
    }
}

void Student::setDegreeProgram(DegreeProgram modifydegree) {
    degree = modifydegree;
}

// Print student data
void Student::print() {
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "First Name: " << fName << std::endl;
    std::cout << "Last Name: " << lName << std::endl;
    std::cout << "Email Address: " << email << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Days to Complete Courses: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << daysFinishCourses[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Degree Program: " << degree << std::endl;
}

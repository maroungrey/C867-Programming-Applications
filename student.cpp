#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>


Student::Student()
{
    this->studentID = "";
    this->fName = "";
    this->lName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysInCourse; ++i) this->courses[i] = 0;
    this->degree = DegreeProgram::SECURITY;
}


Student::Student(std::string studentID, std::string fName, std::string lName, std::string email, int age, int courses[], DegreeProgram degree)
{
    this->studentID = studentID;
    this->fName = fName;
    this->lName = lName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysInCourse; ++i) this->courses[i] = courses[i];
    this->degree = degree;
}


//Accessors
std::string Student::getStudentID() {
    return this->studentID;
}

std::string Student::getFirstName() {
    return this->fName;
}

std::string Student::getLastName() {
    return this->lName;
}

std::string Student::getEmailAddress() {
    return this->email;
}

int Student::getAge() {
    return this->age;
}

int* Student::getCoursesFinishDate() {
    return this->courses;
}

DegreeProgram Student::getDegreeProgram() {
    return degree;
}


// Mutators
void Student::setStudentID(std::string ID) {
    this->studentID = ID;
}

void Student::setFirstName(std::string fName) {
    this->fName = fName;
}

void Student::setLastName(std::string lName) {
    this->lName = lName;
}

void Student::setEmailAddress(std::string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setCoursesFinishDate(int courses[]) {
    for (int i = 0; i < daysInCourse; i++) this->courses[i] = courses[i];
}

void Student::setDegreeProgram(DegreeProgram degree) {
    degree = degree;
}

// Print student data
void Student::printHeader() {
    std::cout << "Output format: ID|Title|Author|Prices|Type\n";
}


void Student::print() {
    std::cout << this->getStudentID() << '\t';
    std::cout << this->getFirstName() << '\t';
    std::cout << this->getLastName() << '\t';
    std::cout << this->getEmailAddress() << '\t';
    std::cout << this->getAge() << '\t';
    std::cout << this->getCoursesFinishDate()[0] << ',';
    std::cout << this->getCoursesFinishDate()[1] << ',';
    std::cout << this->getCoursesFinishDate()[2] << '\t';
    std::cout << DegreeProgramStrings[this->getDegreeProgram()] << '\n';
}

//destructor
Student::~Student() {}
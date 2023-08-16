#pragma once
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>


class Student {
public:
    const static int daysInCourse = 3;
private:
	std::string studentID;
	std::string fName;
	std::string lName;
	std::string email;
	int age;
	int courses[daysInCourse];
	DegreeProgram degree;
public:
    //Constructor declaration
    Student();
    Student(std::string studentID, std::string fName, std::string lName, std::string email, int age, int courses[], DegreeProgram degree);
    ~Student();

    // Accessors
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getCoursesFinishDate();
    DegreeProgram getDegreeProgram();
    
    // Mutators
    void setStudentID(std::string ID);
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setEmailAddress(std::string email);
    void setAge(int age);
    void setCoursesFinishDate(int courses[]);
    void setDegreeProgram(DegreeProgram degree);

    static void printHeader();

    void print(); 

};

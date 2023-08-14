#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"

#include <string>


class Student {
private:
	std::string studentID;
	std::string fName;
	std::string lName;
	std::string email;
	int age;
	int daysFinishCourses[3];
	DegreeProgram degree;

public:
    //Constructor declaration
    Student(std::string studentID, std::string fName, std::string lName, std::string email, int  age, int daysFinishCourses[3], DegreeProgram degree) {
        this->studentID = studentID;
        this->fName = fName;
        this->lName = lName;
        this->email = email;
        this->age = age;
        for (int i = 0; i < 3; ++i) {
            this->daysFinishCourses[i] = daysFinishCourses[i];
        }
        this->degree = degree;
    }

    // Accessors methods declarations
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getDaysFinishCourses();
    DegreeProgram getDegreeProgram();

    // Mutators methods declarations
    void setStudentID(std::string modifystudentID);
    void setFirstName(std::string modifyfName);
    void setLastName(std::string modifylName);
    void setEmailAddress(std::string modifyemail);
    void setAge(int modifyage);
    void setDaysToCompleteCourses(int modifydaysFinishCourses[3]);
    void setDegreeProgram(DegreeProgram modifydegree);

    // Print student data
    void print();

};


#endif
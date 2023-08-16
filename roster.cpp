#include "roster.h"
#include <iostream>
#include <string>


void Roster::parse(std::string studentdata) {

    int rhs = studentdata.find(',');
    std::string studentID = studentdata.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    std::string firstName = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    std::string lastName = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    std::string emailAddress = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourses1 = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourses2 = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourses3 = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);

    DegreeProgram degreeProgram = SECURITY;

    if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') degreeProgram = SECURITY;
    else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') degreeProgram = SOFTWARE;
    else if (studentdata.at(lhs) == 'N') degreeProgram = NETWORK;

    add(studentID, firstName, lastName, emailAddress, age, daysInCourses1, daysInCourses2, daysInCourses3, degreeProgram);

}

//add method combines strings and creates obj in roster
void Roster::add(std::string studentID, std::string fName, std::string lName, std::string email, int age, int daysInCourses1, int daysInCourses2, int daysInCourses3, DegreeProgram degreeProgram) {
    int daysArr[3] = { daysInCourses1, daysInCourses2, daysInCourses3 };
    classRosterArray[++lastIndex] = new Student(studentID, fName, lName, email, age, daysArr, degreeProgram);//use full constructor
}

//display all students using tab delimited output
void Roster::printAll() {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        std::cout << classRosterArray[i]->getStudentID(); std::cout << '\t';
        std::cout << classRosterArray[i]->getFirstName(); std::cout << '\t';
        std::cout << classRosterArray[i]->getLastName(); std::cout << '\t';
        std::cout << classRosterArray[i]->getEmailAddress(); std::cout << '\t';
        std::cout << classRosterArray[i]->getAge(); std::cout << '\t';
        std::cout << classRosterArray[i]->getCoursesFinishDate()[0]; std::cout << '\t';
        std::cout << classRosterArray[i]->getCoursesFinishDate()[1]; std::cout << '\t';
        std::cout << classRosterArray[i]->getCoursesFinishDate()[2]; std::cout << '\t';
        std::cout << DegreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
    }
}

//display students with matching degree
void Roster::printByDegreeProgram(DegreeProgram degree) {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degree) classRosterArray[i]->print();
    }
    std::cout << std::endl;
}


void Roster::printInvalidEmails() {
    bool invalidEmail = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        std::string email = (classRosterArray[i]->getEmailAddress());
        if ((email.find("@") == std::string::npos) && (email.find(" ") != std::string::npos) && (email.find(".") == std::string::npos)) {
           invalidEmail = true;
           std::cout << email << ": " << classRosterArray[i]->getFirstName() << std::endl;
        }
    }
    if (!invalidEmail) std::cout << "NONE" << std::endl;
}


void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            std::cout << studentID << ":";
            std::cout << (classRosterArray[i]->getCoursesFinishDate()[0] +
                classRosterArray[i]->getCoursesFinishDate()[1] +
                classRosterArray[i]->getCoursesFinishDate()[2]) / 3 << std::endl;
        }
    }
}



void Roster::removeStudentByID(std::string studentID) {
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success) {
        std::cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();
    }
    else std::cout << studentID << " not found." << std::endl << std::endl;;
}

Roster::~Roster()
{
    std::cout << "Destructor called!" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        std::cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}


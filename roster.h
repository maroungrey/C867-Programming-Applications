#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(std::string row);
	void add(std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int daysInCourses1,
		int daysInCourses2,
		int daysInCourses3,
		DegreeProgram degreeProgram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse(std::string studentID);
	void removeStudentByID(std::string studentID);
	
	~Roster(); //destructor
};

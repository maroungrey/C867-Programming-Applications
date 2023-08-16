#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Scripting and Programming Applications - C867" << std::endl;
	cout << "Written in C++" << std::endl;
	cout << "By: Maroun Barqawi Student ID - 010309427" << std::endl;
	cout << std::endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Maroun,Barqawi,mbarqa1@wgu.edu,24,20,30,40,SOFTWARE"

	};
	int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Displaying students with Invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	//loop through classRosterArray and for each element:
	cout << "Displaying average days: " << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << std::endl;


	cout << "Displaying Students in the Software program: " << std::endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << std::endl;

	cout << "Removing student with ID A3:" << std::endl;
	classRoster.removeStudentByID("A3");
	cout << std::endl;

	cout << "Student with ID A3 not found:" << std::endl;
	classRoster.removeStudentByID("A3");
	cout << std::endl;

	system("pause");

	return 0;

}
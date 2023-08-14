#include "student.h"
#include <iostream>

int main() {
    // Create a Student object
    int courseDays[3] = { 90, 85, 95 };
    Student student("123", "John", "Doe", "john@example.com", 20, courseDays, DegreeProgram::SECURITY);

    // Display student information using accessor methods
    std::cout << "Initial Student Information:\n";
    student.print();

    // Use mutator methods to update student information
    student.setAge(21);
    student.setEmailAddress("updated@example.com");

    int newDays[3] = { 80, 75, 88 };
    student.setDaysFinishCourses(newDays);

    student.setDegreeProgram(DegreeProgram::SOFTWARE);

    // Display updated student information
    std::cout << "\nUpdated Student Information:\n";
    student.print();

    return 0;
}

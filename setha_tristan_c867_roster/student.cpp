#include <iostream>
#include "student.h"

// CONSTRUCTOR
Student::Student()
{
  this->studentID = "";
  this->firstName = "";
  this->lastName = "";
  this->email = "";
  this->age = 0;
  for (int i = 0; i < daysInCoursesSize; i++)
  {
    this->daysInCourses[i] = 0;
  }
  // Default DegreeProgram value
  this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID,
                 string firstName,
                 string lastName,
                 string email,
                 int age,
                 int daysInCourse[],
                 DegreeProgram degreeProgram)
{
  this->studentID = studentID;
  this->firstName = firstName;
  this->lastName = lastName;
  this->email = email;
  this->age = age;
  for (int i = 0; i < daysInCoursesSize; i++)
    this->daysInCourses[i] = daysInCourse[i];
  this->degreeProgram = degreeProgram;
}

// DESTRUCTOR
Student::~Student() {}

// Getters
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int *Student::getDaysInCourses() { return this->daysInCourses; }
DegreeProgram Student::getDegreeProgram()
{
  return this->degreeProgram;
}

// Setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourses(int daysInCourses[])
{
  for (int i = 0; i < daysInCoursesSize; i++)
    this->daysInCourses[i] = daysInCourses[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
  this->degreeProgram = degreeProgram;
}

void Student::print()
{
  std::cout << studentID << "\t"
            << "First Name: " << firstName << "\t"
            << "Last Name: " << lastName << "\t"
            << "Age: " << age << "\t"
            << "daysInCourse: {" << daysInCourses[0] << ", " << daysInCourses[1] << ", " << daysInCourses[2] << "}\t"
            << "Degree Program: " << degreeString[static_cast<int>(getDegreeProgram())]
            << std::endl;
}
#include <iostream>
#include <string>
#include "roster.h"

Roster::~Roster() = default;

void Roster::add(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram)
{
  int daysArray[3] = {
      daysInCourse1,
      daysInCourse2,
      daysInCourse3};
  classRosterArray[++lastIndex] = new Student(
      studentID,
      firstName,
      lastName,
      emailAddress,
      age,
      daysArray,
      degreeProgram);
}

void Roster::remove(string studentID)
{
}

void Roster::printAll()
{
  // c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
  for (int i = 0; i <= lastIndex; i++)
  {
    classRosterArray[i]->print();
  }
}

void Roster::printAverageDaysInCourse(string studentID)
{
  for (int i = 0; i <= lastIndex; i++)
  {
    if (classRosterArray[i]->getStudentID() == studentID)
    {
      int *days = classRosterArray[i]->getDaysInCourses();
      cout << "Student ID: " << studentID << " average days in course is "
           << (days[0] + days[1] + days[2]) / 3.0 << endl;
      return;
    }
  }
}

void Roster::printInvalidEmails()
{
  for (int i = 0; i <= lastIndex; i++)
  {
    string email = classRosterArray[i]->getEmail();
    if (email.find('@') == string::npos ||
        email.find('.') == string::npos ||
        email.find(' ') != string::npos)
    {
      cout << "Invalid email: " << email << endl;
    }
  }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
}

Student *Roster::getStudentAt(int index)
{
  return classRosterArray[index];
}

void Roster::parse(string studentData)
{

  int rhs = studentData.find(",");
  string studentID = studentData.substr(0, rhs);

  int lhs = rhs + 1;
  rhs = studentData.find(",", lhs);

  string firstName = studentData.substr(lhs, rhs - lhs);

  lhs = rhs + 1;
  rhs = studentData.find(",", lhs);
  string lastName = studentData.substr(lhs, rhs - lhs);

  lhs = rhs + 1;
  rhs = studentData.find(",", lhs);
  string email = studentData.substr(lhs, rhs - lhs);

  lhs = rhs + 1;
  rhs = studentData.find(",", lhs);
  int age = stoi(studentData.substr(lhs, rhs - lhs));

  lhs = rhs + 1;
  rhs = studentData.find(",", lhs);
  int days1 = stoi(studentData.substr(lhs, rhs - lhs));

  lhs = rhs + 1;
  rhs = studentData.find(",", lhs);
  int days2 = stoi(studentData.substr(lhs, rhs - lhs));

  lhs = rhs + 1;
  rhs = studentData.find(",", lhs);
  int days3 = stoi(studentData.substr(lhs, rhs - lhs));

  lhs = rhs + 1;
  string degreeStr = studentData.substr(lhs);
  DegreeProgram degree = DegreeProgram::SOFTWARE;
  if (degreeStr == "SECURITY")
    degree = DegreeProgram::SECURITY;
  else if (degreeStr == "NETWORK")
    degree = DegreeProgram::NETWORK;
  Roster::add(studentID, firstName, lastName, email, age,
              days1, days2, days3, degree);
}
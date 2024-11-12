#pragma once
#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

Roster::Roster()
{
}

Roster::~Roster()
{
}

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
}

void Roster::printAverageDaysInCourse(string studentID)
{
}

void Roster::printInvalidEmails()
{
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
  // Parse each string
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
#pragma once
#include "student.h"

class Roster
{
private:
  const static int numberOfStudents = 5;

  // Tracks the last student added
  int lastIndex;

  // Array of pointers to students
  Student *classRosterArray[numberOfStudents];

public:
  Roster();
  ~Roster();
  void add(string studentID,
           string firstName,
           string lastName,
           string emailAddress,
           int age,
           int daysInCourse1,
           int daysInCourse2,
           int daysInCourse3,
           DegreeProgram degreeProgram);
  void remove(string studentID);
  void printAll();
  void printAverageDaysInCourse(string studentID);
  void printInvalidEmails();
  void printByDegreeProgram(DegreeProgram degreeProgram);

  Student *getStudentAt(int index);

  void parse(const string studentData);
};
#pragma once
#include "degree.h"
#include <string>
using namespace std;

class Student
{
public:
  const static int daysInCoursesSize;
private:
  string studentID;
  string firstName;
  string lastName;
  string email;
  int age;
  int daysInCourses[3];
  DegreeProgram degreeProgram;

public:
  Student();
  Student(string studentID,
          string firstName,
          string lastName,
          string email,
          int age,
          int daysInCourse[],
          DegreeProgram degreeProgram);
  // Destructor
  ~Student();

  string getStudentID();
  string getFirstName();
  string getLastName();
  string getEmail();
  int getAge();
  int *getDaysInCourses();
  DegreeProgram getDegreeProgram();

  void setStudentID(string studentID);
  void setFirstName(string firstName);
  void setLastName(string lastName);
  void setEmail(string email);
  void setAge(int age);
  void setDaysInCourses(int daysInCourses[]);
  void setDegreeProgram(DegreeProgram degreeProgram);

  static void printHeader();

  void print();
};
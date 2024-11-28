#pragma once
#include "degree.h"
#include <string>
using namespace std;

class Student
{
public:
  const static int daysInCoursesSize = 3;
private:
  string studentID;
  string firstName;
  string lastName;
  string email;
  int age;
  int daysInCourses[3];
  DegreeProgram degreeProgram;

public:
  // DEFAULT CONSTRUCTOR
  Student();
  // CONSTRUCTOR
  Student(string studentID,
          string firstName,
          string lastName,
          string email,
          int age,
          int daysInCourse[],
          DegreeProgram degreeProgram);
  // DESTRUCTOR
  ~Student();
  // GETTERS
  string getStudentID();
  string getFirstName();
  string getLastName();
  string getEmail();
  int getAge();
  int *getDaysInCourses();
  DegreeProgram getDegreeProgram();
  // SETTERS
  void setStudentID(string studentID);
  void setFirstName(string firstName);
  void setLastName(string lastName);
  void setEmail(string email);
  void setAge(int age);
  void setDaysInCourses(int daysInCourses[]);
  void setDegreeProgram(DegreeProgram degreeProgram);

  void print();
};
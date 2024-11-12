// main.cpp
#include <iostream>
#include <string>
#include "roster.h"

int main()
{

  Roster classRoster;
  // Print program information
  cout << "Course Title: Scripting and Programming - Applications (C867)" << endl;
  cout << "Programming Language: C++" << endl;
  cout << "WGU Student ID: [Your ID]" << endl;
  cout << "Name: Tristan Setha" << endl

       << endl;

  // Student data (add your information as the last item)
  const string studentData[] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Tristan,Setha,tristansetha@gmail.com,31,40,30,15,SOFTWARE"};
  const int studentDataSize = 5;

  for (int i = 0; i < studentDataSize; i++)
  {
    classRoster.parse(studentData[i]);
  }

  classRoster.printAll();

  classRoster.printInvalidEmails();

  // Print average days in course for each student
  for (int i = 0; i < studentDataSize; i++)
  {
    Student *student = classRoster.getStudentAt(i);
    classRoster.printAverageDaysInCourse(student->getStudentID());
  }
  cout << "\n";
  cout << "Degree program SOFTWARE: \n";
  classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
  cout << "\n";

  classRoster.remove("A3");
  cout << "\n";
  classRoster.printAll();
  cout << "\n";
  classRoster.remove("A3");
}

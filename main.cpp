#include <iostream>
#include <string>
#include "roster.h"

int main()
{

  Roster classRoster;
  // PRINT PROGRAM INFORMATION
  cout << "\n";
  cout << "Course Title: Scripting and Programming - Applications (C867)" << endl;
  cout << "Programming Language: C++" << endl;
  cout << "WGU Student ID: 012068201" << endl;
  cout << "Name: Tristan Setha" << endl

       << endl;

  // STUDENT DATA
  const string studentData[] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Tristan,Setha,tsetha@wgu.edu,31,40,30,15,SOFTWARE"};

  // STUDENT DATA SIZE CONSTANT
  const int studentDataSize = 5;

  // PARSE AND ADD TO classRosterArray
  for (int i = 0; i < studentDataSize; i++)
  {
    classRoster.parse(studentData[i]);
  }

  // PRINT TAB SEPERATED LIST OF STUDENT DATA
  cout << "STUDENT DATA: \n";
  classRoster.printAll();
  // PRINT INVALID EMAILS
  cout << "\n";

  cout << "INVALID EMAILS: \n";

  classRoster.printInvalidEmails();
  cout << "\n";

  // PRINT AVERAGE DAYS IN COURSE FOR EACH STUDENT
  cout << "AVERAGE DAYS IN COURSE FOR EACH STUDENT: \n";
  for (int i = 0; i < studentDataSize; i++)
  {
    Student *student = classRoster.getStudentAt(i);
    classRoster.printAverageDaysInCourse(student->getStudentID());
  }
  cout << "\n";
  // PRINT STUDENTS WITHIN SOFTWARE DEGREE PROGRAM
  cout << "Students by degree program SOFTWARE: \n";
  classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
  cout << "\n";

  // REMOVE A3
  classRoster.remove("A3");
  cout << "\n";
  cout << "STUDENT DATA: \n";
  classRoster.printAll();
  cout << "\n";
  // SHOULD RETURN '<student-id> not found'
  classRoster.remove("A3");
}

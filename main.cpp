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
}

// F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:

// 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

// 2.  Create an instance of the Roster class called classRoster.

// 3.  Add each student to classRoster.

// 4.  Convert the following pseudo code to complete the rest of the  main() function:

// classRoster.printAll();
// c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.


//TODO:
// classRoster.printInvalidEmails();

// //loop through classRosterArray and for each element:

// classRoster.printAverageDaysInCourse(/*current_object's student id*/);

// Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.

// classRoster.printByDegreeProgram(SOFTWARE);

// classRoster.remove("A3");

// classRoster.printAll();

// classRoster.remove("A3");

// //expected: the above line should print a message saying such a student with this ID was not found.

// 5.  Implement the destructor to release the memory that was allocated dynamically in Roster.

// G.  Demonstrate professional communication in the content and presentation of your submission.
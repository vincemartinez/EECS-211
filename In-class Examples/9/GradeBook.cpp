

#include <iostream>
#include "GradeBook.h"

using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
   setCourseName( name ); // validate and store courseName
}

// function that sets the course name;
// ensures that the course name has at most 25 characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 25 ) // if name has 25 or fewer characters
      courseName = name; // store the course name in the object

   if ( name.size() > 25 ) // if name has more than 25 characters
   { 
      // set courseName to first 25 characters of parameter name
      courseName = name.substr( 0, 25 ); // start at 0, length of 25

      cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
         << "Limiting courseName to first 25 characters.\n" << endl;
   } // end if
}

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName to get the courseName
   cout << "Welcome to the grade book for\n" << getCourseName()  
      << "!" << endl;
}
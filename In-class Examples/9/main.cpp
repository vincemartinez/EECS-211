
#include <iostream>
#include <iomanip>
#include <string>

#include "CashRegister.h"
#include "GradeBook.h"
#include "Product.h"

using namespace std;


int main() {
    
    /*
    //Example 1: stuff you can do with strings:)
    string mystring = "hi there wildcats!";
    cout << "example a: " << mystring << endl;
    cout << "example b: " << mystring.substr(9, 8) << endl;
    mystring[13] = 'b'; //can assign to an index
    cout << "example c: " << mystring << endl;
    
    //we can have a string of numbers
    string mynumber = "547";
    //we can get one of the digits
    char firstDigitChar = mynumber[0];
    cout << "example d: " << firstDigitChar << endl;
    //but its very important to remember that the digit is a char, not a number
    int myvalue = firstDigitChar * 100;
    cout << "example e: " << myvalue << endl; //what will this print out??
    
    //firstDigitChar is a char but we need a number
    int firstDigitNum = firstDigitChar - '0';
    int value = firstDigitNum * 100;
    cout << "example f: " << value << endl;
    */
    
    /*
    //EXAMPLE 2
    // Rather than replicate these name, price and score variables for each
    //    product, it makes sense to group them together into the concept of a
    //    product. Product will be a class, it holds some data members,
    //    the name, price and score of a product. It includes some member
    //    functions to read a product from the user, print out the product info,
    //    and compare the value of a product to that of another product.
    // Try breakpoint on first if line
    
    Product best; // invoke constructor
    
    bool more = true;
    while (more) {
        Product next; // invoke constructor
        next.read();  // get values from user
        if (next.is_better_than(best))
            best = next;
        cout << "More data? (y/n) ";
        string answer;
        getline(cin, answer);
        if (answer != "y")
            more = false;
    }
    cout << "The best value is " << endl;
    best.print(); cout << "\n";
    */

    /*
    //Example 3: cash register
    CashRegister register1;
    register1.clear();
    register1.add_item(1.95);
    register1.display();
    register1.add_item(0.95);
    register1.display();
    register1.add_item(2.50);
    register1.display();
    register1.add_items(100, 1.0);
    register1.display();
    */
     
    /*
    //Example 4 (from book): grade book
    // create two GradeBook objects;
    // initial course name of gradeBook1 is too long
    GradeBook gradeBook1( "CS101 Introduction to Programming in C++" );
    GradeBook gradeBook2( "CS102 C++ Data Structures" );
    
    // display each GradeBook's courseName
    cout << "gradeBook1's initial course name is: "
    << gradeBook1.getCourseName()
    << "\ngradeBook2's initial course name is: "
    << gradeBook2.getCourseName() << endl;
    
    // modify gradeBook1's courseName (with a valid-length string)
    gradeBook1.setCourseName( "CS101 C++ Programming" );
    
    // display each GradeBook's courseName
    cout << "\ngradeBook1's course name is: "
    << gradeBook1.getCourseName()
    << "\ngradeBook2's course name is: "
    << gradeBook2.getCourseName() << endl;
    */
}

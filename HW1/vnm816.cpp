/*
 
 Averaging program with input from a file or keyboard.
 Author:  your name
 EECS 211, Spring 2015, Program 1
 
 Input file contains test scores for 1 or more students. 
 For each student, it gives the following data in this order:
 *N (the number of scores for the student)
 *N numbers separated by spaces (the scores for the student)
 *a number to indicate if there are more students in the lines that follow. 
    Specifically, -1 (there is another set) or -2 (end of data)
*/

#include <iostream> //to use cin and cout
#include <fstream>  //to get input from a file
using namespace std;

// Set the following constant to 1 for input from the keyboard,
// 0 for input from file.
const int MODE = 0;

// This is the input file for when MODE is 0.
//   It is declared at the file level becuase it is
//   used within both functions.
ifstream in_file;

int get_one_number(int src) {
    // Gets the next integer from the input.  If src is
    // 0, then read from the file opened in the main function,
    // otherwise read from the keyboard.
    
    int val;
    
    if(src) {
        // Input from keyboard.
        cout << "Enter the next input: ";
        cin >> val;
    }
    else {
        // Input from file.
        in_file >> val;
    }
    
    return val;
}

int main() {
	// Your variables go here.  Be sure to include an int called more.
	int more = 0;
	int number_of_exams = 0;
	int student_number = 1;
	int total_scores=0;
	int reading=0;
	int average=0;
	int invalid_scores=0;
	int GradeRead = 1;
	int ThisStudent = 1;


	if (MODE == 0) {
		in_file.open("p1input.txt", ios::in);
		if (in_file.fail()) {
			cout << "Could not open input file.  Program terminating.\n\nEnter an integer to quit.";
			cin >> more;
			return 0;
		}
	}

	while (GradeRead){

		number_of_exams = get_one_number(MODE);

		while (ThisStudent){
			
			reading = get_one_number(MODE);

			if (reading == -1){
				average = total_scores / number_of_exams;
				//print statements
				ThisStudent = !ThisStudent;
			}

			if (reading < 0 || reading>100){
				reading = 0;
				number_of_exams--;
				invalid_scores++;
			}

			if (reading == -2){
				cout << "End of students.  Enter an integer to quit.";
				cin >> more;
				ThisStudent = !ThisStudent;
				GradeRead = !GradeRead;
			}

			total_scores += reading;

		}

		student_number++;

	}

			

    // The rest of your code goes here.
    
    
    return 0;
}

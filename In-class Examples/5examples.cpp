#include <iostream>
#include <string>
using namespace std;

//VVDocumenter - for XCode
//http://www.raywenderlich.com/66395/documenting-in-xcode-with-headerdoc-tutorial
// /// to start a doc
// option+click over function name to show docs

/**
 *  Computes the volume of a cube.
 *
 *  @param side_length the side length of the cube
 *
 *  @return the volume
 */
double cube_volume(double side_length)
{
    double volume = side_length * side_length * side_length;
    return volume;
}

/**
 *  Writes the input string with the wrap-format around it.
 *
 *  @param str the string to format
 */
void box_string(string str)
{
    long n = str.length();
    if ( n != 0 )
    {
        for (int i = 0; i < n + 2; i++)
            cout << "-";
        cout << endl;
        cout << "!" << str << "!" << endl;
        for (int i = 0; i < n + 2; i++)
            cout << "-";
        cout << endl;
    }
        
    return; //return without a value is acceptable but not necessary (void)
}

//stubs
string digit_name(int digit)
{
    return "mumble";
}

string teens_name(int number)
{
    return "mumbleteen";
}

string tens_name(int number)
{
    return "mumblety";
}

///**
// *  Turns a digit into its English name.
// *
// *  @param digit an integer between 1 and 9
// *
// *  @return the name of digit ("one" ... "nine")
// */
//string digit_name(int digit)
//{
//    if (digit == 1) return "one";
//    if (digit == 2) return "two";
//    if (digit == 3) return "three";
//    if (digit == 4) return "four";
//    if (digit == 5) return "five";
//    if (digit == 6) return "six";
//    if (digit == 7) return "seven";
//    if (digit == 8) return "eight";
//    if (digit == 9) return "nine";
//    return "";
//}
//
///**
// *  Turns a number between 10 and 19 into its English name.
// *
// *  @param number an integer between 10 and 19
// *
// *  @return the name of the given number ("ten" ... "nineteen")
// */
//string teens_name(int number)
//{
//    if (number == 10) return "ten";
//    if (number == 11) return "eleven";
//    if (number == 12) return "twelve";
//    if (number == 13) return "thirteen";
//    if (number == 14) return "fourteen";
//    if (number == 15) return "fifteen";
//    if (number == 16) return "sixteen";
//    if (number == 17) return "seventeen";
//    if (number == 18) return "eighteen";
//    if (number == 19) return "nineteen";
//    return "";
//}
//
///**
// *  Gives the name of the tens part of a number between 20 and 99.
// *
// *  @param number an integer between 20 and 99
// *
// *  @return the name of the tens part of the number ("twenty" ... "ninety")
// */
//string tens_name(int number)
//{
//    if (number == 9) return "ninety";
//    if (number == 8) return "eighty";
//    if (number == 7) return "seventy";
//    if (number == 6) return "sixty";
//    if (number == 5) return "fifty";
//    if (number == 4) return "forty";
//    if (number == 3) return "thirty";
//    if (number == 2) return "twenty";
//    return "";
//}

/**
 *  Turns a number into its English name.
 *
 *  @param number a positive integer < 1,000
 *
 *  @return the name of the number (e.g. "two hundred seventy four")
 */
string int_name(int number)
{
    int part = number; // The part that still needs to be converted
    string name; // The return value
    
    if (part >= 100) //its a 3 digit number
    {
        name = digit_name(part / 100) + " hundred";
        part = part % 100;
    }
    if (part >= 20) //its a 2 digit number but not a teen
    {
        name = name + " " + tens_name(part / 10);
        part = part % 10;
    }
    else if (part >= 10)  //its a teens number
    {
        name = name + " " + teens_name(part);
        part = 0;
    }
    
    if (part > 0) //its a single digit number
    {
        name = name + " " + digit_name(part);
    }
    
    return name;
}

/**
 *  Withdraws the amount from the given balance, or withdraws a penalty
 *  if the balance is insufficient.
 *
 *  @param balance the balance from which to make the withdrawal
 *  @param amount  the amount to withdraw
 */
void withdraw(double& balance, double amount)
{
    const int PENALTY = 10;
    if (balance >= amount)
    {
        balance = balance - amount;
    }
    else
    {
        balance = balance - PENALTY;
    }
}

/**
 *  calculates the volume of the input cube
 *
 *  @param side_length the length of a side
 *  @param volume a double ref
 */
void cube_volume2(double side_length, double& volume)
{
    volume = side_length * side_length * side_length;
}

/**
 *  Swaps the values of the two variables.
 *
 *  @param x int ref
 *  @param y int ref
 */
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

/**
 *  adds a number of students to the group size
 *
 *  @param num_to_add the number of students to add
 */
void add_to_group(int num_to_add)
{
    static int group_size = 0;
    //don't need to initialize bc automatically set to 0
    // =0 above is redundant.
    group_size += num_to_add;
    cout << "group size is now: " << group_size << endl;
}


/**
 *  print as many “*”s in a given line, as is the line number
 *  (i.e., print a “triangle”).
 *
 *  @param num_lines the number of lines desired
 */
void print_UDtriangle (int num_lines)
{
    if (num_lines == 0)
    {
        return;
    }
    else
    {
        for (int i=0 ; i < num_lines; i++)
        {
            cout << "*" <<" ";
        }
        cout << endl;
        print_UDtriangle(num_lines - 1);
    }
}

/**
 *  Calculates n!
 *
 *  @param n the input value
 *
 *  @return n!
 */
int factorial (int n)
{
    //assume n is valid
    if (n <= 1)
        return 1;
    else
        return   n * factorial(n-1);
}


int main()
{
    /*
    //Example 1 - Functions - scope, pass by value
    double result1 = cube_volume(2);
    double result2 = cube_volume(10);
    cout << "A cube with side length 2 has volume " << result1 << endl;
    cout << "A cube with side length 10 has volume " << result2 << endl;
    */
    
    /*
    //Example 2 - void return type
    box_string("hello there class");
    */
     
    
    /*
    //Example 3 - helper functions and stubs (switch to full defs after)
    cout << "Please enter a positive integer: ";
    int input;
    cin >> input;
    cout << int_name(input) << endl;
    */
    
    /*
    //Example 4 - reference parameters
    double harrys_account = 1000;
    double sallys_account = 500;
    withdraw(harrys_account, 100);
    // Now harrys_account is 900
    withdraw(harrys_account, 1000); // Insufficient funds
    // Now harrys_account is 890
    withdraw(sallys_account, 150);
    // Now sallys_accoutn is 350
    cout << "Harry's account: " << harrys_account << endl;
    cout << "Sally's account: " << sallys_account << endl;
    */
    
    
    /*
    //Example 5 - bad use of reference parameters
    //some programmers like to use reference parameters just to get the
    //    return values of functions
    double vol;

    //overall, not a good idea
    //bc cannot do the following line
    //  the return type is void
    //double x = cube_volume2(2, vol);

    cube_volume2(2, vol);
    cout << "vol is: " << vol << endl;
    */
    
    /*
    //Example 6 - a good use of reference parameters
    //  we need to return more than 1 value
    int a = 4;
    int b = 7;
    cout << "before swapping, a is: " << a << endl;
    cout << "before swapping, b is: " << b << endl;
    swap(a, b);
    cout << "after swapping, a is: " << a << endl;
    cout << "after swapping, b is: " << b << endl;
    */
    
    /*
    //Example 7 - static local variables
    //a static local variable is only initialized ONCE, when it is declared
    //static local variables retain their values when the function returns to
    //   its caller
    add_to_group(2);
    add_to_group(3);
    add_to_group(7);
    */
    
    /*
    //Example 8 - recursion
    print_UDtriangle(5);
    int fivefactorial = factorial(5);
    cout << "five factorial is: " << fivefactorial << endl;
    */
    
}

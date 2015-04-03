#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    
     //EXAMPLE 1 - printing "hello world!"
     cout << "Hello World! \n";
     
    
    
     //EXAMPLE 2 - some simple addition
     int number1 = 0;
     int number2 = 0;
     int sum = 0;
     
     //an alternative
     //int number1 = 0, number2 = 0, sum = 0;
     
     cout << "enter number 1:\n";
     cin >> number1;
    
     number1 = number1 + 1;
        //number1++;
     
     cout << "enter number 2:\n";
     cin >> number2;
     number2++;
    
     sum = number1 + number2;
     
     cout << "sum is: " << sum << endl;
    

    /*
    //EXAMPLE 3
    unsigned int min_unsignedint = numeric_limits<unsigned int>::min();
    unsigned int max_unsignedint = numeric_limits<unsigned int>::max();
    
    int size_of_unsignedint = sizeof(unsigned int);
    
    cout << "unsigned ints: \n";
    cout << "size: " << size_of_unsignedint << " bytes \n";
    cout << "min: " << min_unsignedint << "\n";
    cout << "max: " << max_unsignedint << "\n";
    
    //int and signed int are synonyms
    int min_int = numeric_limits<int>::min();
    int max_int = numeric_limits<int>::max();
    
    int size_of_int = sizeof(int);
    
    cout << "signed ints: \n";
    cout << "size: " << size_of_int << " bytes \n";
    cout << "min: " << min_int << "\n";
    cout << "max: " << max_int << "\n";
    
    unsigned long min_unsigned_long = numeric_limits<unsigned long>::min();
    unsigned long max_unsigned_long = numeric_limits<unsigned long>::max();
    
    int size_of_unsigned_long = sizeof(unsigned long);
    
    cout << "unsigned longs: \n";
    cout << "size: " << size_of_unsigned_long << " bytes \n";
    cout << "min: " << min_unsigned_long << "\n";
    cout << "max: " << max_unsigned_long << "\n";
    
    //long and signed long are synonyms
    long min_long = numeric_limits<long>::min();
    long max_long = numeric_limits<long>::max();
    
    int size_of_long = sizeof(long);
    
    cout << "signed longs: \n";
    cout << "size: " << size_of_long << " bytes \n";
    cout << "min: " << min_long << "\n";
    cout << "max: " << max_long << "\n";
    */
    
    /*
    //EXAMPLE 4- if/else if/else
    float richter;
    
    cout << "enter richter value: " << endl;
    cin >> richter;
    
    if (richter >= 8.0)
    {
        cout << "Most structures fall" << endl;
    }
    else if (richter >= 7.0)
    {
        cout << "Many buildings destroyed" << endl;
    }
    else if (richter >= 6.0)
    {
        cout << "Many buildings considerably damaged, some collapse" << endl;
    }
    else if (richter >= 4.5)
    {
        cout << "Damage to poorly constructed buildings" << endl;
    }
    else
    {
        cout << "No destruction of buildings" << endl;
    }
     */
    
    /*
    //EXAMPLE 5 - nested branches
    //taxes example
    const double RATE1 = 0.10;
    const double RATE2 = 0.25;
    const double RATE1_SINGLE_LIMIT = 32000;
    const double RATE1_MARRIED_LIMIT = 64000;
    
    double tax1 = 0;
    double tax2 = 0;
    
    double income;
    cout << "Please enter your income: ";
    cin >> income;
    
    cout << "Please enter s for single, m for married: ";
    string marital_status;
    cin >> marital_status;
    
    if (marital_status == "s")
    {
        if (income <= RATE1_SINGLE_LIMIT)
        {
            tax1 = RATE1 * income;
        }
        else
        {
            tax1 = RATE1 * RATE1_SINGLE_LIMIT;
            tax2 = RATE2 * (income - RATE1_SINGLE_LIMIT);
        }
    }
    else //you must be married then
    {
        if (income <= RATE1_MARRIED_LIMIT)
        {
            tax1 = RATE1 * income;
        }
        else
        {
            tax1 = RATE1 * RATE1_MARRIED_LIMIT;
            tax2 = RATE2 * (income - RATE1_MARRIED_LIMIT);
        }
    }
    
    double total_tax = tax1 + tax2;
    cout << "your total taxes to be paid: " << total_tax << endl;
     */
    
    /*
    //EXAMPLE 6 - dangling else
    //shipping example
    double shipping_charge = 5.00;
    
    string country = "";
    cout << "what country are you shipping to?"<< endl;
    cin>>country;
    string state = "";
    cout << "what state are you shipping to?"<<endl;
    cin>>state;
    
    // $5 inside continental U.S.
    if (country == "USA")
        if (state == "HI")
            shipping_charge = 10.00;		// Hawaii is more expensive
    else
        shipping_charge = 20.00;             // As are foreign shipments

    cout << "your shipping charge is: " << shipping_charge<<endl;
     */
    
    /*
    //EXAMPLE 7 - switch
    int digit;
    string digit_name;
    
    cout << "enter a digit" << endl;
    cin >> digit;
    
//    if (digit == 1)
//    {
//        digit_name = "one";
//    }
//    else if (digit == 2)
//    {
//        digit_name = "two";
//    }
//    else if (digit == 3)
//    {
//        digit_name = "three";
//    }
//    else
//    {
//        digit_name = "too large";
//    }
    
    
    switch (digit)
    {
        case 1:
            digit_name = "one";
            break;
        case 2:
            digit_name = "two";
            break;
        case 3:
            digit_name = "three";
            break;
        default:
            digit_name = "too large";
            break;
    }
    
    cout << digit_name << endl;
     */
    
    /*
    //EXAMPLE 8 - while
    //doubling investment problem
    const double RATE = 5;
    const double INITIAL_BALANCE = 10000;
    const double TARGET = 2 * INITIAL_BALANCE; //we want our money to double
    
    double balance = INITIAL_BALANCE;
    int year = 0;
    
    while (balance < TARGET)
    {
        year++;
        balance = balance * (1 + RATE / 100); //in parens should be 1.05
    }
    
    cout << "The investment doubled after " << year << " years." << endl;
     */
    
    /*
    //EXAMPLE 9 - more while examples
    int i = 5;
    while (i > 0)
    {
        cout << i << " ";
        i--;
    }
    cout << endl;
    
    //bug 1 (add semicolon after while line)
    //bug 2 (remove i--)
    
    //bug 3 - but really not an infinite loop
    //each step through the loop should be making the gap between
    //    your current state and completing the loop smaller
    //BUT it actually will complete when i becomes too big to be an int
    //Due to what is called “wrap around”, the previous loop will end.
    //At some point the value stored in the int variable gets to the largest
    //  positive integer that could possibly be represented on a given machine.
    //  When it is incremented past that, the value stored “wraps around” to be
    //  a negative number.
    //max int is 2147483647
    
    int q = 2147483640;
    while (q > 0)
    {
    cout << q << " ";
    q++;
    }
    cout << "q is: " << q << endl;
    cout << "hi" << endl;
    */
    
    /*
    //EXAMPLE 10 - for
    const double RATE2 = 5;
    const double INITIAL_BALANCE2 = 10000;
    double balance2 = INITIAL_BALANCE2;
    int nyears;
    
    cout << "Enter number of years: ";
    cin >> nyears;
    
    cout << fixed << setprecision(2);
    for (int year = 1; year <= nyears; year++)
    {
        balance2 = balance2 * (1 + RATE2 / 100);
        cout << setw(4) << year << setw(10) << balance2 << endl;
    }
     */
    
    /*
    //EXAMPLE 11 - Bug: WHAT? this compiles because all three pieces are valid
    //      statements!! but this is a ridiculous looking for loop
    int sum = 0;
    int count = 0;
    int x = 0;
    for (cout << "Inputs: "; cin >> x; sum += x)
    {
        count++;
    }
    */
    
    /*
    //EXAMPLE 12 - do while!
    //    goes through the loop at least once, even if the condition is not met
    int ct = 0;
    do {
        cout << "hi\n";
        ct ++;
    } while (ct < 5);
    */
}

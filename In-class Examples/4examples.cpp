#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    /*
    //EXAMPLE 1 - while
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
    //EXAMPLE 2 - more while examples
    int i = 5;
    while (i > 0)
    {
        cout << i << " ";
        i--;
    }
    cout << endl;
    
    //bug 1 (add semicolon after while line)
    //bug 2 (remove i--)
    */
    
    /*
    //EXAMPLE 3
    //bug - but really not an infinite loop
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
    //EXAMPLE 4 - for
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
    //EXAMPLE 5 - for w break
    int i;
    for(i = 1; i < 10; i++)
    {
        if (i%3 == 0)
            break;
    }
    cout << "after loop completes, i is: " << i << endl;
    */
    
    /*
    //EXAMPLE 6 - for w continue
    for (int i = 0; i < 10; i++)
    {
        if (i%2 == 0)
            continue;
        cout << "i is: " << i << endl;
    }
    */
    
    /*
    //EXAMPLE 7 - Bug: WHAT? this compiles because all three pieces are valid
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
    //EXAMPLE 8 - do while!
    //    goes through the loop at least once, even if the condition is not met
    int ct = 0;
    do {
        cout << "hi\n";
        ct ++;
    } while (ct < 5);
    
    //try changing condition to (ct < -5)
    */
    
    /*
    //EXAMPLE 9 - arrays
    float scores[6] = {99, 0, 95, 5, 27, 14};
    
    int total = 0;
    
    for (int i = 0; i < 6; i++){
        total += scores[i];
    }
    
    double average = float(total)/6;
    
    cout << "total is: " << total << endl;
    cout << "average is: " << average << endl;
    */
}

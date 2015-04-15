#include <iostream>

using namespace std;

/**
 *  multiplies all values stored between location beg and location end by
 *      factor
 *
 *  @param beg    pointer to the first value
 *  @param end    pointer to the last value
 *  @param factor the factor by which to multiply
 */
void multiply_all (int* beg, int* end, int factor)
{
    int* current = beg;
    while (current != end)
    {
        *current *= factor;
        current++;
    }
}

/**
 *  adds adder to all values stored between location beg and location end by
 *
 *  @param beg    pointer to the first value
 *  @param end    pointer to the last value
 *  @param adder  the amount to add to each value
 */
void add_to_all (int* beg, int* end, int adder)
{
    int* current = beg;
    while (current != end)
    {
        *current += adder;
        current++;
    }
}


/**
 *  prints all values stored between location beg and location end
 *
 *  @param beg    pointer to the first value
 *  @param end    pointer to the last value
 */
void print_all (int* beg, int* end)
{
    //since we aren't intending to alter the values, the pointer might as well
    //   be to a const value so that we don't mess up
    const int* current = beg;
    while (current != end)
    {
        cout << *current << " ";
        current++;
    }
    cout << endl;
}

int main()
{
    
    //EXAMPLE 1 - pointers!!
    
    //cheatsheet
    // * used in declaring a pointer
    //also used to get the value of the variable a pointer is pointing to
    //& used to get the location where a variable is stored
    
    //two separate bank accounts and their initial balances
    double harrys_account = 0;
    double joint_account = 2000;
    
    //declares account_pointer as a 'pointer to double'
    double* account_pointer = &harrys_account;
    //initializes account_pointer to the memory location of harrys_account
    
    //the value that account_pointer is pointing to gets an addition of 1000
    *account_pointer += 1000; // Initial deposit
    
    //the value that account_pointer is pointing to loses 100
    *account_pointer = *account_pointer - 100;
    
    //prints the value that account_pointer is pointing to (harrys_account)
    cout << "Balance *account_pointer: " << *account_pointer << endl;
    cout << "Balance harrys_account: " << harrys_account << endl;
    
    //account_pointer now points to the location of a different variable
    account_pointer = &joint_account;
    
    //withdraw 100 from the value the pointer is pointing to
    *account_pointer = *account_pointer - 100;
    
    //print the balance
    cout << "Balance *account_pointer: " << *account_pointer << endl;
    cout << "Balance joint_account: " << joint_account << endl;
    
    
    
    //EXAMPLE 2 - another pointer example
    int x, y;
    int* px;
    int* py;
    
    //accessing an uninitialized pointer gives unpredictable values
    //    but is legal
    cout << "*px is: " << *px << endl;
    cout << "*py is: " << *py << endl;
    
    //to be sure we don't mess up and try to access an uninitialized pointer
    //   its better to set it to nullptr so that we cannot access it
    px = nullptr; //OR px = NULL
    py = nullptr; //OR py = NULL
    //now we can no longer access those pointers because they are NULL
    //cout << "*px is: " << *px << endl;
    //cout << "*py is: " << *py << endl;
    
    px = &x;   //the address of x
    py = &y;   //the address of y
    
    *px = 47;   //value pointed to by px gets 47
    *py = *px;  //value pointed to by py gets value pointed to by px (47)
    px = py; //px gets the thing py points to (they point to the same thing)
    *px = 48; //essentially, y gets 48
    
    cout << "x is: " << x << endl;
    cout << "y is: " << y << endl;
    
    
    
    //EXAMPLE 3 - the reason pointer have to have a type is because they need to
    //     know the size of the thing they are pointing to so they can retrieve
    //     it properly
    // there is a 'void' pointer - that is a pointer wtih no type
    //    these are sometimes useful, but since they have no type, you can't 
    //    immediately dereference them because you don't know how much stuff
    //    to grab, so their use is very limited
    
    int my_int = 5;
    int* intptr = &my_int;
    
    long my_long = 5;
    long* longptr = &my_long;
    
    cout << "my_int is : " << my_int << '\n';
    cout << "this is the same as: " << *intptr << '\n';
    cout << "it is stored at: " << intptr << " hex \n";
    cout << "which is the same as: " << long(intptr) << " decimal \n";
    cout << "next available place in memory is: " << long(intptr + 1) << '\n';
    cout << "dist between is: " << (long(intptr + 1) - long(intptr)) << " bytes \n";
    *(intptr + 1) = 6; //put a 6 at the next memory location
    cout << "two adjacent places in memory now have: " << *intptr ;
    cout << " " << *(intptr + 1) << '\n';
    cout << '\n';
    
    cout << "my_long is : " << my_long << '\n';
    cout << "this is the same as: " << *longptr << '\n';
    cout << "it is stored at: " << longptr << " hex \n";
    cout << "which is the same as: " << long(longptr) << " decimal \n";
    cout << "next available place in memory is: " << long(longptr + 1) << '\n';
    cout << "dist between is: " << (long(longptr + 1) - long(longptr)) << " bytes\n";
    *(longptr + 1) = 6; //put a 6 at the next memory location
    cout << "two adjacent places in memory now have: " << *longptr ;
    cout << " " << *(longptr + 1) << '\n';
    
    
     /*
     //EXAMPLE 4- pointers and arrays!!
     const int CAPACITY = 10;
     
     //a is an array of 10 numbers
     int a[CAPACITY] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
     
     //p is a pointer to a
     int* p = a; //notice this is not &a bc a itself is a pointer
     
     cout << "accessing the first element of the array..." << endl;
     cout << "*p (value p points to) is: " << *p << endl;
     cout << "*a (array name used just like a pointer) is: " << *a << endl;
     cout << "a[0] (normal access to first element of an array) is: " << a[0] << endl;
     
     cout << "pointer arithmetic..." << endl;
     cout << "*(p+3) (value (p+3) points to) is: " << *(p+3) << endl;
     cout << "*(a+3) (array name used just like a pointer) is: " << *(a+3) << endl;
     cout << "a[3] (normal access to fourth element of an array) is: " << a[3] << endl;
     */
    
     
     //EXAMPLE 5
     const int CAPACITY = 6;
     int lotto_numbers[CAPACITY] = {};
     int* pln = lotto_numbers; //pointer to first element

     lotto_numbers[1] = 43;
     *pln = 17;
	 [17, 43....]
     pln+= 2;
     *pln = 21;
     pln = lotto_numbers + 4;
     *(pln + 1) = 15;
     *pln = 87;
     pln = &lotto_numbers[3];
     *pln = 36;
     pln = lotto_numbers;
     int* qln = pln;
     *qln = 99;
     qln += 2;
     *qln = *pln - 2;
     
     for (int i = 0; i < CAPACITY; i++)
     {
         cout << lotto_numbers[i] << " ";
     }
     cout << endl;
    
    
    /*
    //EXAMPLE 6 - consts pointers and pointers to consts
    //ptr is a pointer to a const int
    //    it cannot assign to the value its pointing to
    //    but the ptr itself can be assigned (it can point to something else)
    int x = 5;
    int y = 10;
    const int* ptr = &y; //ptr gets the address of y
    // *ptr = 20; //can't do this, can change the value of the thing ptr points to
    ptr++; //but can do this
    
    //qtr is a const pointer to a const int
    const int* const qtr = &x;
    // *qtr = 15; //cannot assign the value qtr points to
    //qtr++; //cannot change the address that qtr points to
    
    int stuff[] = {1,2,3,4,5};
    print_all(stuff, stuff+3);
    multiply_all(stuff, stuff+3, 100);
    print_all(stuff, stuff+3);
    */
    
    /*
    //EXAMPLE 7 - pointers to pointers
    int x = 47;
    int* px = &x;
    int** ppx = &px;

    //print the value stored in x...
    cout << x << endl;
    cout << *px << endl;
    cout << **ppx << endl;
    */
    
    
    /*
    //EXAMPLE 8 - pointers to functions (kind of) allow passing functions as
    //    arguments (higher order functions - like we did in 111)
    
    //just like our previous example....
    int stuff[] = {1,2,3,4,5};
    print_all(stuff, stuff+3);
    multiply_all(stuff, stuff+3, 100);
    print_all(stuff, stuff+3);
    
    //now we create pointers to functions
    void (*mult)(int*, int*, int) = multiply_all;
    void (*add)(int*, int*, int) = add_to_all;

    void (*fun)(int*, int*, int) = add;
     
    (*fun)(stuff, stuff+3, 1);
    print_all(stuff, stuff+3);

    fun = mult;
    
    (*fun)(stuff, stuff+3, 100);
    print_all(stuff, stuff+3);
    */
    
}

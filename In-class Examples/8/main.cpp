#include <iostream>
#include <string>

using namespace std;

#include "Product.h"

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
    //current is NOT a pointer to a const int becuase we want to change
    //     the values that it is pointing to
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
    //notice that current is not a const pointer, bc we are changing current
    //but it is a pointer to a const int, so we cannot alter the values stored
    while (current != end)
    {
        cout << *current << " ";
        current++;
    }
    cout << endl;
}


int main() {
    /*
    //EXAMPLE 5 - from last time
    const int CAPACITY = 6;
    int lotto_numbers[CAPACITY] = {};
    int* pln = lotto_numbers;
    
    lotto_numbers[1] = 43;
    *pln = 17;
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
     */
    
    /*
    //EXAMPLE 6 - consts pointers and pointers to consts
    //ptr is a pointer to a const int
    //    it cannot assign to the value its pointing to
    //    but the ptr itself can be assigned (it can point to something else)
    int x = 5;
    int y = 10;
    //ptr is a pointer to a const int
    const int* ptr = &y; //ptr gets the address of y.
    cout << "y is: " << *ptr << endl; //can print out the value that it points to
    // *ptr = 20; //can't do this, can change the value of the thing ptr points to
    ptr++; //but can do this (can have it point to something else)
     
    //qtr is a const pointer to a const int - the 'const' right before qtr
    //    makes it a const pointer
    const int* const qtr = &x;
    cout << "x is: " << *qtr << endl;
    // *qtr = 15; //cannot assign the value qtr points to
    //qtr++; //cannot change the address that qtr points to
    
    //why is this useful?????
    int stuff[] = {1,2,3,4,5};
    //what is stuff? what is stuff+3?
    print_all(stuff, stuff+3);
    multiply_all(stuff, stuff+3, 100);
    print_all(stuff, stuff+3);
    //in print_all, using a const int* (a pointer to a const int) protects us
    //   from accidentally altering a value during the printing process
    //   (that is, we'd get an error if we tried to)
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
    //    arguments (higher order functions)
    //functions are stored in memory just like variables
     
    //just like our previous example....
    int stuff[] = {1,2,3,4,5};
    print_all(stuff, stuff+3);
    multiply_all(stuff, stuff+3, 100);
    print_all(stuff, stuff+3);
     
    //now we create pointers to functions
    void (*mult)(int*, int*, int) = multiply_all; //ptr called mult to multiply_all
    void (*add)(int*, int*, int) = add_to_all; //ptr called add to add_to_all
    
    //create a new pointer called fun and set it to the pointer add
    //   which is holding the location of our add_to_all function
    void (*fun)(int*, int*, int) = add;
    
    //call the function located at fun
    (*fun)(stuff, stuff+3, 1);
    print_all(stuff, stuff+3);
    
    //set fun to be the mult pointer, location of the multiply_all function
    fun = mult;

    //call the function located at fun
    (*fun)(stuff, stuff+3, 100);
    print_all(stuff, stuff+3);
    */

    /*
    //EXAMPLE 0 - a simple example for breakpoints
    //   try a breakpoint on total+=current line
    int some_stuff[10] = {1,2,3,4,5,6,7,8,9,10};
    int total = 0;
    
    for (int i = 0; i <= 10; i++)
    {
        int current = some_stuff[i];
        total += current;
    }
    
    cout << "total is: " << total << endl;
    */
    
    /*
    //EXAMPLE 1- Imagine that we're trying to shop for a toaster oven.
    //   We want to get the best value for our money. We will define value as
    //   the ratio of average customer rating score (called score) to price.
    //   That is, the value of a car is boosted by their score and punished by
    //   their price.
    //   We will ask the user for some info about different toaster ovens.
    //   Then, at the end, we will tell them which has the highest 'value.'
    //&&&getline just gets a whole line of input - not important to this example
    
    //the 3 variables that will store the 'best' product info
    string best_name = "";
    double best_price = 1;
    int best_score = 0;
    
    //a variable to tell use whether or not to keep getting stuff from user
    bool more = true;
    
    while (more)
    {
        //the 3 variables that will store the 'next' product info
        string next_name;
        double next_price;
        int next_score;
        
        cout << "Please enter the model name: " << endl;
        getline(cin, next_name); //gets a whole line, not just up to a space
        cout << "Please enter the price: " << endl;
        cin >> next_price;
        cout << "Please enter the score: " << endl;
        cin >> next_score;
        string remainder; // Read remainder of line
        getline(cin, remainder);
        
        //is the 'next' better than the 'best' product so far?
        if ((next_score / next_price) > (best_score / best_price))
        {
            //if yes, make it the new best product
            best_name = next_name;
            best_score = next_score;
            best_price = next_price;
        }
        //rewards higher scores, punishes higher prices
        
        cout << "More data? (y/n) ";
        string answer;
        getline(cin, answer);
        if (answer != "y")
            more = false;
    }
    cout << "The best value is " << best_name << "\n";
    cout << " Price: " << best_price << "\n";
    cout << " Score: " << best_score << endl;
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
    
}

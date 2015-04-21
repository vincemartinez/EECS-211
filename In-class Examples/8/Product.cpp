#include "Product.h"

//This 'implementation' file (classname.cpp) is hidden from the client code
//   (the person who is using our class). "This practice ensures that you do not
//   write client code that depends on the class's implementation details."
//   That way, if we change our implementation details later on, it won't
//   break the client code that is using our class.
//We need to implement all of the functions described in the .h file. Put
//   classname :: (scope resolution operator) in front of the function name
//   but otherwise copy the function prototype line of each.

Product::Product()
{
    name = "";
    price = 1;
    score = 0;
}

void Product::read()
{
    cout << "Please enter the model name: ";
    getline(cin, name);
    
    cout << "Please enter the price: ";
    cin >> price;
    
    cout << "Please enter the score: ";
    cin >> score;
    
    string remainder; // Read the remainder of the line
    getline(cin, remainder);
}

void Product::print() const
{
    cout << "Model name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Score: " << score << endl;
}

bool Product::is_better_than(Product b) const
{
    return ((score / price) > (b.score / b.price));
}

#include <iostream>
#include <string>
using namespace std;

//This file (Product.h) gives the Product interface
//  "describes what services a class's clients can use and how to request those
//  services, but not how the class carries out the services"

class Product
{
public:  //4 member functions below are accessible to
    //you see their function 'prototypes'
    //describes how someone uses the function without giving away the
    //    implementation details
    Product(); //constructors cannot return values so no return type
    void read();
    bool is_better_than(Product b) const; //note the const
    void print() const;
private: //data-members (attributes) will most commonly be private - are only
         //accessible to member functions of the class (or 'friends')
    string name;
    double price;
    int score;
};

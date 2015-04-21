

class CashRegister
{
public:
    //CashRegister(); //the default constructor
    void clear();  //clear the items and price
    void add_item(double price); //add an item to the order
    void add_items(long  qnt, double prc); //adds a # of the same item
    double get_total() const; //get the total price
    long get_count() const; //get the item count
    void display() const; //display the data members
private:
    long item_count; //# of things someone is buying
    double total_price; //total cost of the transaction
};


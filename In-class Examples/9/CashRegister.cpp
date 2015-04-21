#include <iomanip>
#include <iostream>
#include "CashRegister.h"

using namespace std;

//CashRegister::CashRegister()
//{
//    item_count = 0;
//    total_price = 0;
//}

void CashRegister::clear()
{
    item_count = 0;
    total_price = 0;
}
void CashRegister::add_item(double price)
{
    item_count++;
    total_price = total_price + price;
}
void CashRegister::add_items(long qnt, double prc)
{
    for (int i = 1; i <= qnt; i++)
    {
        add_item(prc);
    }
}
double CashRegister::get_total() const
{
    return total_price;
}

long CashRegister::get_count() const
{
    return item_count;
}

void CashRegister::display() const
{
    cout << get_count() << " $";
    cout << fixed << setprecision(2) << get_total() << endl;
}


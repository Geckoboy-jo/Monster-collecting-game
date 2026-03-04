#include "item.hpp"


void item::printItem()
{
    if(quantity > 0)
    {
        cout<<"=============================="<<endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Quantity: " << quantity << endl;
        cout<<"=============================="<<endl;
    }
}
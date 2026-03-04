#include "list.hpp"

class item
{
private:
    string name;
    int ID;
    int quantity;
public:
    item(){}
    ~item(){}
    //getters and setters
    string getName(){return name;}
    int getID(){return ID;}
    int getQuantity(){return quantity;}

    void setName(string n){name = n;}
    void setID(int id){ID = id;}
    void setQuantity(int q){quantity = q;}
    //print function
    void printItem();
   
};
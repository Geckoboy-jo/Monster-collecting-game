#include "user.hpp"


void user::printUserInfo()
{
    cout<<"=============="<<endl;
    cout<<"Username: " + userName<<endl;
    cout<<"Password: " + password<<endl;
    cout<<"Display Name: " + displayName<<endl;
    cout<<"ID: " + to_string(ID)<<endl;
    cout<<"Level: " + to_string(level)<<endl;
    cout<<"=============="<<endl;
}
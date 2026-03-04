#include "top.hpp"


class user
{
private:
    string userName;
    string password;
    string displayName;
    int ID;
    int level;
public:
    user(){}
    ~user(){}
    //getters and setters
    string getUserName(){return userName;}
    string getPasword(){return password;}
    string getDisplayName(){return displayName;}
    int getID(){return ID;}
    int getLevel(){return level;}

    void setUserName(string newUserName){userName = newUserName;}
    void setPassword(string newPassword){password = newPassword;}
    void setDisplayName(string newName){displayName =  newName;}
    void setID(int newID){ID=newID;}
    void setLevel(int newLevel){level = newLevel;}
    //public member functions
    void printUserInfo();

};
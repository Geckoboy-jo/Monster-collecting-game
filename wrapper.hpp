#include "tree.hpp"

class wrapper
{
private:
    user* currentUser;
    //getters and setters
    user* getCurrentUser(){return currentUser;}

    void setCurrentUser(user* newUser){currentUser = newUser;}
    //private member functions
    void retrievwUserInfo();
    void populateTree();
public:
    wrapper(){}
    ~wrapper(){}
    //member funtions
    void runGame();
};
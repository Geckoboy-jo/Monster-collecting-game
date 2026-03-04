#include "tree.hpp"

class wrapper
{
private:
    user* currentUser;
    BST* plantIndex;
    //getters and setters
    user* getCurrentUser(){return currentUser;}
    BST* getPlantIndex(){return plantIndex;}

    void setPlantIndex(BST* newPlantIndex){plantIndex = newPlantIndex;}
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
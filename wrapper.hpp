#include "shop.hpp"

class wrapper
{
private:
    user* currentUser;
    BST* plantIndex;
    shop* gameShop;
    //getters and setters
    user* getCurrentUser(){return currentUser;}
    BST* getPlantIndex(){return plantIndex;}
    shop* getGameShop(){return gameShop;}

    void setPlantIndex(BST* newPlantIndex){plantIndex = newPlantIndex;}
    void setGameShop(shop* newGameShop){gameShop = newGameShop;}
    void setCurrentUser(user* newUser){currentUser = newUser;}
    //private member functions
    void retrievwUserInfo();
    void populateTree();
public:
    wrapper(){
        currentUser = nullptr;
        plantIndex = new BST();}
    ~wrapper(){}
    //member funtions
    void runGame();
};
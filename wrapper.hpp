#include "shop.hpp"

class wrapper
{
private:
    user* currentUser;
    BST* plantIndex;
    shop* gameShop;
   
    //private member functions
    void retrievwUserInfo();
    void populateTree();
    void retrievGameData();
    void retrieveInventory();
    void saveGameData();
public:
    wrapper(){
        currentUser = nullptr;
        plantIndex = new BST();
        gameShop = new shop(60, 5);
    }
    ~wrapper(){saveGameData(); delete currentUser; delete plantIndex; delete gameShop;}
    //member funtions
    void preGame();
    //getters and setters
    user* getCurrentUser(){return currentUser;}
    BST* getPlantIndex(){return plantIndex;}
    shop* getGameShop(){return gameShop;}

    void setPlantIndex(BST* newPlantIndex){plantIndex = newPlantIndex;}
    void setGameShop(shop* newGameShop){gameShop = newGameShop;}
    void setCurrentUser(user* newUser){currentUser = newUser;}
};
#include "wrapper.hpp"


class game
{
private:
    wrapper* gameWrapper;
    //getters and setters
    wrapper* getGameWrapper(){return gameWrapper;}
    void setGameWrapper(wrapper* newWrapper){gameWrapper = newWrapper;}
    //private member functions
    void gameLoop();
    void waterPlant();
    int getuserInput();
    void passTime();
    void repotPlant();
    void harvestPlant();
    void getSeed(int plantID);
    void plantPlant();
public:
    game(){gameWrapper = new wrapper();}
    ~game(){delete gameWrapper;}
    //member functions
    void RunGame();
};
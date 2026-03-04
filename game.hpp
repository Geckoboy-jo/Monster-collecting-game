#include "wrapper.hpp"


class game
{
private:
    wrapper* gameWrapper;
    //getters and setters
    wrapper* getGameWrapper(){return gameWrapper;}
    void setGameWrapper(wrapper* newWrapper){gameWrapper = newWrapper;}
    //private member functions
    bool gameLoop();
    void waterPlant();
    int getuserInput();
public:
    game(){gameWrapper = new wrapper();}
    ~game(){delete gameWrapper;}
    //member functions
    void RunGame();
};
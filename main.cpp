#include "game.hpp"

int main()
{
    game* myGame = new game();
    myGame->RunGame();
    delete myGame;
    return 0;
}
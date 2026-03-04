#include "game.hpp"


void game::RunGame()
{
    gameWrapper->preGame();
    while(gameLoop());
    
}
bool game::gameLoop()
{
    if(getuserInput() == 1) gameWrapper->getGameShop()->getInventory()->printList();
    else if(getuserInput() == 2) gameWrapper->getPlantIndex()->printInOrder();
    else if(getuserInput() == 3) waterPlant();
    else if(getuserInput() == 4) gameWrapper->getCurrentUser()->printUserInfo();
    else if(getuserInput() == 5) return false;
    return true;
}
int game::getuserInput()
{
    while(true)
    {
        cout<<"what would you like to do?"<<endl;
        cout<<"1. View shop inventory"<<endl;
        cout<<"2. View plant index"<<endl;
        cout<<"3. Water plants"<<endl;
        cout<<"4. View your stats"<<endl;
        cout<<"5. Exit game"<<endl;
        string input;
        cin>>input;
        try{return stoi(input);}
        catch(invalid_argument& e){cout<<"invalid input, try again"<<endl;}
    }
}
void game::waterPlant()
{
    while(true)
    {
        cout<<"which plant would you like to water?"<<endl;
        cout<<"==============="<<endl;
        ListNode* pMem = gameWrapper->getGameShop()->getInventory()->getPHead();
        int index = 1;
        while(pMem != nullptr) cout<<index++<<". "<<pMem->getData()->getName()<<endl;
        string input;
        cin>>input;
        try
        {
            int choice = stoi(input);
            if(choice<1 || choice>=index) throw out_of_range("invalid input, try again");
            plant* chosenPlant = gameWrapper->getGameShop()->getInventory()->getAtIndex(choice-1)->getData();
            chosenPlant->setWaterHas(chosenPlant->getWaterHas()+1);
            cout<<"you watered "<<chosenPlant->getName()<<", its health is now "<<chosenPlant->getHealth()<<endl;
            break;
        }
        catch(invalid_argument& e){cout<<"invalid input, try again"<<endl;}
        cout<<"==============="<<endl;
    }
    
}
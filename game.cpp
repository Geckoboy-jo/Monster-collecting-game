#include "game.hpp"


void game::RunGame()
{
    gameWrapper->preGame();
    gameLoop();
    
}
void game::gameLoop()
{
    while(true)
    {
        int userChoice = getuserInput();
        plant* newPlant = nullptr;
        item* newItem = nullptr;
        if(userChoice == 1) gameWrapper->getGameShop()->getPlantInventory()->printList(newPlant);
        else if(userChoice == 2) gameWrapper->getPlantIndex()->printInOrder();
        else if(userChoice == 3) gameWrapper->getGameShop()->getItemInventory()->printList(newItem);
        else if(userChoice == 4) waterPlant();
        else if(userChoice == 5) gameWrapper->getCurrentUser()->printUserInfo();
        else if(userChoice == 6) passTime();
        else if(userChoice == 7) break;
        else cout<<"invalid input, try again"<<endl;
    }
}

int game::getuserInput()
{
    while(true)
    {
        cout<<"what would you like to do?"<<endl;
        cout<<"1. View shop inventory"<<endl;
        cout<<"2. View plant book"<<endl;
        cout<<"3. View item inventory"<<endl;
        cout<<"4. Water plants"<<endl;
        cout<<"5. View your stats"<<endl;
        cout<<"6. sleep for a day"<<endl;
        cout<<"7. Exit game"<<endl;
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
        ListNode<plant*>* pMem = gameWrapper->getGameShop()->getPlantInventory()->getHead();
        int index = 1;
        while(pMem != nullptr) {
            cout<<index++<<". "<<pMem->getData()->getName()<<endl;
            pMem = pMem->getNext();
        }
        string input;
        cin>>input;
        try
        {
            int choice = stoi(input);
            if(choice<1 || choice>=index) throw out_of_range("invalid input, try again");
            plant* chosenPlant = gameWrapper->getGameShop()->getPlantInventory()->getAtIndex(choice-1)->getData();
            chosenPlant->setWaterHas(chosenPlant->getWaterHas()+1);
            cout<<"you watered "<<chosenPlant->getName()<<" it now has "<<fixed<<setprecision(2)<<chosenPlant->getWaterHas()<<" water"<<endl;
            break;
        }
        catch(invalid_argument& e){cout<<"invalid input, try again"<<endl;}
        cout<<"==============="<<endl;
    }
    
}
void game::passTime()
{
    
    ListNode<plant*>* pMem = gameWrapper->getGameShop()->getPlantInventory()->getHead();
    while(pMem != nullptr)
    {
        pMem->getData()->ageCycle();
        pMem = pMem->getNext();
    }
}
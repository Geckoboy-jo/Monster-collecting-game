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
        else if(userChoice == 5) repotPlant();
        else if(userChoice == 6) harvestPlant();
        else if(userChoice == 7) gameWrapper->getCurrentUser()->printUserInfo();
        else if(userChoice == 8) passTime();
        else if(userChoice == 9) break;
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
        cout<<"5. Repot plants"<<endl;
        cout<<"6. Harvest plants"<<endl;
        cout<<"7. View your stats"<<endl;
        cout<<"8. Sleep for a day"<<endl;
        cout<<"9. Exit game"<<endl;
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
            try
            {
                cout<<"how much water would you like to give your plant?"<<endl;
                string input;
                cin>>input;
                int waterAmount = stoi(input);
                if(waterAmount<0) throw out_of_range("invalid input, try again");
                plant* chosenPlant = gameWrapper->getGameShop()->getPlantInventory()->getAtIndex(choice-1)->getData();
                chosenPlant->setWaterHas(chosenPlant->getWaterHas()+waterAmount);
            }
            catch(invalid_argument& e){cout<<"invalid input, try again"<<endl;}
            cout<<"==============="<<endl;
            cout<<"you watered "<<chosenPlant->getName()<<" it now has "<<fixed<<setprecision(2)<<chosenPlant->getWaterHas()<<" water"<<endl;
            break;

        }
        catch(invalid_argument& e){cout<<"invalid input, try again"<<endl;}
        cout<<"how much water would you like to give your plant?"<<endl;
        
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
    cout<<"you slept for a day, now all your plants are a day older!"<<endl;
}

void game::repotPlant()
{
    while(true)
    {
        cout<<"==============="<<endl;
        cout<<"which plant would you like to repot?"<<endl;
        
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
            chosenPlant->setSoilNutrientsLevel(chosenPlant->getSoilNutrientsLevelMax());
            cout<<"you repotted "<<chosenPlant->getName()<<" it now has "<<fixed<<setprecision(2)<<chosenPlant->getSoilNutrientsLevel()<<" soil nutrients"<<endl;
            break;
        }
        catch(invalid_argument& e){cout<<"invalid input, try again"<<endl;}
        cout<<"==============="<<endl;
    }
}
void game::harvestPlant()
{
    while(true)
    {
        cout<<"which plant would you like to harvest?"<<endl;
        cout<<"==============="<<endl;
        ListNode<plant*>* pMem = gameWrapper->getGameShop()->getPlantInventory()->getHead();
        int index = 1;
        int numSkipped = 0;
        while(pMem != nullptr) {
            if(pMem->getData()->getHasFruit() == true)
            {
                cout<<index<<". "<<pMem->getData()->getName()<<endl;
                index++;
            }
            else numSkipped++;
            pMem = pMem->getNext();
        }
        if(index == 1) {
            cout<<"you have no plants with fruit to harvest"<<endl;
            break;
        }
        else
        {
            string input;
            cin>>input;
            try
            {
                int choice = stoi(input);
                if(choice<1 || choice>=index) throw out_of_range("invalid input, try again");
                plant* chosenPlant = gameWrapper->getGameShop()->getPlantInventory()->getAtIndex(choice-1+numSkipped)->getData();
                if(chosenPlant->getHasFruit() == false) {cout<<"this plant has no fruit to harvest"<<endl; break;}
                chosenPlant->setHasFruit(false);
                getSeed(chosenPlant->getID());
                cout<<"you harvested "<<chosenPlant->getName()<<" and got "<<fixed<<setprecision(2)<<(chosenPlant->getYeild()/3)<<" fruit!"<<endl;
                break;
            }
            catch(invalid_argument& e){cout<<"invalid input, try again"<<endl;}
        }
        
        cout<<"==============="<<endl;
    }
}


void game::getSeed(int plantID)
{
    ListNode<item*>* pMem = gameWrapper->getGameShop()->getItemInventory()->getHead(); 
    for(int i=0; i<plantID; i++) pMem = pMem->getNext();
    pMem->getData()->setQuantity(pMem->getData()->getQuantity()+1);
    cout<<"you got a "<<pMem->getData()->getName()<<" seed! you now have "<<pMem->getData()->getQuantity()<<" "<<pMem->getData()->getName()<<" seeds!"<<endl;
}
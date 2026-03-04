#include "wrapper.hpp"


void wrapper::preGame()
{
    retrievwUserInfo();
    currentUser->printUserInfo();
    populateTree();
    cout<<"tree popualted"<<endl; 
    //plantIndex->printInOrder();
    cout<<"retrieving gameData"<<endl;
    retrievGameData();
    retrieveInventory();
    //invenctory printed
    cout<<"gameData retrieved"<<endl;
    gameShop->setAmbaince();
    //ambiance set
    //saveGameData();

}

void wrapper::retrievwUserInfo()
{
    fstream file("userData.csv");
    string line, token;
    line = "hello";
    user* newUser = new user();
    getline(file, line);//header line
    getline(file, line);
    stringstream ss(line);
    getline(ss, token, ',');
    newUser->setUserName(token);
    getline(ss, token, ',');
    newUser->setPassword(token);
    getline(ss, token, ',');
    newUser->setDisplayName(token);
    getline(ss, token, ',');
    newUser->setID(stoi(token));
    getline(ss, token, ',');
    newUser->setLevel(stoi(token));
    setCurrentUser(newUser);
}
void wrapper::populateTree()
{
    fstream file("plants.csv");
    string line, token;
    getline(file, line);//header line
    while(getline(file, line))
    {
        plant* newPlant = new plant(1);
        stringstream ss(line);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setName(token);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setID(stoi(token));
        getline(ss, token, ',');
        newPlant->setGrowRate(stof(token));
        newPlant->setCanProduce(true);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setYeild(stof(token));
        newPlant->setAge(0);
        newPlant->setMaturity(seedling);
        newPlant->setHasFruit(0);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setWaterNeedsMin(stof(token));
        newPlant->setWaterHas(0);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setWaterNeedsMax(stof(token));
        newPlant->setWaterHas(0);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setSunNeedsMin(stof(token));
        newPlant->setSunHas(0);

        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setSunNeedsMax(stof(token));
        newPlant->setSunHas(0);
        
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setMaxHealth(stof(token));
        newPlant->setHealth(newPlant->getMaxHealth());
        newPlant->setIsAlive(1);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setCanDie(stoi(token));
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setValue(stof(token));
        newPlant->setForSale(0);
        newPlant->setSoilNutrientsLevelMax(10);
        newPlant->setSoilNutrientsLevel(10);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setTemperatureNeedsHigh(stof(token));
        getline(ss, token, '\0');
        //cout<<token<<endl;
        newPlant->setTemperatureNeedsLow(stof(token));
        cout<<"flag"<<endl;
        plantIndex->insert(newPlant);
        cout<<"flag"  <<endl;

    }
}
void wrapper::retrievGameData()
{
    fstream file("gameData.csv");
    string line, token;
    getline(file, line);//header line
    while(getline(file, line))
    {
        stringstream ss(line);
        getline(ss, token, ',');
        plant* currentPlant = new plant(plantIndex->search(stoi(token)));
        if(currentPlant == nullptr) continue;
        getline(ss, token, ',');
        currentPlant->setAge(stof(token));
        if(currentPlant->getAge()>=0 && currentPlant->getAge()<5*currentPlant->getGrowRate()) currentPlant->setMaturity(seedling);
        else if(currentPlant->getAge()>=5*currentPlant->getGrowRate() && currentPlant->getAge()<10*currentPlant->getGrowRate()) currentPlant->setMaturity(juvenile);
        else if(currentPlant->getAge()>=10*currentPlant->getGrowRate()) currentPlant->setMaturity(adult);
        getline(ss, token, ',');
        currentPlant->setCanProduce(stoi(token));
        getline(ss, token, ',');
        currentPlant->setHasFruit(stoi(token));
        getline(ss, token, ',');
        currentPlant->setHealth(stof(token));
        getline(ss, token, ',');
        currentPlant->setSoilNutrientsLevel(stof(token));
        getline(ss, token, ',');
        currentPlant->setForSale(stoi(token));
        getline(ss, token, '\0');
        currentPlant->setWaterHas(stof(token));
        gameShop->getPlantInventory()->insertAtFront(currentPlant);
    }
}

void wrapper::saveGameData()
{
    fstream file("gameData.csv", ios::out);
    file<<"ID,age,canProduce,hasFruit,health,soilNutrientsLevel,ForSale,waterHas\n";
    list<plant*>* inventory = gameShop->getPlantInventory();
    ListNode<plant*>* current = inventory->getHead();
    while(current != nullptr)
    {
        plant* currentPlant = current->getData();
        file<<currentPlant->getID()<<","<<currentPlant->getAge()<<","<<currentPlant->getCanProduce()<<","<<currentPlant->getHasFruit()<<","<<currentPlant->getHealth()<<","<<currentPlant->getSoilNutrientsLevel()<<","<<currentPlant->getForSale()<<","<<currentPlant->getWaterHas()<<"\n";
        current = current->getNext();
    }
    file.close();
    fstream userFile("userData.csv", ios::out);
    userFile<<"userName,password,displayName,ID,level\n";
    user* currentUser = getCurrentUser();
    userFile<<currentUser->getUserName()<<","<<currentUser->getPassword()<<","<<currentUser->getDisplayName()<<","<<currentUser->getID()<<","<<currentUser->getLevel()<<"\n";
    userFile.close();
    saveInventory();
}


void wrapper::retrieveInventory()
{
    fstream file("inventory.csv");
    string line, token;
    getline(file, line);//header line
    while(getline(file, line))
    {
        stringstream ss(line);
        getline(ss, token, ',');
        item* newItem = new item();
        newItem->setID(stoi(token));
        getline(ss, token, ',');
        newItem->setName(token);
        getline(ss, token, ',');
        newItem->setQuantity(stoi(token));
        gameShop->getItemInventory()->insertAtFront(newItem);
    }
}

//public save inventory function
void wrapper::saveInventory()
{
    fstream file("inventory.csv", ios::out);
    file<<"itemID,item name,quantity\n";
    ListNode<item*>* current = gameShop->getItemInventory()->getHead();
    saveInventory(current, file);
    file.close();
}
void wrapper::saveInventory(ListNode<item*>* current, fstream& file)
{
    if(current == nullptr) return;
    item* currentItem = current->getData();
    saveInventory(current->getNext(), file);
    file<<currentItem->getID()<<","<<currentItem->getName()<<","<<currentItem->getQuantity()<<"\n";
    
}
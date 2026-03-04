#include "wrapper.hpp"


void wrapper::runGame()
{
    retrievwUserInfo();
    currentUser->printUserInfo();
    populateTree();
}

void wrapper::retrievwUserInfo()
{
    fstream file("userData.csv");
    string line, token;
    line = "hello";
    user* newUser = new user();
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
    line = "hello";
    BST* tree = new BST();
    while(getline(file, line))
    {
        stringstream ss(line);
        getline(ss, token, ',');
        plant* newPlant = new plant(stof(token));
        getline(ss, token, ',');
        newPlant->setName(token);
        getline(ss, token, ',');
        newPlant->setGrowRate(stof(token));
        newPlant->setCanProduce(true);
        getline(ss, token, ',');
        newPlant->setYeild(stof(token));
        newPlant->setAge(0);
        newPlant->setMaturity(seedling);
        newPlant->setHasFruit(0);
        getline(ss, token, ',');
        newPlant->setWaterNeeds(stof(token));
        newPlant->setWaterHas(0);
        getline(ss, token, ',');
        newPlant->setSunNeeds(stof(token));
        newPlant->setSunHas(0);
        getline(ss, token, ',');
        newPlant->setMaxHealth(stof(token));
        newPlant->setHealth(newPlant->getMaxHealth());
        newPlant->setIsAlive(1);
        getline(ss, token, ',');
        newPlant->setCanDie(stoi(token));
        getline(ss, token, ',');
        newPlant->setValue(stof(token));
        newPlant->setForSale(0);
        newPlant->setSoilNutrientsLevelMax(10);
        newPlant->setSoilNutrientsLevel(10);
        getline(ss, token);
        newPlant->setTemperatureNeedsHigh(stof(token));
        getline(ss, token, ',');
        newPlant->setTemperatureNeedsLow(stof(token));
        tree->insert(newPlant);
    }
}
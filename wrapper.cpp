#include "wrapper.hpp"


void wrapper::runGame()
{
    retrievwUserInfo();
    currentUser->printUserInfo();
    populateTree();
    cout<<"tree popualted"<<endl; 
    plantIndex->printInOrder();
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
        newPlant->setWaterNeeds(stof(token));
        newPlant->setWaterHas(0);
        getline(ss, token, ',');
        //cout<<token<<endl;
        newPlant->setSunNeeds(stof(token));
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
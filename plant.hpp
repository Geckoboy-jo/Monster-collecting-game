#include "user.hpp"



//plant stages of maturity
typedef enum plantMaturity
{
    seedling,
    juvenile,
    adult
} plantMaturity;
class plant

{
private:
    string name;//plant name
    int ID;//type of plant

    //a growth rate of 1 means that is takes 10 cycles for the plant to reach adulthood
    float growRate;//rate the plant grows
    
    bool canProduce;//whether or not the plant can produce fruit

    //a yeild of 1 means that a plant can produce 1 fruit per 3 cycles
    float yeild;//rate the plant produces fruit

    float age;//how many cycles the plant has been alive
    plantMaturity maturity;//the maturity of the plant
    bool hasFruit;//whether or not the plant has fruit


    float waterNeeds;//amount of water the plant needs
    float waterHas;//amount of water the plant has


    float sunNeeds;//amount of sunlight the plant needs
    float sunHas;//amount of sunlight the plant has

    //health score
    float maxHealth;//the maximum health the plant can have
    float health;//how healthy the plant is
    bool isAlive;//whether or not the plant is alive

    bool canDie;//whether or not the plant can die

    float value;//value of the plant
    bool ForSale;//whether or not the plant is for sale

    float soilNutrientsLevelMax;//max level of soil nutrients the plant can benefit from
    float soilNutrientsLevel;//how nutritious the soil is  

    float temperatureNeedsHigh;//the temperature the plant needs
    float temperatureNeedsLow;//the temperature the plant needs
    float temperatureHas;//the temperature the plant has  
public:
    plant(int id) : ID(id) {
        name = "default";
        growRate = 1;
        canProduce = true;
        yeild = 1;
        age = 0;
        maturity = seedling;
        hasFruit = false;
        waterNeeds = 1;
        waterHas = 0;
        sunNeeds = 1;
        sunHas = 0;
        maxHealth = 10;
        health = maxHealth;
        isAlive = true;
        canDie = false;
        value = 1;
        ForSale = false;
        soilNutrientsLevelMax = 10;
        soilNutrientsLevel = soilNutrientsLevelMax/2;
        temperatureNeedsHigh = 30;
        temperatureNeedsLow = 0;
        temperatureHas = (temperatureNeedsHigh + temperatureNeedsLow)/2;
    }
    ~plant(){}
    //getters and setters
    string getName(){return name;}
    int getID(){return ID;}
    float getGrowRate(){return growRate;}
    bool getCanProduce(){return canProduce;}
    float getYeild(){return yeild;}
    float getAge(){return age;}
    plantMaturity getMaturity(){return maturity;}
    bool getHasFruit(){return hasFruit;}
    float getWaterNeeds(){return waterNeeds;}
    float getWaterHas(){return waterHas;}
    float getSunNeeds(){return sunNeeds;}
    float getSunHas(){return sunHas;}
    float getMaxHealth(){return maxHealth;}
    float getHealth(){return health;}
    bool getIsAlive(){return isAlive;}
    bool getCanDie(){return canDie;}
    float getValue(){return value;}
    bool getForSale(){return ForSale;}
    float getSoilNutrientsLevelMax(){return soilNutrientsLevelMax;}
    float getSoilNutrientsLevel(){return soilNutrientsLevel;}
    float getTemperatureNeedsHigh(){return temperatureNeedsHigh;}
    float getTemperatureNeedsLow(){return temperatureNeedsLow;}
    float getTemperatureHas(){return temperatureHas;}

    void setName(string newName){name = newName;}
    void setID(int newID){ID = newID;}
    void setGrowRate(float newGrowRate){growRate = newGrowRate;}
    void setCanProduce(bool newCanProduce){canProduce = newCanProduce;}
    void setYeild(float newYeild){yeild = newYeild;}
    void setAge(float newAge){age = newAge;}
    void setMaturity(plantMaturity newMaturity){maturity = newMaturity;}
    void setHasFruit(bool newHasFruit){hasFruit = newHasFruit;}
    void setWaterNeeds(float newWaterNeeds){waterNeeds = newWaterNeeds;}
    void setWaterHas(float newWaterHas){waterHas = newWaterHas;}
    void setSunNeeds(float newSunNeeds){sunNeeds = newSunNeeds;}
    void setSunHas(float newSunHas){sunHas = newSunHas;}
    void setMaxHealth(float newMaxHealth){maxHealth = newMaxHealth;}
    void setHealth(float newHealth){health = newHealth;}
    void setIsAlive(bool newIsAlive){isAlive = newIsAlive;}
    void setCanDie(bool newCanDie){canDie = newCanDie;}
    void setValue(float newValue){value = newValue;}
    void setForSale(bool newForSale){ForSale = newForSale;}
    void setSoilNutrientsLevelMax(float newSoilNutrientsLevelMax){soilNutrientsLevelMax = newSoilNutrientsLevelMax;}
    void setSoilNutrientsLevel(float newSoilNutrientsLevel){soilNutrientsLevel = newSoilNutrientsLevel;}
    void setTemperatureNeedsHigh(float newTemperatureNeedsHigh){temperatureNeedsHigh = newTemperatureNeedsHigh;}
    void setTemperatureNeedsLow(float newTemperatureNeedsLow){temperatureNeedsLow = newTemperatureNeedsLow;}

    //public member functions
    //age cycle
    void ageCycle();
    void printPlantData();



};
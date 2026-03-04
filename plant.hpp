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
    int entityID;//unique identifier for the plant

    //a growth rate of 1 means that is takes 10 cycles for the plant to reach adulthood
    float growRate;//rate the plant grows
    
    bool canProduce;//whether or not the plant can produce fruit

    //a yeild of 1 means that a plant can produce 1 fruit per 3 cycles
    float yeild;//rate the plant produces fruit

    float age;//how many cycles the plant has been alive
    plantMaturity maturity;//the maturity of the plant
    bool hasFruit;//whether or not the plant has fruit


    float waterNeedsMin;//amount of water the plant needs
    float waterNeedsMax;//amount of water the plant needs
    float waterHas;//amount of water the plant has


    float sunNeedsMin;//amount of sunlight the plant needs
    float sunNeedsMax;//amount of sunlight the plant needs
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
        entityID = 0;
        growRate = 1;
        canProduce = true;
        yeild = 1;
        age = 0;
        maturity = seedling;
        hasFruit = false;
        waterNeedsMin = 1;
        waterNeedsMax = 1;
        waterHas = 0;
        sunNeedsMin = 1;
        sunNeedsMax = 1;
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
    plant(plant* copy);
    ~plant(){}
    //getters and setters
    string getName(){return name;}
    int getID(){return ID;}
    int getEntityID(){return entityID;}
    float getGrowRate(){return growRate;}
    bool getCanProduce(){return canProduce;}
    float getYeild(){return yeild;}
    float getAge(){return age;}
    plantMaturity getMaturity(){return maturity;}
    bool getHasFruit(){return hasFruit;}
    float getWaterNeedsMin(){return waterNeedsMin;}
    float getWaterNeedsMax(){return waterNeedsMax;}
    float getWaterHas(){return waterHas;}
    float getSunNeedsMin(){return sunNeedsMin;}
    float getSunNeedsMax(){return sunNeedsMax;}
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
    void setEntityID(int newEntityID){entityID = newEntityID;}
    void setGrowRate(float newGrowRate){growRate = newGrowRate;}
    void setCanProduce(bool newCanProduce){canProduce = newCanProduce;}
    void setYeild(float newYeild){yeild = newYeild;}
    void setAge(float newAge){age = newAge;}
    void setMaturity(plantMaturity newMaturity){maturity = newMaturity;}
    void setHasFruit(bool newHasFruit){hasFruit = newHasFruit;}
    void setWaterNeedsMin(float newWaterNeedsMin){waterNeedsMin = newWaterNeedsMin;}
    void setWaterNeedsMax(float newWaterNeedsMax){waterNeedsMax = newWaterNeedsMax;}
    void setWaterHas(float newWaterHas){waterHas = newWaterHas;}
    void setSunNeedsMin(float newSunNeedsMin){sunNeedsMin = newSunNeedsMin;}
    void setSunNeedsMax(float newSunNeedsMax){sunNeedsMax = newSunNeedsMax;}
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
    void setTemperatureHas(float newTemperatureHas){temperatureHas = newTemperatureHas;}
    //public member functions
    //age cycle
    void ageCycle();
    void printPlantData();



};
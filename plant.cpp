#include "plant.hpp"


void plant::ageCycle()
{
    if(getIsAlive() == false) return;
    if(canProduce == true)
    {
        setAge(getAge() + 1);
        if(getAge()>=0 && getAge()<5*getGrowRate()) setMaturity(seedling);
        else if(getAge()>=5*getGrowRate() && getAge()<10*getGrowRate()) setMaturity(juvenile);
        else if(getAge()>=10*getGrowRate()) setMaturity(adult);
        if(getMaturity() == adult)
        {
            if(static_cast<int>(getAge()) % static_cast<int>(3/getYeild()) == 0) setHasFruit(true);
        }
        if(getWaterHas() < getWaterNeedsMin()) setHealth(getHealth() - 1);
        if(getSunHas() < getSunNeedsMin()) setHealth(getHealth() - 1);
        if(getTemperatureNeedsLow() < getTemperatureHas()) setHealth(getHealth() - 1);
        if(getSoilNutrientsLevel() < 0) setHealth(getHealth() - 1);
        if(getWaterHas() > getWaterNeedsMax()) setHealth(getHealth() - 1);
        if(getSunHas() > getSunNeedsMax()) setHealth(getHealth() - 1);
        if(getTemperatureHas() > getTemperatureNeedsHigh()) setHealth(getHealth() - 1);
        soilNutrientsLevel--;
        if((getWaterHas()> getWaterNeedsMin())&& (getSunHas() > getSunNeedsMin()) && (getTemperatureHas() >= getTemperatureNeedsLow()))
        {
            if(getTemperatureHas() <= getTemperatureNeedsHigh()) setHealth(getHealth() + 1);
        } 
        if(getHealth() > maxHealth) setHealth(maxHealth);
        if(getHealth() < 0) setHealth(0);
        if(getHealth() <= 0 && canDie == true) setIsAlive(false);
        else if(getHealth() <= 0 && canDie == false) setCanProduce(false);
        
    }
    else
    {
        if((getWaterHas()> getWaterNeedsMin())&& (getSunHas() > getSunNeedsMin()) && (getTemperatureHas() >= getTemperatureNeedsLow()))
        {
            if(getTemperatureHas() <= getTemperatureNeedsHigh()) setHealth(getHealth() + 1);
        } 
        if(getHealth() >= (3/getMaxHealth())/4) setCanProduce(true);
        if(getHealth() > maxHealth) setHealth(maxHealth);
        if(getHealth() < 0) setHealth(0);
    }
}

void plant::printPlantData()
{
    cout<<"=============="<<endl;
    cout<<"Name: " + getName()<<endl;
    cout<<"ID: "<<getID()<<endl;
    cout<<"Entity ID: "<<getEntityID()<<endl;
    cout<<"Growth Rate: "<<fixed<<setprecision(2)<<getGrowRate()*10<<" days to grow"<<endl;
    if(getCanProduce() == true) cout<<"Can Produce: true"<<endl;
    else cout<<"Can Produce: false"<<endl;
    cout<<"Yeild: "<<fixed<<setprecision(2)<<(getYeild()/3)<<" fruit per day"<<endl;
    cout<<"Age: "<<fixed<<setprecision(2)<<getAge()<<" days"<<endl;
    cout<<"Maturity: "<<to_string(getMaturity())<<endl;
    if(getHasFruit() == true) cout<<"Has Fruit: true"<<endl;
    else cout<<"Has Fruit: false"<<endl;
    cout<<"Water Needs minimum: "<<fixed<<setprecision(2)<<getWaterNeedsMin()<<endl;
    cout<<"Water Needs maximum: "<<fixed<<setprecision(2)<<getWaterNeedsMax()<<endl;
    cout<<"Water Has: "<<fixed<<setprecision(2)<<getWaterHas()<<endl;
    cout<<"Sun Needs minimum: "<<fixed<<setprecision(2)<<getSunNeedsMin()<<endl;
    cout<<"Sun Needs maximum: "<<fixed<<setprecision(2)<<getSunNeedsMax()<<endl;
    cout<<"Sun Has: "<<fixed<<setprecision(2)<<getSunHas()<<endl;
    cout<<"Max Health: "<<fixed<<setprecision(2)<<getMaxHealth()<<endl;
    cout<<"Health: "<<fixed<<setprecision(2)<<getHealth()<<endl;
    if(getIsAlive() == true) cout<<"Is Alive: true"<<endl;
    else cout<<"Is Alive: false"<<endl;
    if(getCanDie() == true) cout<<"Can Die: true"<<endl;
    else cout<<"Can Die: false"<<endl;
    cout<<"Value: "<<fixed<<setprecision(2)<<getValue()<<endl;
    if(getForSale() == true) cout<<"For Sale: true"<<endl;
    else cout<<"For Sale: false"<<endl;
    cout<<"Soil Nutrients Level Max: "<<fixed<<setprecision(2)<<getSoilNutrientsLevelMax()<<endl;
    cout<<"Soil Nutrients Level: "<<fixed<<setprecision(2)<<getSoilNutrientsLevel()<<endl;
    cout<<"Temperature Needs High: "<<fixed<<setprecision(2)<<getTemperatureNeedsHigh()<<endl;
    cout<<"Temperature Needs Low: "<<fixed<<setprecision(2)<<getTemperatureNeedsLow()<<endl;
    cout<<"Temperature Has: "<<fixed<<setprecision(2)<<getTemperatureHas()<<endl;
    cout<<"=============="<<endl;

}

plant::plant(plant* copy)
{
    name = copy->getName();
    ID = copy->getID();
    entityID = copy->getEntityID();
    growRate = copy->getGrowRate();
    canProduce = copy->getCanProduce();
    yeild = copy->getYeild();
    age = copy->getAge();
    maturity = copy->getMaturity();
    hasFruit = copy->getHasFruit();
    waterNeedsMin = copy->getWaterNeedsMin();
    waterNeedsMax = copy->getWaterNeedsMax();
    waterHas = copy->getWaterHas();
    sunNeedsMin = copy->getSunNeedsMin();
    sunNeedsMax = copy->getSunNeedsMax();
    sunHas = copy->getSunHas();
    maxHealth = copy->getMaxHealth();
    health = copy->getHealth();
    isAlive = copy->getIsAlive();
    canDie = copy->getCanDie();
    value = copy->getValue();
    ForSale = copy->getForSale();
    soilNutrientsLevelMax = copy->getSoilNutrientsLevelMax();
    soilNutrientsLevel = copy->getSoilNutrientsLevel();
    temperatureNeedsHigh = copy->getTemperatureNeedsHigh();
    temperatureNeedsLow = copy->getTemperatureNeedsLow();
    temperatureHas = copy->getTemperatureHas();
}
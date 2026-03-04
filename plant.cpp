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
        if(getTemperatureNeedsLow() > getTemperatureHas()) setHealth(getHealth() - 1);
        if(getSoilNutrientsLevel() <= 0) setHealth(getHealth() - 1);
        if(getWaterHas() > getWaterNeedsMax()) setHealth(getHealth() - 1);
        if(getSunHas() > getSunNeedsMax()) setHealth(getHealth() - 1);
        if(getTemperatureHas() > getTemperatureNeedsHigh()) setHealth(getHealth() - 1);
        soilNutrientsLevel--;
        if(soilNutrientsLevel < 0) soilNutrientsLevel = 0;
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
        setAge(getAge() + 1);
        if((getWaterHas()> getWaterNeedsMin())&& (getSunHas() > getSunNeedsMin()) && (getTemperatureHas() >= getTemperatureNeedsLow()))
        {
            if(getTemperatureHas() <= getTemperatureNeedsHigh()) setHealth(getHealth() + 1);
        } 
        if(getHealth() >= (3/4)*getMaxHealth()) setCanProduce(true);
        if(getHealth() > maxHealth) setHealth(maxHealth);
        if(getHealth() < 0) setHealth(0);
    }
    if(static_cast<int>(getAge()) % 7 == 0) setWaterHas(0);
}

void plant::printPlantDataPerminent()
{
    cout<<"=============="<<endl;
    cout<<"Name: " + getName()<<endl;
    cout<<"ID: "<<getID()<<endl;
    cout<<"Growth Rate: "<<fixed<<setprecision(2)<<getGrowRate()*10<<" days to grow"<<endl;
    cout<<"Yeild: "<<fixed<<setprecision(2)<<(getYeild()/3)<<" fruit per day"<<endl;
    cout<<"Water Needs range: "<<fixed<<setprecision(2)<<getWaterNeedsMin()<<" - "<<fixed<<setprecision(2)<<getWaterNeedsMax()<<endl;
    cout<<"Sun Needs range: "<<fixed<<setprecision(2)<<getSunNeedsMin()<<" - "<<fixed<<setprecision(2)<<getSunNeedsMax()<<endl;
    cout<<"Max Health: "<<fixed<<setprecision(2)<<getMaxHealth()<<endl;
    if(getCanDie() == true) cout<<"Can Die: true"<<endl;
    else cout<<"Can Die: false"<<endl;
    cout<<"Value: "<<fixed<<setprecision(2)<<getValue()<<endl;
    if(getForSale() == true) cout<<"For Sale: true"<<endl;
    cout<<"Temperature Needs range: "<<fixed<<setprecision(2)<<getTemperatureNeedsLow()<<" - "<<fixed<<setprecision(2)<<getTemperatureNeedsHigh()<<endl;
    cout<<"=============="<<endl;

}
void plant::printPlantDataTemp()
{
    cout<<"=============="<<endl;
    cout<<"Name: " + getName()<<endl;
    cout<<"Age: "<<fixed<<setprecision(2)<<getAge()<<" days"<<endl;
    cout<<"Maturity: ";
    if(getMaturity() == seedling) cout<<"Seedling"<<endl;
    else if(getMaturity() == juvenile) cout<<"Juvenile"<<endl;
    else if(getMaturity() == adult) cout<<"Adult"<<endl;
    if(getCanProduce() == true) cout<<"Can Produce: true"<<endl;
    else cout<<"Can Produce: false"<<endl;
    if(getHasFruit() == true) cout<<"Has Fruit: true"<<endl;
    else cout<<"Has Fruit: false"<<endl;
    cout<<"Health: "<<fixed<<setprecision(2)<<getHealth()<<"/"<<fixed<<setprecision(2)<<getMaxHealth()<<endl;
    cout<<"Soil Nutrients Level: "<<fixed<<setprecision(2)<<getSoilNutrientsLevel()<<endl;
    cout<<"Water Has: "<<fixed<<setprecision(2)<<getWaterHas()<<endl;
    cout<<"Sunlight Has: "<<fixed<<setprecision(2)<<getSunHas()<<endl;
    cout<<"Temperature Has: "<<fixed<<setprecision(2)<<getTemperatureHas()<<endl;
    if(getIsAlive() == true) cout<<"Is Alive: true"<<endl;
    else cout<<"Is Alive: false"<<endl;

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
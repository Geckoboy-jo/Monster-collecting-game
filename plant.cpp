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
        if(getWaterHas() < getWaterReq()) setHealth(getHealth() - 1);
        if(getSunHas() < getSunReq()) setHealth(getHealth() - 1);
        if(getTemperatureNeedsLow() < getTemperatureHas()) setHealth(getHealth() - 1);
        if(getSoilNutrientsLevel() < 0) setHealth(getHealth() - 1);
        if(getWaterHas() > (3/2)*getWaterReq()) setHealth(getHealth() - 1);
        if(getSunHas() > (3/2)*getSunReq()) setHealth(getHealth() - 1);
        if(getTemperatureHas() > getTemperatureNeedsHigh()) setHealth(getHealth() - 1);
        soilNutrientsLevel--;
        if((getWaterHas()> getWaterReq())&& (getSunHas() > getSunReq()) && (getTemperatureHas() >= getTemperatureNeedsLow()))
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
        if((getWaterHas()> getWaterReq())&& (getSunHas() > getSunReq()) && (getTemperatureHas() >= getTemperatureNeedsLow()))
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
    cout<<"ID: " + to_string(getID())<<endl;
    cout<<"Growth Rate: " + to_string(getGrowRate())<<endl;
    cout<<"Can Produce: " + to_string(getCanProduce())<<endl;
    cout<<"Yeild: " + to_string(getYeild())<<endl;
    cout<<"Age: " + to_string(getAge())<<endl;
    cout<<"Maturity: " + to_string(getMaturity())<<endl;
    cout<<"Has Fruit: " + to_string(getHasFruit())<<endl;
    cout<<"Water Needs: " + to_string(getWaterReq())<<endl;
    cout<<"Water Has: " + to_string(getWaterHas())<<endl;
    cout<<"Sun Needs: " + to_string(getSunReq())<<endl;
    cout<<"Sun Has: " + to_string(getSunHas())<<endl;
    cout<<"Health: " + to_string(getHealth())<<endl;
    cout<<"Is Alive: " + to_string(getIsAlive())<<endl;
    cout<<"Can Die: " + to_string(getCanDie())<<endl;
    cout<<"Value: " + to_string(getValue())<<endl;
    cout<<"For Sale: " + to_string(getForSale())<<endl;
    cout<<"Soil Nutrients Level: " + to_string(getSoilNutrientsLevel())<<endl;
    cout<<"Temperature Needs Low: " + to_string(getTemperatureNeedsLow())<<endl;
    cout<<"Temperature Needs High: " + to_string(getTemperatureNeedsHigh())<<endl;
    cout<<"Temperature Has: " + to_string(getTemperatureHas())<<endl;

}
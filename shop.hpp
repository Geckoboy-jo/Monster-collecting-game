#include "item.hpp"


class shop
{
private:
    float ambientTemp;
    list<plant*>* plantInventory;
    float ambientSunlight;
    list<item*>* itemInventory;


public:
    shop(int temp, int sunlight)
    {
        ambientTemp = temp;
        ambientSunlight = sunlight;
        plantInventory = new list<plant*>();
        itemInventory = new list<item*>();
    }
    ~shop(){delete plantInventory; delete itemInventory;}
    //getters and setters 
    float getAmbientTemp(){return ambientTemp;}
    float getAmbientSunlight(){return ambientSunlight;}
    list<plant*>* getPlantInventory(){return plantInventory;}
    list<item*>* getItemInventory(){return itemInventory;}

    void setAmbientTemp(float newTemp){ambientTemp = newTemp;}
    void setAmbientSunlight(float newSunlight){ambientSunlight = newSunlight;}
    void setPlantInventory(list<plant*>* newInventory){plantInventory = newInventory;}
    void setItemInventory(list<item*>* newInventory){itemInventory = newInventory;}
    //member funtions
    void setAmbaince();
};
#include "list.hpp"


class shop
{
private:
    float ambientTemp;
    list* inventory;
    float ambientSunlight;
public:
    shop(int temp, int sunlight)
    {
        ambientTemp = temp;
        ambientSunlight = sunlight;
        inventory = new list();
    }
    ~shop(){delete inventory;}
    //getters and setters 
    float getAmbientTemp(){return ambientTemp;}
    float getAmbientSunlight(){return ambientSunlight;}
    list* getInventory(){return inventory;}



    void setAmbientTemp(float newTemp){ambientTemp = newTemp;}
    void setAmbientSunlight(float newSunlight){ambientSunlight = newSunlight;}
    void setInventory(list* newInventory){inventory = newInventory;}
    //member funtions
    void setAmbaince();
};
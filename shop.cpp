#include "shop.hpp"


void shop::setAmbaince()
{
    list<plant*>* plants = getPlantInventory();
    ListNode<plant*>* pMem = plants->getHead();
    int index =0;

    while(pMem != nullptr)
    {
        pMem->getData()->setEntityID(index);
        pMem->getData()->setTemperatureHas(getAmbientTemp());
        pMem->getData()->setSunHas(getAmbientSunlight());
        if(pMem->getData()->getIsAlive() == false) plants->removeFromIndex(index);
        else index++;
        pMem = pMem->getNext();
    }
}
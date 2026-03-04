#include "shop.hpp"


void shop::setAmbaince()
{
    list* shopInventory = getInventory();
    ListNode* pMem = shopInventory->getPHead();
    int index =0;

    while(pMem != nullptr)
    {
        pMem->getData()->setEntityID(index);
        pMem->getData()->setTemperatureHas(getAmbientTemp());
        pMem->getData()->setSunHas(getAmbientSunlight());
        if(pMem->getData()->getIsAlive() == false) shopInventory->removeFromIndex(index);
        pMem = pMem->getNext();
        index++;
    }
}
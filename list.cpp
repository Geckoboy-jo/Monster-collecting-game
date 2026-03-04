#include "list.hpp"


void list::insertAtFront(plant* newPlant)
{
    ListNode* newNode = new ListNode(newPlant);
    newNode->setNext(pHead);
    pHead = newNode;
}
void list::removeFromFront()
{
    if(istEmpty()) return;
    ListNode* temp = pHead;
    pHead = pHead->getNext();
    delete temp;
}
void list::printList()
{
    ListNode* pMem = getPHead();
    while(pMem != nullptr)
    {
        pMem->getData()->printPlantData();
        pMem = pMem->getNext();
    }
}
void list::removeFromIndex(int index)
{
    if(istEmpty()) return;
    if(index == 0)
    {
        removeFromFront();
        return;
    }
    ListNode* pMem = getPHead();
    int currentIndex = 0;
    while(pMem != nullptr && currentIndex < index - 1)
    {
        pMem = pMem->getNext();
        currentIndex++;
    }
    if(pMem == nullptr || pMem->getNext() == nullptr) return;
    ListNode* temp = pMem->getNext();
    pMem->setNext(temp->getNext());
    delete temp;
}
#include "item.hpp"


template<typename T>
class ListNode
{
private:
    T data;
    ListNode* next;
public:
    ListNode(T newData) : data(newData), next(nullptr) {}
    ~ListNode(){}
    //getters and setters
    T getData(){return data;}
    ListNode* getNext(){return next;}

    void setData(T newData){data = newData;}
    void setNext(ListNode* newNext){next = newNext;}
};
template<typename T>
class list
{
private:
    ListNode<T>* pHead;
    //other functions 
    bool istEmpty(){return pHead == nullptr;}
public:

    list(){pHead = nullptr;}
    ~list(){while(!istEmpty()){removeFromFront();}}
    //getters and setters
    ListNode<T>* getHead(){return pHead;}

    void setHead(ListNode<T>* newHead){pHead = newHead;}
    //public member functions
    void insertAtFront(T newData);
    void removeFromFront();
    void printList(plant* type); 
    void printList(item* type);
    void removeFromIndex(int index);
    ListNode<T>* getAtIndex(int index);
}; 
//implementation


template<typename T>
void list<T>::insertAtFront(T newData)
{
    ListNode<T>* newNode = new ListNode<T>(newData);
    newNode->setNext(pHead);
    pHead = newNode;
}
template<typename T>
void list<T>::removeFromFront()
{
    if(istEmpty()) return;
    ListNode<T>* temp = pHead;
    pHead = pHead->getNext();
    delete temp;
}
template<typename T>
void list<T>::printList(plant* type)
{
    
    ListNode<T>* pMem = getHead();
    while(pMem != nullptr)
    {
        pMem->getData()->printPlantData();
        pMem = pMem->getNext();
    }

}
template<typename T>
void list<T>::printList(item* type)
{
    
    ListNode<T>* pMem = getHead();
    while(pMem != nullptr)
    {
        
        pMem->getData()->printItem();
        pMem = pMem->getNext();
    }
    
}

template<typename T>
void list<T>::removeFromIndex(int index)
{
    if(istEmpty()) return;
    if(index == 0)
    {
        removeFromFront();
        return;
    }
    ListNode<T>* pMem = getHead();
    int currentIndex = 0;
    while(pMem != nullptr && currentIndex < index - 1)
    {
        pMem = pMem->getNext();
        currentIndex++;
    }
    if(pMem == nullptr || pMem->getNext() == nullptr) return;
    ListNode<T>* temp = pMem->getNext();
    pMem->setNext(temp->getNext());
    delete temp;
}
template<typename T>
ListNode<T>* list<T>::getAtIndex(int index)
{
    ListNode<T>* pMem = getHead();
    int currentIndex = 0;
    while(pMem != nullptr && currentIndex < index)
    {
        pMem = pMem->getNext();
        currentIndex++;
    }
    return pMem;
}
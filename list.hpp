#include "tree.hpp"



class ListNode
{
private:
    plant* data;
    ListNode* next;
public:
    ListNode(plant* newData) : data(newData), next(nullptr) {}
    ~ListNode(){delete data;}
    //getters and setters
    plant* getData(){return data;}
    ListNode* getNext(){return next;}

    void setData(plant* newData){data = newData;}
    void setNext(ListNode* newNext){next = newNext;}
};
class list
{
private:
    ListNode* pHead;
    //other functions 
    bool istEmpty(){return pHead == nullptr;}
public:

    list(){pHead = nullptr;}
    ~list(){while(!istEmpty()){removeFromFront();}}
    //getters and setters
    ListNode* getPHead(){return pHead;}

    void setPHead(ListNode* newPHead){pHead = newPHead;}
    //public member functions
    void insertAtFront(plant* newPlant);
    void removeFromFront();
    void printList(); 
    void removeFromIndex(int index);
    ListNode* getAtIndex(int index);
}; 
#include "tree.hpp"



void BST::insert(plant* newPlant){
    Node* newNode = new Node(newPlant);
    cout<<"newNode made" <<endl;
    if(pRoot == nullptr) setRoot(newNode); 
    else insert(newNode, pRoot);
}
void BST::insert(Node* newNode, Node* pNode)
{
    cout<<"wrong bu still alive" << endl;
    if(newNode->getData()->getID() < pNode->getData()->getID())
    {
        if(pNode->getLeft() == nullptr) pNode->setLeft(newNode);
        else insert(newNode, pNode->getLeft());
    }
    else if(newNode->getData()->getID() > pNode->getData()->getID())
    {
        if(pNode->getRight() == nullptr) pNode->setRight(newNode);
        else insert(newNode, pNode->getRight());
    }
}


void BST::destroyTree(){if(pRoot != nullptr) destroyTree(pRoot);}
void BST::destroyTree(Node* node)
{
    
    if(node->getLeft()!=nullptr) destroyTree(node->getLeft());
    if(node->getRight()!=nullptr) destroyTree(node->getRight());
    delete node;
    
}

plant* BST::search(int ID)
{
    Node* current = pRoot;
    while(current != nullptr)
    {
        if(ID == current->getData()->getID()) return current->getData();
        else if(ID < current->getData()->getID()) current = current->getLeft();
        else current = current->getRight();
    }
    return nullptr;
}

void BST::printInOrder(){if(pRoot != nullptr) printInOrder(pRoot);}
void BST::printInOrder(Node* node)
{
    
    if(node->getLeft()!=nullptr) printInOrder(node->getLeft());
    node->getData()->printPlantData();
    if(node->getRight()!=nullptr) printInOrder(node->getRight());
    
}

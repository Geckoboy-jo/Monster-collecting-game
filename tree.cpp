#include "tree.hpp"




void BST::insert(plant* newPlant)
{
    Node* newNode = new Node(newPlant);
    if(root == nullptr)
    {
        root = newNode;
        return;
    }
    Node* current = root;
    Node* parent = nullptr;
    while(current != nullptr)
    {
        parent = current;
        if(newPlant->getID() < current->getData()->getID())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }
    if(newPlant->getID() < parent->getData()->getID())
    {
        parent->setLeft(newNode);
    }
    else
    {
        parent->setRight(newNode);
    }
}

void BST::destroyTree(Node* node)
{
    if(node != nullptr)
    {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}

plant* BST::search(float ID)
{
    Node* current = root;
    while(current != nullptr)
    {
        if(ID == current->getData()->getID())
        {
            return current->getData();
        }
        else if(ID < current->getData()->getID())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }
    return nullptr;
}
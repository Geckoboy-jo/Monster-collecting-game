#include "plant.hpp"

class Node
{
private:
    Node* left;
    Node* right;
    plant* data;
public:
    Node(plant* newData) : data(newData), left(nullptr), right(nullptr){}
    ~Node(){delete data;}
    //getters and setters
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
    plant* getData(){return data;}

    void setLeft(Node* newLeft){left = newLeft;}
    void setRight(Node* newRight){right = newRight;}
    void setData(plant* newData){data = newData;}

};

class BST
{
private:
    Node* root;
    void destroyTree(Node* node);
public:
    BST() : root(nullptr){}
    ~BST(){destroyTree(root);}
    //getters and setters
    Node* getRoot(){return root;}
    void setRoot(Node* newRoot){root = newRoot;}
    //public member functions
    void insert(plant* newPlant);
    plant* search(float ID);

};


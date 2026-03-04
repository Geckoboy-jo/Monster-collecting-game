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
    Node* pRoot;
    //priavate member functions
    void destroyTree(Node* node);
    void printInOrder(Node* node);
    void insert(Node* newNode, Node* pNode);
public:
    BST() {pRoot = nullptr;}
    ~BST(){destroyTree();}
    //getters and setters
    Node* getRoot(){return pRoot;}
    void setRoot(Node* newRoot){pRoot = newRoot;}
    //public member functions
    void insert(plant* newPlant);
    plant* search(float ID);
    void printInOrder();
    void destroyTree();

};


#ifndef TREES_TREES_H
#define TREES_TREES_H

class Node{
public:
    int value;
    Node * left;
    Node * right;
    Node(int value){
        this->value = value;
        left = NULL;
        right = NULL;
    }
};


class BST{
    Node * root;
public:
    BST(){
        root = NULL;
    }
    void insertNode(int value);
    void removeNode(int value);
    void printPreOrder();
    Node * findAndRemovePreOrderPredecessor(Node * node);
private:
    void printPreOrder(Node * node);
};


#endif //TREES_TREES_H


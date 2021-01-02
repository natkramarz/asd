#ifndef TREES_TREES_H
#define TREES_TREES_H

class Node{
public:
    int value;
    Node * left;
    Node * right;
    int height;
    Node(int value){
        this->value = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class Tree{
public:
    Node * root;
    Tree(): root{NULL}{};
    void inorder();
    void inorder(Node * node);
    void preorder();
    void preorder(Node * node);
};

class BST: public Tree{
public:
    void insertNode(int value);
    void removeNode(int value);
    Node * findAndRemovePreOrderPredecessor(Node * node);
private:
    void insertNode(int value, Node * node);
    Node * findNodeAndItsParent(int value, Node * node, Node *& parent);
};

class AVL: public Tree{
public:
    void updateHeight(Node * node);
    int balanceFactor(Node * node);
    Node * rightRotation(Node * node);
    Node * leftRotation(Node * node);
    Node * rlRotation(Node * node);
    Node * lrRotation(Node * node);
    void insertNode(int value);
    int height(Node * node);
private:
    Node * insertNode(int value, Node * node);
};

#endif //TREES_TREES_H


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
    int height(Node * node);
    void updateHeight(Node * node);
    int balanceFactor(Node * node);
    Node * rightRotation(Node * node);
    Node * leftRotation(Node * node);
    void insertNode(int value);
    void deleteNode(int value);
    Node * findPredecessor(Node * node);
private:
    Node * insertNode(int value, Node * node);
    Node * deleteNode(int value, Node * node);
};

class RedBlackTree{
    struct node{
        int value;
        int colour; // 0 - black, 1 - red
        node * left;
        node * right;
        node * parent;
        node(int value, int colour, node * parent, node * left, node * right){
            this->value = value;
            this->colour = colour;
            this->parent = parent;
            this->left = left;
            this->right = right;
        }
    };
public:
    node * root;
    node * nil;
    RedBlackTree(){
        nil = new node(-1, 0, NULL, NULL, NULL);
        root = nil;
    };
    node * leftRotation(node * x);
    node * rightRotation(node * n);
    void insertNode(int value);
    void deleteNode(int value);
    void insertFixUp(node * n);
    void inorder();
    void transplant(node *u, node *v);
    void deleteFixup(node * x);
    node * findTreeMinimum(node * n);
private:
    node * deleteNode(node * n);
    node * inorder(node * n);
};

#endif //TREES_TREES_H


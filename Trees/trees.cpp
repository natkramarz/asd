#include "trees.h"

void Tree::inorder() {
    inorder(root);
}

void Tree::inorder(Node * node) {
    if(node->left != NULL){
        inorder(node->left);
    }
    std::cout << node->value << " ";
    if(node->right != NULL){
        inorder(node->right);
    }
}

void Tree::preorder() {
    preorder(root);
}
void Tree::preorder(Node * node){
    std::cout << node->value << " ";
    if(node->left != NULL){
        preorder(node->left);
    }
    if(node->right != NULL){
        preorder(node->right);
    }
}

void BST::insertNode(int value) {
    insertNode(value, root);
}

void BST::insertNode(int value, Node * node) {
    if(root == NULL){
        root = new Node(value);
        return;
    }
    if(node->value > value){
        if(node->left == NULL){
            node->left = new Node(value);
        }
        else{
            insertNode(value, node->left);
        }
    }
    else{
        if(node->right == NULL){
            node->right = new Node(value);
        }
        else {
            insertNode(value, node->right);
        }
    }
}

Node * BST::findNodeAndItsParent(int value, Node * node, Node *& parent) {
    Node * tmp = root;
    Node * tmpParent = NULL;
    while(tmp != NULL && tmp->value != value){
        tmpParent = tmp;
        if(tmp->value > value){
            tmp = tmp->left;
        }
        else{
            tmp = tmp->right;
        }
    }
    parent = tmpParent;
    return tmp;
}

void BST::removeNode(int value) {
    Node * parent = NULL;
    Node * tmp = NULL;
    tmp = findNodeAndItsParent(value, root, parent);
    if(tmp == NULL) return;
    if(tmp->left == NULL && tmp->right == NULL){
        if(parent->left == tmp){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
        delete tmp;
        return;
    }
    if(tmp->left == NULL){
        if(parent->left == tmp){
            parent->left = tmp->right;
        }else{
            parent->right = tmp->right;
        }
        delete tmp;
        return;
    }
    if(tmp->right == NULL){
        if(parent->left == tmp){
            parent->left = tmp->left;
        }else{
            parent->right = tmp->left;
        }
        delete tmp;
        return;
    }
    if(tmp == root){
        Node * node = findAndRemovePreOrderPredecessor(root);
        node->left = root->left;
        node->right = root->right;
        delete root;
        root = node;
        return;
    }
    Node * predecessor = findAndRemovePreOrderPredecessor(tmp);
    if(tmp == parent->left){
        parent->left = predecessor;
    }else{
        parent->right = predecessor;
    }
    predecessor->left = tmp->left;
    predecessor->right = tmp->right;
    delete tmp;

}


Node * BST::findAndRemovePreOrderPredecessor(Node * node) {
    Node * tmpParent = node;
    Node * tmp = node->left;
    if(tmp->right == NULL){
        tmpParent->left = NULL;
        return tmp;
    }
    while(tmp->right != NULL){
        tmpParent = tmp;
        tmp = tmp->right;
    }
    tmpParent->right = NULL;
    return tmp;
}

int AVL::balanceFactor(Node *node) {
    if(node == NULL) return 0;
    return height(node->left) - height(node->right);
}

void AVL::insertNode(int value) {
    root = insertNode(value, root);
}

int AVL::height(Node *node) {
    if(node == NULL) return 0;
    return node->height;
}

void AVL::updateHeight(Node *node) {
    node->height = 1 + std::max(height(node->left), height(node->right));
}

Node * AVL::insertNode(int value, Node * node) {
    if(node == NULL){
        Node * newNode = new Node(value);
        return newNode;
    }
    if(node->value > value){
        node->left = insertNode(value, node->left);
    }
    else if(node->value < value){
        node->right = insertNode(value, node->right);
    }
    else
        return node;

    updateHeight(node);
    int balance = balanceFactor(node);

    if(balance > 1){
        if(value > node->left->value){
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
        else if(value < node->left->value){
            return rightRotation(node);
        }

    }

    if(balance < -1){
        if(value > node->right->value){
            return leftRotation(node);
        }
        else if(value < node->right->value){
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
    }

    return node;
}

Node * AVL::leftRotation(Node * x) {
    Node * y = x->right;
    Node * t2 = y->left;
    x->right = t2;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node * AVL::rightRotation(Node * y) {
    Node * x = y->left;
    Node * t2 = x->right;
    y->left = t2;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}
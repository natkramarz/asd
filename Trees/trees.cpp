#include "trees.h"

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

void BST::printPreOrder() {
    printPreOrder(root);
}

void BST::printPreOrder(Node * node) {
    if(node->left != NULL){
        printPreOrder(node->left);
    }
    std::cout << node->value << " ";
    if(node->right != NULL){
        printPreOrder(node->right);
    }
}
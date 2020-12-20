#include "trees.h"

void BST::insertNode(int value) {
    if(root == NULL){
        root = new Node(value);
        return;
    }
    Node * tmp = root;
    while(tmp != NULL){
        if(tmp->value > value){
            if(tmp->left != NULL){
                tmp = tmp->left;
            }else{
                tmp->left = new Node(value);
                break;
            }
        }
        else{
            if(tmp->right != NULL){
                tmp = tmp->right;
            }else{
                tmp->right = new Node(value);
                break;
            }
        }
    }
}

void BST::removeNode(int value) {
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
    if(tmp == NULL) return;
    if(tmp->left == NULL && tmp->right == NULL){
        if(tmpParent->left == tmp){
            tmpParent->left = NULL;
        }
        else{
            tmpParent->right = NULL;
        }
        delete tmp;
        return;
    }
    if(tmp->left == NULL){
        if(tmpParent->left == tmp){
            tmpParent->left = tmp->right;

        }else{
            tmpParent->right = tmp->right;
        }
        delete tmp;
        return;
    }
    if(tmp->right == NULL){
        if(tmpParent->left == tmp){
            tmpParent->left = tmp->left;

        }else{
            tmpParent->right = tmp->left;
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
    if(tmp == tmpParent->left){
        tmpParent->left = predecessor;
    }else{
        tmpParent->right = predecessor;
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
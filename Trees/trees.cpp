#include "trees.h"

void Tree::inorder() {
    inorder(root);
    std::cout << std::endl << std::endl;
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
    std::cout << std::endl << std::endl;
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

void AVL::deleteNode(int value){
    root = deleteNode(value, root);
}

Node * AVL::findPredecessor(Node * node){
    Node * tmp = node->right;
    if(tmp == NULL) return NULL;
    Node * tmpParent = node;
    while(tmp->left != NULL){
        tmpParent = tmp;
        tmp = tmp->left;
    }
    if(node == tmpParent) node->right = tmp->right;
    else
        tmpParent->left = tmp->right;
    return tmp;
}

Node * AVL:: deleteNode(int value, Node * node){
    if(node == NULL){
        return node;
    }
    if(value < node->value){
        node->left = deleteNode(value, node->left);
    }
    else if(value > node->value){
        node->right = deleteNode(value, node->right);
    }
    else{
        Node * tmp;
        if(node->left == NULL && node->right == NULL){
            tmp = NULL;
        }
        else if(node->left != NULL && node->right == NULL){
            tmp = node->left;
        }
        else if(node->right != NULL && node->left == NULL){
            tmp = node->right;
        }
        else{
            tmp = findPredecessor(node);
            tmp->left = node->left;
            tmp->right = node->right;
        }
        if(root == node) root = NULL;
        delete node;
        return tmp;
    }
    updateHeight(node);
    int balance = balanceFactor(node);

    if(balance > 1){
        if(balanceFactor(node->left) >= 0){
            return rightRotation(node);
        }
        else{
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
    }
    if(balance < -1){
        if(balanceFactor(node->right) <= 0){
            return leftRotation(node);
        }
        else{
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
    }

    return node;
}

RedBlackTree::node * RedBlackTree::leftRotation(node * x) {
    node * y = x->right;
    x->right = y->left;
    if(y->left != nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil){
        root = y;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    return x;
}

RedBlackTree::node * RedBlackTree::rightRotation(node * y) {
    node * x = y->left;
    y->left = x->right;
    if(x->right != nil){
        x->right->parent = y;
    }
    x->parent = y->parent;
    if(y->parent == nil){
        root = x;
    }
    else if(y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void RedBlackTree::insertNode(int value) {
    node * y = nil;
    node * x = root;
    while(x != nil){
        y = x;
        if(value < x->value){
            x = x->left;
        }
        else x = x->right;
    }
    node * z = new node(value, 1, y, nil, nil);
    if(y == nil){
        root = z;
    }
    else if(z->value < y->value){
        y->left = z;
    }
    else y->right = z;
    insertFixUp(z);
}

void RedBlackTree::insertFixUp(node *z) {
    while(z->parent->colour == 1){
        if(z->parent == z->parent->parent->left){
            node * y = z->parent->parent->right; // uncle
            if(y->colour == 1){
                z->parent->colour = 0;
                y->colour = 0;
                z->parent->parent->colour = 1;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotation(z);
                }
                z->parent->colour = 0;
                z->parent->parent->colour = 1;
                rightRotation(z->parent->parent);
            }
        }
        else{
            node * y = z->parent->parent->left;
            if(y->colour == 1){
                z->parent->colour = 0;
                y->colour = 0;
                z->parent->parent->colour = 1;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->left){
                    z = z->parent;
                    rightRotation(z);
                }
                z->parent->colour = 0;
                z->parent->parent->colour = 1;
                leftRotation(z->parent->parent);
            }
        }
    }
    root->colour = 0;
};

void RedBlackTree::inorder() {
    inorder(root);
    std::cout << std::endl << std::endl;
}

RedBlackTree::node * RedBlackTree::inorder(node *n) {
        if(n->left != nil){
            inorder(n->left);
        }
        std::cout << n->value << ": colour: " << n->colour << ", ";
        if(n->right != nil){
            inorder(n->right);
        }
}

void RedBlackTree::deleteNode(int value) {
    node * tmp = root;
    while(tmp != nil && tmp->value != value){
        if(tmp->value < value)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    if(tmp == nil) return;
    deleteNode(tmp);

}

RedBlackTree::node * RedBlackTree::findTreeMinimum(node *n) {
    if(n == nil) return nil;
    while(n->left != nil){
        n = n->left;
    }
    return n;
}

RedBlackTree::node * RedBlackTree::deleteNode(node *z) {
    node * y = z;
    node * x;
    int y_original_colour = y->colour;
    if(z->left == nil){
        x = z->right;
        transplant(z, z->right);
    }
    else if(z->right == nil){
        x = z->left;
        transplant(z, z->left);
    }
    else{
        y = findTreeMinimum(z->right);
        y_original_colour = y->colour;
        x = y->right;
        if(y->parent == z){
            x->parent = y;
        }
        else{
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->colour = z->colour;
    }
    if(y_original_colour == 0) deleteFixup(x);
}

void RedBlackTree::deleteFixup(node *x) {
    while(x != root && x->colour == 0){
        if(x == x->parent->left){
            node * w = x->parent->right;
            if(w->colour == 1){
                w->colour = 0;
                x->parent->colour = 1;
                leftRotation(x->parent);
                w = x->parent->right;
            }
            if(w->left->colour == 0 && w->right->colour == 0){
                w->colour = 1;
                x = x->parent;
            }
            else{
                if(w->right->colour == 0){
                    w->left->colour = 0;
                    w->colour = 1;
                    rightRotation(w);
                    w = x->parent->right;
                }
                w->colour = x->parent->colour;
                x->parent->colour = 0;
                w->right->colour = 0;
                leftRotation(x->parent);
                x = root;
            }
        }
        else{
            node * w = x->parent->left;
            if(w->colour = 1){
                w->colour = 0;
                x->parent->colour = 1;
                rightRotation(x->parent);
                w = x->parent->left;
            }
            if(w->right->colour == 0 && w->left->colour == 0){
                w->colour = 1;
                x = x->parent;
            }
            else{
                if(w->left->colour == 0){
                    w->right->colour = 0;
                    w->colour = 1;
                    leftRotation(w);
                    w = x->parent->left;
                }
                w->colour = x->parent->colour;
                x->parent->colour = 0;
                w->left->colour = 0;
                rightRotation(x->parent);
                x = root;
            }
        }
    }
    x->colour = 0;
}

void RedBlackTree::transplant(node *u, node *v) {
    if(u->parent == nil) root = v;
    else if(u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    v->parent = u->parent;
}
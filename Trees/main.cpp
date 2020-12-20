#include <iostream>
#include "trees.cpp"

int main() {
    BST tree = BST();
    tree.insertNode(9);
    tree.insertNode(12);
    tree.insertNode(4);
    tree.insertNode(17);
    tree.insertNode(6);
    tree.insertNode(2);
    tree.insertNode(5);
    tree.insertNode(7);
    tree.insertNode(8);
    tree.insertNode(16);
    tree.removeNode(9);
    tree.printPreOrder();
    return 0;
}

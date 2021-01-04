#include <iostream>
#include "trees.cpp"

int main() {
    /* BST tree = BST();
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
    tree.preorder();
    AVL avl = AVL();
    avl.insertNode(14);
    avl.insertNode(17);
    avl.insertNode(11);
    avl.insertNode(7);
    avl.insertNode(53);
    avl.insertNode(4);
    avl.insertNode(13);
    avl.insertNode(12);
    avl.insertNode(8);
    avl.insertNode(60);
    avl.insertNode(19);
    avl.insertNode(16);
    avl.insertNode(20);
    avl.deleteNode(8);
    avl.deleteNode(7);
    avl.deleteNode(11);
    avl.deleteNode(14);
    avl.deleteNode(17);
    avl.inorder();
    std::cout << std::endl;
    avl.preorder(); */
    RedBlackTree Rbtree = RedBlackTree();
    Rbtree.insertNode(10);
    Rbtree.insertNode(18);
    Rbtree.insertNode(7);
    Rbtree.insertNode(15);
    Rbtree.insertNode(16);
    Rbtree.insertNode(30);
    Rbtree.insertNode(25);
    Rbtree.insertNode(40);
    Rbtree.insertNode(60);
    Rbtree.insertNode(2);
    Rbtree.insertNode(1);
    Rbtree.insertNode(70);
    Rbtree.deleteNode(18);
    Rbtree.deleteNode(70);
    Rbtree.deleteNode(10);
    Rbtree.deleteNode(16);
    Rbtree.inorder();

    return 0;
}

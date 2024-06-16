#include "BST.hpp"

int main () {
    BST<int> tree;
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);
    tree.insert(8);
    tree.insert(1);
    tree.insert(-2);
    // tree.insert(7);
    // tree.insert(9);
    tree.inorder();
}
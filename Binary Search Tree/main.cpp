#include <iostream>
#include "BinarySearchTree.h"

int main() {

    BinarySearchTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);

    std::cout << tree.getRoot()->getData() << std::endl;
    tree.remove(tree.getRoot(), 50);
    std::cout << tree.getRoot()->getData() << std::endl;

    return 0;
}
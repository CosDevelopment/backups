#include "trees.h"
#include<iostream>
int main(){

    Tree<int> myTree(8);
    myTree.insert(16);
    // myTree.insert(17);
    // myTree.insert(32);

    myTree.inOrder();

    return 0;
}
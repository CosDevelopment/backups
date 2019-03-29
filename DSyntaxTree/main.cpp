#include<iostream>
#include "DSyntaxTree.hpp"
int main(){
    DSyntaxTree tree ;
    tree.expression ="5X^2-10";
    tree.tokenize();
    tree.correctTokens();

}
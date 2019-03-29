#include<iostream>
#include "Dice.h"
using namespace std;


int main(){
    Dice *d1 = new Dice();
    Dice *d2 = new Dice();
    d1->hello();
    d2->hello();

    return 0;
}

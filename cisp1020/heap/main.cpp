#include<iostream>
#include "./Heap.h"
using namespace std;

int main(){

    Heap<int> ints([](int& first, int&second){ 
        if(first<second)
        return true ;
        else 
        return false;});
        ints.add(1);
        ints.add(5);
        ints.add(6);
        ints.add(2);
        ints.add(3);
        ints.add(4);
        ints.breadth();
        ints.removeMax();
        ints.breadth();
        ints.add(-2);
        ints.add(-3);
        ints.add(-4);
        ints.breadth();





    return 0;
}


#include "array.h"
#include<iostream>
main(){
    Disarray<int,5> array;
    array[0] = 30;
    array[1] = 60;
    array[2] = 90;
    array[3] = 120;
    array[4] = 160;

    for(auto i = array.begin();i!= array.end();i++){
        std::cout<<*i<<std::endl;
    }
}
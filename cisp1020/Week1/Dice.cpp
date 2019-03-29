#include "Dice.h"

Dice::Dice(){
 roll=10;
}

Dice::~Dice(){

}
void Dice::hello(){
    std::cout<<"Roll:"<<roll<<std::endl;
}
// #####################################################
// Preston Smith
// Cosc 302
// Dr.Emerich
// Project 2- adding large numbers using a linked list
// ###################################################






#include "LinkedList.h"
#include "BigNumberList.h"
#include <string>

using namespace std;
int main(){
string num1, num2;
    while(cin>>num1){
                cin>>num2;
        BigNumberList::add(num1,num2);
    }

    return 0;
}
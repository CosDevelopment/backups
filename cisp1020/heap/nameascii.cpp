#include<string>
#include<iostream>

using namespace std;

int main(){

 string name = "Qal";
 int value;
 for(char x:name){
     value += (int)(x);
    }
    value *=3;
    value %=100;
 std::cout<<value<<endl;

}
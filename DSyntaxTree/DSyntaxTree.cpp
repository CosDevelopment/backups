#include "DSyntaxTree.hpp"
#include<string>
#include<iostream>
   /////////////////////////////////////////////
  // function tokenizes input expression     //
 //  modifies allocAmmount, and tokens ptr  //
/////////////////////////////////////////////
void DSyntaxTree::tokenize(){
    allocAmmount = expression.length()*4;
    tokens = (std::string*)malloc(sizeof(std::string)*allocAmmount);
    int i =0;
    for(char token:expression){ // reads over each character of the input expression, to build a rough tokens array
        
        if(token =='X'){
        tokens[i]=std::string(1,'*');
        tokens[++i]=std::string(1,',');
        tokens[++i]=std::string(1,'X');

        }
        else{
        tokens[i]=std::string(1,token);
        }
        tokens[++i]=std::string(1,',');
        i++;
    }
    for(int i=0;i<allocAmmount;i++){
       std::cout<<tokens[i];
    }
    correctTokens();   // calls function to fix tokens ( ie: 1,0,0 to 100. s,i,n, to sin)
}
void DSyntaxTree::correctTokens(){
    tokenCorrections =(std::string*)malloc(sizeof(std::string)*allocAmmount);
    for(auto i =0; i <  allocAmmount;i++){
        //........TODO..........//
    }
    delete tokens;  // free's memory token's uses;
    tokens = nullptr; // sets the ptr to null;
}
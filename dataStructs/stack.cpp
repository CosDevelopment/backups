#include<iostream>
using namespace std;

class MyStack{
public:
   MyStack(MyStack &x){
      thisStack=x;
    }
   MyStack(){

   };
   MyStack thisStack = new MyStack();
   int digit;
   MyStack* predecessor;
   void push(int x){
       predecessor = &thisStack
       thisStack = new MyStack();
       thisStack.digit =x;
       thisStack.predecessor = predecessor;
    }
    void print(){
        cout<< thisStack.digit;
        cout<< thisStack.predecessor->print();
    }

};
int main(){
     MyStack stack;
     MyStack baseStack = new MyStack();
     baseStack.digit = 0;
     baseStack.predecessor=&baseStack; 
     stack.push(1);
     stack.push(2);
     stack.push(3);
     stack.print(); 


}

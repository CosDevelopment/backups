#pragma once
#include <cstdlib>
#include <iostream>
#include<queue>
template <class T>
class Tree
{
    T value;
    Tree<T> *left;
    Tree<T> *right;
    Tree();
    int level = 0;
  public:
    Tree(T val);
    void preOrder();
    void postOrder();
    void inOrder();
    void breadthFirst();
    Tree<T> *Root();
    void insert(T val);
};
template <class T>
Tree<T>::Tree(T val)
{
    value = val;
    left = right = NULL;
}

template <class T>
void Tree<T>::preOrder()
{
    std::cout << value << ", " << std::endl;
    if (left != NULL)
        (left)->preOrder();
    if (right != NULL)
        (right)->preOrder();
}
template <class T>
Tree<T> *Tree<T>::Root()
{
    return value;
}
template <class T>
void Tree<T>::insert(T val)
{
    if (value < val && right == NULL)
    {

        right = new Tree(val);
    }
    else if (value > val && left == NULL)
    {
        left = new Tree(val);
    }
    else if (value < val)
    {
        (right)->insert(val);
    }
    else if (value > val)
    {
        (left)->insert(val);
    }
}
template <class T>
void Tree<T>::postOrder()
{
        
    if (left != NULL)
        (left)->postOrder();
    if (right != NULL)
        (right)->postOrder();
    std::cout << value << ", " << std::endl;
}
template <class T>
void Tree<T>::inOrder()
{
        
    if (left != NULL)
        (left)->inOrder();
        std::cout << value << ", " << std::endl;
    if (right != NULL)
        (right)->inOrder();
    }
template <class T>
void Tree<T>::breadthFirst(){
    std::queue<Tree*> breadthQueue;
    Tree* temp;
    std::cout<<value<<" "; 
    breadthQueue.push(left);
    breadthQueue.push(right);
    while(!breadthQueue.empty()){
        temp = breadthQueue.front();
        breadthQueue.pop();
        std::cout<<temp->value<<" ";
        if(temp->left != NULL)
        breadthQueue.push(temp->left);
        if(temp->right != NULL)
        breadthQueue.push(temp->right);
    }
    
  
}

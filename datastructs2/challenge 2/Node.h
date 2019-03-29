#pragma once
#include<cstdlib>
template <class type>
class Node{
public:
    type data;
    Node<type>* next=NULL;
    Node<type>* prev = NULL;
};
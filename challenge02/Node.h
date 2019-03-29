#pragma once
#include<memory>
#include <cstdlib>
using namespace std;
//simple node for a linked list.
template <class T>
class Node
{
  public:
    T data;
    shared_ptr<Node<T>> next ;
    shared_ptr<Node<T>> prev ;
};
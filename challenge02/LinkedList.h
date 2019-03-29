#pragma once
#include "Node.h"
#include <cstdlib>
#include <iostream>
#include<memory>

using namespace std;
// linked list I wrote 2 years ago. some of the functions may not work, but the ones needed for the assignment does. 
template <class T>
class LinkedList
{

  public:
    shared_ptr<Node<T>> head = NULL ;
    shared_ptr<Node<T>> tail = NULL;
    void insertNode(T data);
    LinkedList(){};
    ~LinkedList();
    void insertFront(T data);
    void removeFront();
    void removeBack();
    void walkF();
    void walkB();
};

template <class T>
LinkedList<T>::~LinkedList()
{
\
}

template <class T>
void LinkedList<T>::insertNode(T data)
{
    if (head == NULL)
    {
        shared_ptr<Node<T>> x(new Node<T>());
        x->data = data;
        x->next = NULL;
        x->prev = NULL;
        head = x;
        return;
    }
    Node<T> *p = new Node<T>();
    for (p = head; p->next != NULL; p = p->next)
        ;
    shared_ptr<Node<T>> x(new Node<T>());
    x->data = data;
    x->next = NULL;
    x->prev = p;
    p->next = x;
    tail = x;
}

template <class T>
void LinkedList<T>::insertFront(T data)
{
    shared_ptr<Node<T>> x(new Node<T>());
    if (head != NULL)
    {
        x->data = data;
        x->next = head;
        x->prev = NULL;
        head->prev = x;
        head = x;
    }
    else
    {
        x->data = data;
        x->next = head;
        x->prev = NULL;
        head = x;
    }
}

template <class T>
void LinkedList<T>::walkF()
{
    shared_ptr<Node<T>> p(new Node<T>());
    for (p = head; p != NULL; p = p->next)
    {
        std::cout << p->data << std::endl;
    }
}

template <class T>
void LinkedList<T>::removeFront()
{
    
    head = head->next;
    head->prev = NULL;
}

template <class T>
void LinkedList<T>::removeBack()
{
    shared_ptr<Node<T>> p(new Node<T>());
    for (p = head; (p->next) != NULL && (p->next)->next != NULL; p = p->next)
        ;
    p->next = NULL;
    tail = p;
}

template <class T>
void LinkedList<T>::walkB()
{
    shared_ptr<Node<T>> p(new Node<T>());
    for (p = tail; p != NULL; p = p->prev)
    {
        std::cout << p->data << std::endl;
    }
}

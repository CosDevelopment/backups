#pragma once
#include "Node.h"
#include <cstdlib>
#include<iostream>
template <class type>
class LinkedList{
 Node<type>* head = NULL;
 Node<type>* tail = NULL;
 public:
void insertNode(type data);
void insertFront(type data);
void removeFront();
void removeBack();
void walkF();
void walkB();
void walkB2();

};
template <class type>
void LinkedList<type>::insertNode(type data){
    if(head==NULL){
    Node<type> *x = new Node<type>();
    x->data = data;
    x->next = NULL;
    x->prev = NULL;
    head = x;
    return;
}
 Node<type> *p = new Node<type>(); 
    for(p = head; p->next != NULL; p = p->next);
    Node<type> *x = new Node<type>();
    x->data = data;
    x->next = NULL;
    x->prev = p;
    p->next = x;
    tail=x;


}

template <class type>
void LinkedList<type>::insertFront(type data){
    Node<type> *x = new Node<type>();
    if(head !=NULL){
    x->data = data;
    x->next = head;
    x->prev = NULL;
    head->prev = x;
    head = x;
}
else{
    x->data = data;
    x->next = head;
    x->prev = NULL;
    head = x;
}

}

template <class type>
void LinkedList<type>::walkF(){
    Node<type> *p = new Node<type>(); 
    for(p = head; p != NULL; p = p->next){
        std::cout<<p->data<<std::endl;
    }

}

template <class type>
void LinkedList<type>::removeFront(){
    head = head->next;
    head->prev = NULL;
}

template <class type>
void LinkedList<type>::removeBack(){
    Node<type> *p = new Node<type>(); 
    for(p = head; (p->next) != NULL && (p->next)->next != NULL; p = p->next);
    p->next = NULL;
    tail = p;
}

template <class type>
void LinkedList<type>::walkB(){
LinkedList<type> walkb ;
Node<type> *p = new Node<type>(); 
    for(p = head; p != NULL; p = p->next){
        walkb.insertFront(p->data);
    }
    walkb.walkF();
}

template <class type>
void LinkedList<type>::walkB2(){
Node<type> *p = new Node<type>(); 
    for(p = tail; p != NULL; p = p->prev){
        std::cout<<p->data<<std::endl;
    }
}
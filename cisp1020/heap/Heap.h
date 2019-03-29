#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
template <class T>
class Heap
{

  protected:
    Heap *left;                              ///   left is the left child of the heap tree segment
    Heap *right;                             ///    right is the right child of the heap tree segment
    Heap *beingProcessed;                    /// Node who is being inserted into, or having values swapped, this is for processing
    Heap *previouslyProcessed;               /// The previously processed node
    std::vector<Heap *> processVector;       /// This vector holds the nodes in the order that is needed to process and insert new nodes
    T value;                                 ///     value is the data that will be held by this node of the heap tree
    bool (*comparator)(T &first, T &second); // comparator function for the sort function
    int location;                            // which element of the vector we are currently on

    Heap(T data) // internal protected constructor, this is so you dont have to constantly pass the comparator function since this is handled by the root node.
    {
        left = NULL;  /// initializes left tree
        right = NULL; ///  initializes the right tree
        value = data; ///   sets data to the data in the constructor
    }

  public:
    Heap(T data, bool (*func)(T &first, T &second)) // constructor with sort
    {
        left = NULL;       /// initializes left tree
        right = NULL;      ///  initializes the right tree
        value = data;      ///   sets data to the data in the constructor
        comparator = func; // sets the comparator function based on the input comparator function;
    };
        Heap(bool (*func)(T &first, T &second)) // constructor with sort, no data
    {
        left = NULL;       /// initializes left tree
        right = NULL;      ///  initializes the right tree
        comparator = func; // sets the comparator function based on the input comparator function;
    };

    void add(T data)// adds data value to heap, inserts node into processing vector, and calls sort function
    {

        if (processVector.empty())
        {
            value = data;
            processVector.push_back(this);     /// pushes the root into the vector
            location = 0;                      ///  sets the location at the beginning of the vector
            beingProcessed = processVector[0]; ///  initalizes the processing node as root.
        }
        else if (beingProcessed->left == NULL)
        {
            beingProcessed->left = new Heap<T>(data);      //Initalizes the left tree with the data inserted if the left value is null
            processVector.push_back(beingProcessed->left); //Pushes a node for later processing
        }
        else if (beingProcessed->right == NULL)
        {
            beingProcessed->right = new Heap<T>(data);      //initalizes the right tree witht the data inserted if left is !null and right is.
            processVector.push_back(beingProcessed->right); //pushes the right side of the current node into the vector.
            previouslyProcessed = beingProcessed;
            beingProcessed = processVector[++location]; //sets the next node of the vector as "being processed";
        }
    };
    void sort(std::vector<Heap *> processVec) // sorts and swaps based on the passed comparator functionm this is an internal utility function;
    {
        for (auto i = processVec.rbegin(); i != processVec.rend(); i++)
        {
            if ((*i)->left != NULL)
            {
                if (comparator((*i)->value, ((*i)->left)->value))
                    std::swap((*i)->value, ((*i)->left)->value);
            }
            if ((*i)->right != NULL)
            {
                if (comparator((*i)->value, ((*i)->right)->value))
                    std::swap((*i)->value, ((*i)->right)->value);
            }
        }
    }
    T removeMax()// removes root value, sets its new value as the last insterted child, then sorts for a new max;
    { 
        sort(processVector);
        T data = processVector[0]->value;
        processVector[0]->value = (processVector.back())->value;
        processVector.pop_back();
        if (beingProcessed->right == NULL)
        {
            beingProcessed->left = NULL;
        }
        else
        {
            previouslyProcessed->right = NULL;
            beingProcessed = previouslyProcessed;
            location--;
        }
        return data;
    }
    void breadth() //breadth-first traversal
    {
        std::queue<Heap<T> *> breadthQueue;
        Heap<T> *temp;
        std::cout << value << " ";
        if (left != NULL)
            breadthQueue.push(left);
        if (right != NULL)
            breadthQueue.push(right);
        while (!breadthQueue.empty())
        {
            temp = breadthQueue.front();
            breadthQueue.pop();
            std::cout << temp->value << " ";
            if (temp->left != NULL)
                breadthQueue.push(temp->left);
            if (temp->right != NULL)
                breadthQueue.push(temp->right);
        }
        std::cout << "\n";
    };
    int size()   /// returns the size of the internal processing vector
    {

        return processVector.size();
    };
    bool isEmpty()  // returns whether the internal processing vector is empty;
    {
        return processVector.empty();
    };
};

/*
static queue<Heap<T>*>process
if left has both children
process.push(left->left)
process.push(left->right)
if right has both children
process.push(right->left)
process.push(right -> right)
*/
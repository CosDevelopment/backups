#pragma once

#include "LinkedList.h"
// class with functions to process the input and generate a linked list;
class BigNumberList
{
  public:
    BigNumberList(){};
    ~BigNumberList(){};
    static void add(string list1, string list2);
    static void output(const LinkedList<int> &answer);
};

// this is super super sloppy but it uses string iterators so that it can covert each character into an int, do some math, then input into the list
void BigNumberList::add(string list1, string list2)
{
    LinkedList<int> answer;
    int intAdd = 0, carry = 0;
    auto list2It = list2.rbegin();
    auto list1It = list1.rbegin();
    int list2NumToAdd = *list2It - '0';
    int list1NumToAdd = *list1It - '0';

    while (list2It != list2.rend() || list1It != list1.rend() || carry)
    {

        intAdd += (list1NumToAdd) + (list2NumToAdd) + carry;
        answer.insertFront(intAdd % 10);
        carry = intAdd / 10;
        intAdd = 0;
        if (list2It != list2.rend())
        {
            list2It++;
            if(list2It != list2.rend())
            list2NumToAdd = *list2It - '0';
            else{
                list2NumToAdd =0;
            }
        }
        else
        {
            list2NumToAdd = 0;
        }
        if (list1It != list1.rend())
        {
            list1It++;
            list1NumToAdd = *list1It - '0';

            if(list1It != list1.rend())
            list1NumToAdd = *list1It - '0';
            else{
                list1NumToAdd =0;
            }
        }
        else
        {
            list1NumToAdd = 0;
        }
    }

    output(answer);
}
// just outputs each node of the list.
void BigNumberList::output(const LinkedList<int> &answer)
{

    shared_ptr<Node<int>> p(new Node<int>());
    for (p = answer.head; p != NULL; p = p->next)
    {
        std::cout << p->data;
    }
    cout << std::endl;
}
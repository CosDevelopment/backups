// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Node
{
	std::string string;
	int number;
	std::shared_ptr<Node> next;
};

struct List
{
	std::shared_ptr<Node> head;
	size_t size = 0;
	//Not defined in .cpp because they do not do anything specific in this application
	List(){};  // define in list.cpp
	~List(){}; // define in list.cpp

	void push_front(const std::string &s); //define below
};

// Functions -------------------------------------------------------------------

void List::push_front(const std::string &s)
{
	size++;
	if (head == NULL)
	{
		shared_ptr<Node> x(new Node());
		x->next = NULL;
		x->string = s;
		head = x;
		return;
	}
	std::shared_ptr<Node> p(new Node());
	for (p = head; p->next != NULL; p = p->next)
		;
	shared_ptr<Node> x(new Node());
	x->string = s;
	p->next = x;
};

//Just compares the numerical value of the pointers
int qnode_number_compare(const void *a, const void *b)
{
	Node *c = *(Node **)a;
	Node *d = *(Node **)b;
	c->number = stoi(c->string);
	d->number = stoi(d->string);
	if (c->number < d->number)
	{
		return 1;
	}
	else
	{
		return 0;
	}

};

//Compared the values of the strings within the pointers for qsort;
int qnode_string_compare(const void *a, const void *b)
{
	Node *c = *(Node **)a;
	Node *d = *(Node **)b;

	if (c->string.compare(d->string) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
};

//Compares the Numeric Value of the pointers for merge,stl, and quick
bool node_number_compare(const std::shared_ptr<Node> a, const std::shared_ptr<Node> b)
{
	a->number = stoi(a->string);
	b->number = stoi(b->string);
	if (a->number > b->number)
	{
		return true;
	}
	else
	{
		return false;
	}

}; //implement in this file (volsort.h), used by quick, merge and stl

//Compares the String Value of the pointers for merge,stl, and quick
bool node_string_compare(const std::shared_ptr<Node> a, const std::shared_ptr<Node> b)
{
	if (a->string.compare(b->string) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}; //implement in this file (volsort.h), used by quick, merge and stl

//################################################################################

//outputs the Nodes
void dump_node(std::shared_ptr<Node> n)
{
	for (std::shared_ptr<Node> curr = n; curr != NULL; curr = curr->next)
	{

		std::cout << curr->number << std::endl;

		std::cout << curr->string << std::endl;
	}

}; // implement in this file (volsort.h) to make it easier for TAs to grade

//############################## STL SORT ####################################

//Stores the links of the lsit in a vector and calls stl SORT on the vectors elements through interators.
void stl_sort(List &l, bool numeric)
{
	vector<shared_ptr<Node>> sortvec;
	for (std::shared_ptr<Node> curr = l.head; curr != NULL; curr = curr->next)
	{
		sortvec.push_back(curr);
	}
	if (numeric)
		std::sort(sortvec.begin(), sortvec.end(), node_number_compare);
	else
		std::sort(sortvec.begin(), sortvec.end(), node_string_compare);

	l.head = sortvec[0];
	for (int i = 0; i < sortvec.size(); i++)
		sortvec[i]->next = sortvec[i + 1];
};

//#############################################################################

//############################# QSORT_SORT######################################

//sorts through the list using C's qsort function. all the nodes of the list are inserted into an array for processing.
void qsort_sort(List &l, bool numeric)
{

	Node **sortarr = new Node *[l.size];
	int i = 0;
	vector<shared_ptr<Node>> sortvec;
	sortvec.resize(l.size);
	for (std::shared_ptr<Node> curr = l.head; curr != NULL; curr = curr->next)
	{
		sortarr[i] = curr.get();
		i++;
	}
	if (numeric)
		qsort(sortarr, l.size, sizeof(Node *), qnode_number_compare);
	else
		qsort(sortarr, l.size, sizeof(Node *), qnode_string_compare);

	for (int i = 0; i < l.size; i++)
	{
		//shared_ptr<Node> x ;

		sortvec[i] = shared_ptr<Node>(new Node());
		sortvec[i]->number = sortarr[i]->number;
		sortvec[i]->string = sortarr[i]->string;
	}

	for (int i = 0; i < sortvec.size() - 1; i++)
		sortvec[i]->next = sortvec[i + 1];

	l.head = sortvec[0];

	delete sortarr;
}; // define in qsort.cpp - sort using qsort from cstdlib

//################################################################################
//Failed attempt at Merge Sort
//#################################### MERGE SORT ################################
void merge_sort(List &l, bool numeric); // define in merge.cpp - your implementation

//################################################################################

//#################################### QUICK SORT ################################
// Failed attempt at Qsort
//################################################################################

std::shared_ptr<Node> concatenate(std::shared_ptr<Node> left, std::shared_ptr<Node> right)
{
	left->next = right;
	return left;
}

std::shared_ptr<Node> partition(std::shared_ptr<Node> &list, bool numeric)
{
	shared_ptr<Node> rightHead = NULL;
	shared_ptr<Node> right = NULL;
	shared_ptr<Node> left = NULL;
	shared_ptr<Node> leftHead = NULL;
	shared_ptr<Node> pivot = list;

	if (pivot->next != NULL)
	{
		shared_ptr<Node> l = pivot->next;
		if (numeric)
		{
			pivot->number = stoi(pivot->string);
			for (std::shared_ptr<Node> curr = l; curr != NULL; curr = curr->next)
			{
				curr->number = stoi(curr->string);
				if (pivot->number > curr->number)
				{
					if (leftHead == NULL)
					{
						leftHead = curr;
						left = leftHead;
					}
					else
					{
						left->next = curr;
						left = left->next;
					}
				}
				else
				{
					if (rightHead == NULL)
					{
						rightHead = curr;
						right = rightHead;
					}
					else
					{
						right->next = curr;
						right = right->next;
					}
				}
			}
		}
	}
	if (rightHead != NULL)
		partition(rightHead, numeric);
	if (leftHead != NULL)
		partition(leftHead, numeric);
	if (right != NULL)
		concatenate(right, pivot);
	else if(rightHead !=NULL)
	{
		concatenate(rightHead, pivot);
	}else
	{
		rightHead = pivot;
	}
	if (leftHead != NULL)
		concatenate(pivot, leftHead);
	return rightHead;
}

void quick_sort(List &list, bool numeric)
{
	List l = list;
	shared_ptr<Node> rightHead = NULL;
	shared_ptr<Node> right = NULL;
	shared_ptr<Node> left = NULL;
	shared_ptr<Node> leftHead = NULL;
	shared_ptr<Node> pivot = l.head;
	l.head = l.head->next;
	pivot->next = NULL;
	if (numeric)
	{
		pivot->number = stoi(pivot->string);
		for (std::shared_ptr<Node> curr = l.head; curr != NULL; curr = curr->next)
		{
			curr->number = stoi(curr->string);
			if (pivot->number > curr->number)
			{
				if (leftHead == NULL)
				{
					leftHead = curr;
					left = leftHead;
				}
				else
				{
					left->next = curr;
					left = left->next;
				}
			}
			else
			{
				if (rightHead == NULL)
				{
					rightHead = curr;
					right = rightHead;
				}
				else
				{
					right->next = curr;
					right = right->next;
				}
			}
		}
	}
	if (rightHead != NULL)
		partition(rightHead, numeric);
	if (leftHead != NULL)
		partition(leftHead, numeric);
	if (right != NULL)
		concatenate(right, pivot);
	else if(rightHead !=NULL)
	{
		concatenate(rightHead, pivot);
	}else
	{
		rightHead = pivot;
	}
	
	if (leftHead != NULL)
		concatenate(pivot, leftHead);

	dump_node(rightHead);
}

std::shared_ptr<Node> qsort(std::shared_ptr<Node> head, bool numeric)
{
}

//################################################################################

#endif

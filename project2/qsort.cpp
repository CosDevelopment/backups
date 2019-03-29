// qsort.cpp

#include "volsort.h"
#include <cstdlib>
#include <array>
#include <iostream>
#include<memory>



int qnode_number_compare(const void* a, const void* b)
{
	Node* c = *(Node**)a;
	Node* d = *(Node**)b;
	c->number = stoi(c->string);
	d->number = stoi(d->string);
	if (c->number > d->number)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}; 
int qnode_string_compare(const void* a, const void* b)
{
	Node* c = *(Node**)a;
	Node* d = *(Node**)b;
	
	if (c->string.compare(d->string) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
};

void qsort_sort(List &l, bool numeric){

	Node** sortarr = new Node*[l.size];
	int i=0;
	vector<shared_ptr<Node>> sortvec;
	sortvec.resize(l.size);
	for (std::shared_ptr<Node> curr = l.head; curr != NULL; curr = curr->next)
	{
		sortarr[i]=curr.get();
		i++;
	}
	if (numeric)
		qsort(sortarr, l.size,sizeof(Node*),qnode_number_compare);
	else
		qsort(sortarr, l.size,sizeof(Node*),qnode_string_compare);

	for (int i = 0; i < l.size; i++){
		//shared_ptr<Node> x ;
		
		sortvec[i] = shared_ptr<Node>(new Node());
		sortvec[i]->number = sortarr[i]->number;
		sortvec[i]->string = sortarr[i]->string;
		
	}
	
	for (int i = 0; i < sortvec.size()-1; i++)
	sortvec[i]->next=sortvec[i+1];

	l.head= sortvec[0];

	delete sortarr;
}; // define in qsort.cpp - sort using qsort from cstdlib

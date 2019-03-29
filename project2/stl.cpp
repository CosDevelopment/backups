// stl.cpp

#include "volsort.h"
#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;
void stl_sort(List &l, bool numeric) {
    vector<shared_ptr<Node>> sortvec;
	 for (std::shared_ptr<Node> curr = l.head; curr != NULL; curr = curr->next) {
		         sortvec.push_back(curr);
}
    if(numeric)
    std::sort(sortvec.begin(),sortvec.end(),node_string_compare);
    else
    std::sort(sortvec.begin(),sortvec.end(),node_string_compare);
}

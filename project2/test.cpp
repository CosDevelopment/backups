#include "volsort.h"
#include<iostream>
#include<string>


using namespace std;
int main(int argc, char const *argv[])
{
    
    List data;
    string x;
    cin>>x;
    while(cin>>x){
        data.push_front(x);
    }

 

    
    qsort_sort(data,true);
    dump_node(data.head);

    return 0;
}

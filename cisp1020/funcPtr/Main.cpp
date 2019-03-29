#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
using myFuncPtr = void (*)(int);
struct person
{
    string name;
    int age;
};

// bool bSearch(array<person,100> people,string name,int size){
//     bool result;
//     ;
//     if(size ==0 ||size >100){
//         return false;
//     }
//     else if(people[size/2].name>name){
//      result = bSearch(people,name,(size/2));
//      return result;
//     }
//     else if(people[size/2].name<name){
//     result = bSearch(people,name,(size+size/2));
//     return result;
//     }
//     else if(people[size/2].name==name){
//         return true;
//     }
//     else{
//         return false;
//     }
// };

int main()
{
    srand(time(NULL));
    ifstream file("names.txt");

    array<person, 100> people;
    for (auto i = 0; i < 100; i++)
    {
        file >> people[i].name;
        people[i].age = (rand() % 60 + 1);
    }
    sort(people.begin(), people.end(), [](person p1, person p2) 
    {
    return(p1.name<p2.name);
    });
    
    for (auto i = 0; i < 100; i++)
    {
        cout<<people[i].name<<" "<<people[i].age<<endl; 
    }


    return 0;
}

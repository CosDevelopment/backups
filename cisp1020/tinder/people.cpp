#include "people.h"
using namespace std;
/*
Function takes in users choice person. 
From the choice person, the searched person compares themselves against th users perfect choice, then assigns a value;
*/
void People::evaluate(People &choice)
{

    value = 0;
    if (nice == choice.nice || nice >= choice.niceImportance)
    {
        value+= choice.nice;
    }
    if (sport == choice.sport)
    {
        value++;
    }
    if(attractiveness >= choice.attractiveness || attractiveness >= choice.attractivenessImportance){
        value+= choice.attractiveness;
    }
     if (eyeColor == choice.eyeColor)
    {
        value++;
    }
        if (dress == choice.dress)
    {
        value++;
    }
        if (phone == choice.phone)
    {
        value++;
    }
        if (preferredClass == choice.preferredClass)
    {
        value++;
    }
    if(physique == choice.physique){
        value++;
    }
    if(intelligence == choice.intelligence || intelligence >= choice.intelligenceImportance){
        value += intelligence;
    }
};

/*
Function takes in an input file, a heap queuem and the choice person. This function builds people from a input file, then calls the evaluation function. returns nothing;
*/
void People::buildPeople(std::ifstream &infile, Heap<People> &heap, People &choice){
while(!infile.eof()){
    People match;
    infile >> match.name;
    infile >> match.hair;
    infile >> match.nice;
    infile >> match.sport;
    infile >> match.attractiveness;
    infile >> match.eyeColor;
    infile >> match.dress;
    infile >> match.phone;
    infile >> match.preferredClass;
    infile >> match.physique;
    infile >> match.intelligence;
    match.evaluate(choice);
   // cout<<match.name<<": "<<match.value<<endl;
    heap.add(match);

 }
};
//Takes in a person then prints all of their information for the user to see
void People::print(People match){
    cout << "Name:"<< match.name<<endl;
    cout << "Hair: "<<match.hair<<endl;
    cout <<"Nice value:"<<match.nice<<endl;;
    cout <<"Sports?:" ;
    if(match.sport == 1){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    cout <<"Attractiveness:"<<match.attractiveness<<endl;;
    cout <<"Eye color:"<<match.eyeColor<<endl;
    cout <<"Dress:"<<match.dress<<endl;
    cout <<"Phone:"<<match.phone<<endl;
    cout <<"DnD class:"<<match.preferredClass<<endl;
    cout <<"Physique:"<<match.physique<<endl;
    cout <<"Intelligence:"<<match.intelligence<<endl;
    cout<<"Rating:"<<match.value<<endl;
    cout<<"\n\n";
 }
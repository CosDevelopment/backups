#pragma once
#include<string>
#include<fstream>
#include "heap.h"
using namespace std;
class People{
public:
 string name;
 string hair;
 int nice;
 int niceImportance;
 bool sport;
 int attractiveness;
 int attractivenessImportance;
 string eyeColor;
 string dress;
 string phone;
 string preferredClass;
 string physique;
 int intelligence;
 int intelligenceImportance;
 int value;
 void evaluate(People &choice);
 static void buildPeople(std::ifstream &infile, Heap<People> &heap,People &choice);
 static void print(People match);
};


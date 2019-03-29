#include<cmath>
#include<cstdlib>
#include<fstream>
#include "Maze.h"
#include <string>
#include<iostream>

int main(){
srand(time(0));
Maze maze;
Mouse mousey;
std::cout << "hello" << std::endl;

std::string filename;
std::ifstream infile;
std::cout<<"Input filename:"<<std::endl;
std::cin>>filename;
infile.open(filename.c_str());
maze = MazeBuilder::build(infile);
mousey.search(maze);
return 0;
}
#include<fstream>
#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdlib>

struct MazeLocations{
    int x;
    int y;
};
class Maze{
    int width; 
    int height;
    MazeLocations startPos;
    std::string map[30];
    friend class MazeBuilder;
    friend class Mouse;   
 };
class MazeBuilder{ 

 public:
    static Maze build(std::ifstream &_maze);
};
 class Mouse{ // Stole the name of my Maze Search from josh.
 std::stack<MazeLocations> searchLocations;
 bool isSearching= true;
 public:
 void search(Maze _maze);

};



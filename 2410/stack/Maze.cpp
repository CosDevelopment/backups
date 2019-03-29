#include <ctime>
#include <fstream>
#include "Maze.h"
Maze MazeBuilder::build(std::ifstream &_maze)
{
    Maze maze;
    std::string line;
    _maze >> maze.height;
    _maze >> maze.width;
    _maze >> maze.startPos.x;
    _maze >> maze.startPos.y;
    for (int i = 0; i < maze.height; i++)
    {
        getline(_maze, line);
        maze.map[i] = (line + '\n');
    }
    return maze;
}
//1,0 0,1 -1,0 0,-1
void Mouse::search(Maze _maze)
{
    MazeLocations direction;
    MazeLocations location = _maze.startPos;
    while (isSearching)
    {
        if (!(location.x == 0 || location.x == _maze.width - 1) && !(location.y == 0 || location.y == _maze.height - 1))
        {
            if (!(_maze.map[location.x + 1][location.y] == '_' || _maze.map[location.x + 1][location.y] == '|' || _maze.map[location.x + 1][location.y] == '#' || _maze.map[location.x + 1][location.y] == '+'))
            {
                searchLocations.push(location);
                _maze.map[location.x][location.y] = '+';
                location.x++;
                std::cout << "push 1" << std::endl;
            }
            else if (!(_maze.map[location.x - 1][location.y] == '_' || _maze.map[location.x - 1][location.y] == '|' || _maze.map[location.x - 1][location.y] == '#' || _maze.map[location.x - 1][location.y] == '+'))
            {
                searchLocations.push(location);
                _maze.map[location.x][location.y] = '+';
                location.x--;
                std::cout << "push 2" << std::endl;
            }
            else if (!(_maze.map[location.x][location.y + 1] == '_' || _maze.map[location.x][location.y + 1] == '|' || _maze.map[location.x][location.y + 1] == '#' || _maze.map[location.x][location.y + 1] == '+'))
            {
                searchLocations.push(location);
                _maze.map[location.x][location.y] = '+';
                location.y++;
                std::cout << "push 3" << std::endl;
            }
            else if (!(_maze.map[location.x][location.y - 1] == '_' || _maze.map[location.x][location.y - 1] == '|' || _maze.map[location.x][location.y - 1] == '#' || _maze.map[location.x][location.y - 1] == '+'))
            {
                searchLocations.push(location);
                _maze.map[location.x][location.y] = '+';
                location.y--;
                std::cout << "push 4" << std::endl;
            }
            else
            {
                
                if (!searchLocations.empty())
                {
                    _maze.map[location.x][location.y] = '#';
                    location = searchLocations.top();
                    searchLocations.pop();
                    std::cout << "pop" << std::endl;
                }
                std::cout << "pop2" << std::endl;
                for (int i = 0; i < _maze.height; i++)
                {
                    std::cout << _maze.map[i];
                }
            }
        }
        else
        {
            isSearching = false;
        }
        
    }
}
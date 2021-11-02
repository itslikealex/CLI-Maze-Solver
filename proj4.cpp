#include "maze.h"

int main()
{
    Maze maze;
    maze.Print();
    std::cout << "Start Position: 1,1\n"; 
    bool foundE = false;
    maze.FindExit(1,1,foundE);
    if(foundE)
        std::cout << "Found Exit!\n";
    else
        std::cout << "No Exit!\n";
    return 0;
}


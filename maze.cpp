#include "maze.h"
#include <iostream>
#include <fstream> 
#include <string>

// Constructor: reads maze map from file and configures maze
Maze::Maze()
{
    std::ifstream mazeFile("readmaze.txt", std::ifstream::in);
    std::string m;
    std::getline(mazeFile, xplor);
    mazeFile >> maxRows >> maxCols;
    mazeFile.ignore(1024, '\n');
	for(int i = 0;i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
             mazeFile.get(maze[i][j]);
        mazeFile.get();
    }
    std::cout << "Maze State:\n"; 
    for(int i = 0;i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
            std::cout << maze[i][j] << " ";
        std::cout << "\n";
    }std::cout << "Start Position: 1,1\n";
};
// Displays the maze and its state
void Maze::Print()
{
    
};
// Recursive function that finds the exit (ints: row, then column)				
void Maze::FindExit(int, int, bool&)
{

};


 
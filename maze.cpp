#include "maze.h"
#include <iostream>
#include <fstream> 
#include <string>
// Constructor: reads maze map from file and configures maze
Maze::Maze()
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            maze[i][j] = 'X';
    std::ifstream mazeFile("readmaze.txt", std::ifstream::in);
    std::string m;
    std::getline(mazeFile, xplor);
    mazeFile >> maxRows >> maxCols;
    mazeFile.ignore(1024, '\n');
	for(int i = 1; i < maxRows + 1; i++)
    {
        for(int j = 1; j < maxCols + 1; j++)
             mazeFile.get(maze[i][j]);
        mazeFile.get();
    }
    
}
// Displays the maze and its state
void Maze::Print()
{
    std::cout << "Maze State:\n"; 
    for(int i = 1; i < maxRows + 1; i++)
    {
        for(int j = 1; j < maxCols + 1; j++)
            std::cout << maze[i][j] << " ";
        std::cout << "\n";
    }
}
// Recursive function that finds the exit (ints: row, then column)
void Maze::FindExit(int f, int s, bool& foundE)
{
	if(!foundE && maze[f][s] != 'X' && maze[f][s] != '*')
	{
		std::cout << "Exploring " << f << ", " << s << '\n';
		if(maze[f][s] == 'E') foundE = true;
		else
		{
			maze[f][s] = '*'; Print();
			for(int i = 0; i < 3; i++)
			{
                std::pair<int,int> xpl = getMove(xplor[i]);
                FindExit(f + xpl.first, s + xpl.second, foundE);
			}
		}
	}
}
// returns a pair (row, then column offset) from these values: (-1, 0, 1)
std::pair<int,int> Maze::getMove(char d)
 {
    std::pair<int,int> mv;
    int r, c;
    if(d == '1')
        {r = -1; c = 1;}
    if(d == '2')
        {r = 1; c = 1;}
    if(d == '3')
        {r = 1; c = -1;}
    if(d == '4')
        {r = -1; c = -1;}
    mv = std::make_pair(r,c);
    return mv;
 }

 
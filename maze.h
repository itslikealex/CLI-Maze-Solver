#ifndef MAZE_H
#define MAZE_H
#include <iostream> 
#include <fstream> 
#include <string>

class Maze								// Represents Maze class' data and function members
{ 
public: 
	Maze();								// Constructor: reads maze map from file and configures maze
	void Print();						// Displays the maze and its state
	void FindExit(int, int, bool&);		// Recursive function that finds the exit (ints: row, then column)
private: 
	char maze[10][10];					// 2D array that holds maze - outer columns and rows not traversable
	int maxRows;						// Maximum number of rows - excludes outer walls
	int maxCols;						// Maximum number of columns - excludes outer walls
	std::string xplor;					// 4-element string dictating order of maze exploration
	std::pair<int,int> getMove(char);	// returns a pair (row, then column offset) from these values: (-1, 0, 1)
};

#endif

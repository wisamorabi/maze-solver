//Maze header file

#pragma once
#include "cell.h"

class Maze
{
private:
	Cell * * arr; //Double pointer to cells (To create 2D array)
	Cell startCell, goalCell; //Stores the starting cell and goal cell (Will be used in DFS and BFS extensively)
	int height, width; // height <-> lines <-> rows | width <-> cells <-> columns
public:
	//------------------Constructor (Default | Non-default), copy constructor, destructor, assignment operator, equlity & inequality checks------------------
	Maze(int Nheight = 0, int Nwidth = 0); //Constructor (Default & Non-default)
	Maze(const Maze & other); //Copy constructor
	Maze operator=(const Maze & other); //Assignment operator
	~Maze(); //Destructor to clean up 2D array
	bool operator==(const Maze & other); //Equality check
	bool operator!=(const Maze & other); //Inequality check



	 //------------------Getters------------------
	int getHeight() const;
	int getWidth() const;

	//------------------Setters------------------
	void setStart(int Nrow, int Ncol);
	void setGoal(int Nrow, int Ncol);
	void setHeight(int Nheight);
	void setWidth(int Nwidth);
	//------------------Major functions------------------

	//Inserts a new cell into the maze (Takes cell object as parameter)
	void insertCell(Cell cell);

	//Function to display the maze object (The array)
	void displayMaze();

	//Function called for success of DFS and BFS
	void Success(Cell * goal);

	//Depth First Search, return boolean to indicates success or failure
	bool DFS();

	//Breadth First Search, return boolean to indicates success or failure
	bool BFS();
};

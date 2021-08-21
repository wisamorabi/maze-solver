//Cell header file

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Cell
{
private:
	int x, y; //Coordiantes (& Indices inside maze array)
	char status; //' ', @, *, S, G
	bool top, down, left, right; //Booleans to indicate if there is a barrier or not in all 4 directions
	Cell * prev; //Pointer to previous cell for backwards traversal when solution is found

public:
	//Constructor (Default & Non-default), copy constructor, No destructor (Default is sufficient for cell class), equal operator, comparison operators (== | !=)
	Cell(int Ny = -1, int Nx = -1, bool Nup = 0, bool Ndown = 0, bool Nleft = 0, bool Nright = 0, char Nstatus = ' ', Cell * Ncell = nullptr); //Constructor (Default & Non-default)
	Cell(const Cell & other); //Copy constructor
	Cell operator=(const Cell & other); //Assignment operator
	bool operator!=(const Cell & other); //Inequality Check
	bool operator==(const Cell & other); //Equality check

	//------------------Getters------------------
	bool getTop() const;
	bool getDown() const;
	bool getRight() const;
	bool getLeft() const;
	char getStatus() const;
	int getX() const;
	int getY() const;
	Cell * getPrev() const;

	//------------------Setters------------------
	void setStatus(char Nstatus); //Changes status to and from: ' ', @, *, S, G
	void setPrev(Cell * Nprev); //Sets the previous cell connected to this one
};

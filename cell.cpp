//Cell implementation file (.cpp)

#pragma once
#include "cell.h"


Cell::Cell(int Ny, int Nx, bool Nup, bool Ndown, bool Nleft, bool Nright, char Nstatus, Cell * Ncell)
	{
		y = Ny; x = Nx;
		status = Nstatus;
		//Cell's previous is set to nullptr by default as a safety measure and also to be able to traverse
		//The cell's to the start in the success function (Think of it as if it is a linked list)
		//The nullptr will be used in a the while loop inside the success function to allow us to stop looping
		Cell * prev = Ncell;
		top = Nup, down = Ndown, left = Nleft, right = Nright;
	}
Cell::Cell(const Cell & other)
	{
		y = other.y;
		x = other.x;
		status = other.status;
		prev = other.prev;
		top = other.top;
		down = other.down;
		left = other.left;
		right = other.right;
	}

	bool Cell::operator!=(const Cell & other)
	{
		return !(*this == other); //Simply !==
	}
	Cell Cell::operator=(const Cell & other)
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;
			status = other.status;
			prev = other.prev;
			top = other.top;
			down = other.down;
			left = other.left;
			right = other.right;
		}
		return *this; //To allow for CellObj1 = CellObj2 = CellObj3 = ...
	}
	bool Cell::operator==(const Cell & other)
	{
		if (
			//The x and the y are the one's that really really matter here.
			x != other.x ||
			y != other.y ||
			//Prev is ignored when checking for equality. The reason is because when comparing currentCell to goalCell (In DFS and BFS)
			//Only currentCell will have a previous and therefore the operator== would always return false even though the goalCell has been found!
			//Therefore, prev is NOT checked.
			//prev != other.prev ||
			status != other.status ||
			down != other.down ||
			left != other.left ||
			right != other.right
			)
			return false;
		return true;
	}

	//------------------Getters------------------
	bool Cell::getTop() const
	{
		return top;
	}
	bool Cell::getDown() const
	{
		return down;
	}
	bool Cell::getRight() const
	{
		return right;
	}
	bool Cell::getLeft() const
	{
		return left;
	}
	char Cell::getStatus() const
	{
		return status;
	}
	int Cell::getX() const
	{
		return x;
	}
	int Cell::getY() const
	{
		return y;
	}
	Cell * Cell::getPrev() const
	{
		return prev;
	}

	//------------------Setters------------------
	void Cell::setStatus(char Nstatus)
	{
		status = Nstatus;
	}
	void Cell::setPrev(Cell * Nprev)
	{
		prev = Nprev;
	}

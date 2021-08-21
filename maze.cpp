//Maze implementation file (.cpp)

#pragma once
#include "maze.h"


Maze::Maze(int Nheight, int Nwidth)
{
	height = Nheight;
	width = Nwidth;
	//Initialization of dynamic 2D array
	arr = new Cell*[height];
	for (int i = 0; i < height; i++)
	{
		arr[i] = new Cell[width];
	}
}
Maze::Maze(const Maze & other)
{
	startCell = other.startCell;
	goalCell = other.goalCell;
	height = other.height;
	width = other.width;
	//Initilization of dynamic 2D array to begin copying from passed maze
	arr = new Cell*[height];
	for (int i = 0; i < height; i++)
	{
		arr[i] = new Cell[width];
	}
	//Copying from passed maze
	for (int i = 0; i < other.height; i++)
	{
		for (int j = 0; j < other.width; j++)
		{
			arr[i][j] = other.arr[i][j];
		}
	}
}
Maze Maze::operator=(const Maze & other)
{
	if (this != &other) //Self assignment check
	{
		startCell = other.startCell;
		goalCell = other.goalCell;

		//Initilization of dynamic 2D array to begin copying from passed maze ONLY IF the height or width are different
		//Otherwise it would be useless to rellocate
		if (height != other.height || width != other.width)
		{
			height = other.height;
			width = other.width;
			arr = new Cell*[height];
			for (int i = 0; i < height; i++)
			{
				arr[i] = new Cell[width];
			}
		}
		//Copying from passed maze
		for (int i = 0; i < other.height; i++)
		{
			for (int j = 0; j < other.width; j++)
			{
				arr[i][j] = other.arr[i][j];
			}
		}
	}
	return *this; //To allow for MazeObj1 = MazeObj2 = MazeObj3 = ...
}
Maze::~Maze()
{
	for (int i = 0; i < height; i++)
		delete[] arr[i];
	delete[] arr;
}
bool Maze::operator==(const Maze & other)
{
	//If start, goal, height or width are different then the mazes are not the same
	if (startCell != other.startCell || goalCell != other.goalCell || height != other.height || width != other.width) return false;
	//Checking every element of the maze
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (arr[i][j] != other.arr[i][j])
			{
				return false;
			}
		}
	}
	return true; //If it passes all the checks, true is returned
}
bool Maze::operator!=(const Maze & other)
{
	return !(*this == other); //Simply !==
}
//------------------Getters------------------
int Maze::getHeight() const
{
	return height;
}
int Maze::getWidth() const
{
	return width;
}

//------------------Setters------------------
void Maze::setStart(int Nrow, int Ncol)
{
	//Checks if there already exists a start, if there is a start then its status is changed to ' '
	//To avoid to duplicate starts in one maze
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (arr[i][j].getStatus() == 'S')
				arr[i][j].setStatus(' ');

	//Sets start status to selected cell
	arr[Nrow][Ncol].setStatus('S');
	//Start cell variable is now set to the new start cell
	startCell = arr[Nrow][Ncol];
}
void Maze::setGoal(int Nrow, int Ncol)
{
	//Checks if there already exists a goal, if there is a goal then its status is changed to ' '
	//To avoid to duplicate goal in one maze
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (arr[i][j].getStatus() == 'G')
				arr[i][j].setStatus(' ');
	//Sets goal status to selected cell
	arr[Nrow][Ncol].setStatus('G');
	//Goal cell variable is now set to the new goal cell
	goalCell = arr[Nrow][Ncol];
}
void Maze::setHeight(int Nheight)
{
	height = Nheight;
}
void Maze::setWidth(int Nwidth)
{
	width = Nwidth;
}


//------------------Major functions------------------


void Maze::insertCell(Cell cell)
{
	arr[cell.getY()][cell.getX()] = cell; //Sets the array's indices to the cell coordinates using the cell's getter functions)
	if (arr[cell.getY()][cell.getX()].getStatus() == 'S') //If the cell is a start
		startCell = arr[cell.getY()][cell.getX()]; //It become the start cell of the maze
	else if (arr[cell.getY()][cell.getX()].getStatus() == 'G') //If the cell is a goal
		goalCell = arr[cell.getY()][cell.getX()]; //It becomes the goal cell of the maze
}

void Maze::displayMaze()
{
	for (int i = 0; i < getHeight(); i++) //Traverse rows
	{
		//The first of cells do not share their top with other cells, therefore, we check their top since they won't
		//Be checked by a cell above them
		//When i = 0, this means this is the first row of cells
		//Therefore we check the top (Happens only once for each maze)
		if (i == 0)
		{
			for (int j = 0; j < getWidth(); j++) //Loop to check top walls of cells
			{
				if (arr[i][j].getTop() == true) cout << "+---"; //If blocked on top, place a wall
				else cout << "+   "; //If not blocked on top, place spaces
			}
		}
		cout << "+"; //The last + in the corner of the row
		cout << endl; //Move to next row
		for (int j = 0; j < getWidth(); j++) //Loop to check left walls of cells
		{
			if (arr[i][j].getLeft() == true) cout << "|"; //If blocked on the left, place a wall
			else cout << " "; //If not blocked, place space
			cout << " " << arr[i][j].getStatus() << " "; //Place a space, the status (' ', @, *, S, G) then a space to create the cell's body
			if (j == getWidth() - 1) //Last cell must check if the right is blocked. All other cells just have to check left (Since their right is another cell's left anyways)
			{
				if (arr[i][j].getRight() == true) cout << "|"; //If blocked on the right, place a wall
			}
		}
		cout << endl; //Move to next row
		for (int j = 0; j < getWidth(); j++) //Loop to check bottom of cells
		{
			if (arr[i][j].getDown() == true) cout << "+---"; //If blocked on bottom, place a wall
			else cout << "+   "; //If not blocked on the bottom, place spaces
		}
	}
	cout << "+"; //The last * in the corner of the row
	cout << endl; //Extra line for good formatting
}




void Maze::Success(Cell * goal) //Takes pointer to the last cell (The goal) as a parameter
						  //The reason it's a pointer is explained in DFS
{
	//Since we are traversing backwards, printing would give us cells from goal to start
	//Even though we want them from start to goal. Therefore, they are stored in a stack to be printed out of it in correct order.
	stack<Cell*> correctOrder;
	correctOrder.push(goal); //To allow for printing the goal's coordinates too
	goal = (goal->getPrev()); //To prevent overwriting the Goal's 'G' with '@'


	if (goal == nullptr) cout << "Start and goal are in the same spot! -> "; //This will only get printed out in the case of start and goal being in the same spot (Very unique scenario)


	while (goal != nullptr) //Keep looping until no more previous cells
	{
		goal->setStatus('@'); //Each cell in the path from S to G will have '@' status
		correctOrder.push(goal); //Stores each cell in the stack
		goal = (goal->getPrev()); //Next previous
	}
	while (!correctOrder.empty()) //Keep looping until the stack is empty
	{
		cout << "(" << (correctOrder.top()->getX() + 1) << ", " << (correctOrder.top()->getY() + 1) << ") "; //Print out each cell's coordinates
		correctOrder.pop(); //To get to the next element
	}
	cout << endl; //New line for better formatting

}

//Explanation on why the stack in DFS and the queue in BFS store pointers to cells rather than the cells themselves:
//The reason is because that any changes which we do to a cell (Such as setting its status to '*' would only happen
//In the scope of the DFS / BFS functions and would not translate into actual changes in the array of the maze
//So, having a pointer to the cells inside in the array would allow direct manipulation of the cells. Otherwise,
//There would be a lot more tedious code which is very unnecessary

bool Maze::DFS()
{
	Cell * currentCell; //Pointer to the cell the DFS is currently at
	stack<Cell*> stk; //Uses stack ADT to store pointers to cells (Explained above)
	stk.push(&startCell); //First cell to be pushed into the stack is the start cell 'S'
	while (!stk.empty()) //There is a possible solution as long as stack is not empty
	{
		currentCell = stk.top(); //The current cell is the top of the stack


		//Extremely important: The reason we didn't simply do (goalCell == *currentCell) is
		//Because the operator== implemented has to check for status of cells so that when comparing
		//The mazes in the main, we can get correct results on whether a maze has been solved or not
		//(Since the only difference between a solved and unsolved maze is the status of the cells)
		if (goalCell.getX() == currentCell->getX() && goalCell.getY() == currentCell->getY()) 
		{
			//A solution is found! Call the Success function with the current cell (Since the current cell contains data
			//On the previous cell and the previous cell contains data on the one before it so that solution coordinates
			//Are printed out for the user
			Success(currentCell);
			//Return true since the DFS process was succesful
			return true;
		}
		currentCell->setStatus('*'); //The current cell's status is changed to true since it has been traversed


									 //Note: Same logic for all 4 cases (Down, Right, Left, Top)
									 //NOTICE! Using (else if) statements since DFS takes one path a time.


		if (
			//First check: Checks if it's walled off from the bottom
			currentCell->getDown() == false
			//Second Check (If first one passes): Checks if this leads to an actual cell or is out of bounds
			&& ((currentCell->getY() + 1) < height)
			//Third Check (If the two before it pass): Checks if the cell below is the start cell (Which implies it has been traversed)
			&& ((arr[currentCell->getY() + 1][(currentCell->getX())]).getStatus() != 'S')
			//Fourth Check (If the three before it pass): Checks if the cell below has been traversed or not
			&& ((arr[currentCell->getY() + 1][(currentCell->getX())]).getStatus() != '*')
			)
		{
			//If all 4 checks pass, the cell below the current one is pushed into the stack.
			stk.push(&arr[currentCell->getY() + 1][((currentCell->getX()))]);
			//The new cell which has been pushed will have its previous set to the current cell
			//This is so we can backtrack when the solution is found (If this cell ends up being part of the solution anyways)
			arr[currentCell->getY() + 1][(currentCell->getX())].setPrev(currentCell);
		}
		else if (
			currentCell->getRight() == false
			&& ((currentCell->getX() + 1) < width)
			&& ((arr[currentCell->getY()][(currentCell->getX() + 1)]).getStatus() != 'S')
			&& ((arr[currentCell->getY()][(currentCell->getX() + 1)]).getStatus() != '*')
			)
		{
			stk.push(&arr[((currentCell->getY()))][(currentCell->getX() + 1)]);
			arr[currentCell->getY()][(currentCell->getX() + 1)].setPrev(currentCell);
		}

		else if (
			currentCell->getLeft() == false
			&& ((currentCell->getX() - 1) >= 0)
			&& ((arr[currentCell->getY()][(currentCell->getX() - 1)]).getStatus() != 'S')
			&& ((arr[currentCell->getY()][(currentCell->getX() - 1)]).getStatus() != '*')
			)
		{
			stk.push(&arr[((currentCell->getY()))][(currentCell->getX() - 1)]);
			arr[currentCell->getY()][(currentCell->getX() - 1)].setPrev(currentCell);
		}
		else if (
			currentCell->getTop() == false
			&& ((currentCell->getY() - 1) >= 0)
			&& ((arr[currentCell->getY() - 1][(currentCell->getX())]).getStatus() != 'S')
			&& ((arr[currentCell->getY() - 1][(currentCell->getX())]).getStatus() != '*')
			)
		{
			stk.push(&arr[currentCell->getY() - 1][(currentCell->getX())]);
			arr[currentCell->getY() - 1][(currentCell->getX())].setPrev(currentCell);
		}

		//If no where left to traverse in 4 directions that is unvisited, we start popping from the stack
		//As to go in reverse. Popping will stop once there is a direction that is visited (Since each cell
		//In the stack will check the 4 statements above)
		else
		{
			stk.pop();
		}
	}
	cout << "No solution found!\n"; //Print out error message if no solution could be found
	return false; //Return false since BFS process was not succesful
}

bool Maze::BFS()
{
	Cell * currentCell; //Pointer to the cell the BFS is currently at
	queue<Cell*> que; //Uses queue ADT to store pointers to cells (Explained above)
	que.push(&startCell); //First cell to be pushed into the queue is the start cell 'S'
	while (!que.empty())  //There is a possible solution as long as queue is not empty
	{
		currentCell = que.front(); //The current cell is the front of the queue

		//Extremely important: The reason we didn't simply do (goalCell == *currentCell) is
		//Because the operator== implemented has to check for status of cells so that when comparing
		//The mazes in the main, we can get correct results on whether a maze has been solved or not
		//(Since the only difference between a solved and unsolved maze is the status of the cells)
		if (goalCell.getX() == currentCell->getX() && goalCell.getY() == currentCell->getY()) //If the derefrenced current cell (Since it is a pointer) is equal to the goalCell
		{
			//A solution is found! Call the Success function with the current cell (Since the current cell contains data
			//On the previous cell and the previous cell contains data on the one before it so that solution coordinates
			//Are printed out for the user
			Success(currentCell);
			//Return true since BFS was succesful
			return true;
		}
		currentCell->setStatus('*'); //The current cell's status is changed to true since it has been traversed
		que.pop(); //Pop before proceeding with checking the neighboring cells (BFS Specification)


				   //Note: Same logic for all 4 cases (Down, Right, Left, Top)


				   //NOTICE! One of the major differences between BFS and DFS when it has to do with the if statements is that BFS does not use (else if)! That is because we want to push ALL the neighboring cells of the current one into the queue then push every neighboring cell of the front of the queue and so on.

		if (
			//First check: Checks if it's walled off from the bottom
			currentCell->getDown() == false
			//Second Check (If first one passes): Checks if this leads to an actual cell or is out of bounds
			&& ((currentCell->getY() + 1) < height)
			//Third Check (If the two before it pass): Checks if the cell below is the start cell (Which implies it has been traversed)
			&& ((arr[currentCell->getY() + 1][(currentCell->getX())]).getStatus() != 'S')
			//Fourth Check (If the three before it pass): Checks if the cell below has been traversed or not
			&& ((arr[currentCell->getY() + 1][(currentCell->getX())]).getStatus() != '*')
			)
		{
			//If all 4 checks pass, the cell below the current one is pushed into the queue.
			que.push(&arr[currentCell->getY() + 1][((currentCell->getX()))]);
			//The new cell which has been pushed will have its previous set to the current cell
			//This is so we can backtrack when the solution is found (If this cell ends up being part of the solution anyways)
			arr[currentCell->getY() + 1][(currentCell->getX())].setPrev(currentCell);
		}
		if (
			currentCell->getRight() == false
			&& ((currentCell->getX() + 1) < width)
			&& ((arr[currentCell->getY()][(currentCell->getX() + 1)]).getStatus() != 'S')
			&& ((arr[currentCell->getY()][(currentCell->getX() + 1)]).getStatus() != '*')
			)
		{

			que.push(&arr[((currentCell->getY()))][(currentCell->getX() + 1)]);
			arr[currentCell->getY()][(currentCell->getX() + 1)].setPrev(currentCell);
		}
		if (
			currentCell->getLeft() == false
			&& ((currentCell->getX() - 1) >= 0)
			&& ((arr[currentCell->getY()][(currentCell->getX() - 1)]).getStatus() != 'S')
			&& ((arr[currentCell->getY()][(currentCell->getX() - 1)]).getStatus() != '*')
			)
		{
			arr[currentCell->getY()][(currentCell->getX() - 1)].setPrev(currentCell);
			que.push(&arr[((currentCell->getY()))][(currentCell->getX() - 1)]);
		}
		if (
			currentCell->getTop() == false
			&& ((currentCell->getY() - 1) >= 0)
			&& ((arr[currentCell->getY() - 1][(currentCell->getX())]).getStatus() != 'S')
			&& ((arr[currentCell->getY() - 1][(currentCell->getX())]).getStatus() != '*')
			)
		{
			que.push(&arr[currentCell->getY() - 1][(currentCell->getX())]);
			arr[currentCell->getY() - 1][(currentCell->getX())].setPrev(currentCell);
		}
	}

	cout << "No solution found!\n"; //Print out error message if no solution could be found
	return false; //Return false since BFS process was not succesfull
}
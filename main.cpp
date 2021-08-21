//Driver & loadMaze function

#include "maze.h"
#include "cell.h"

Maze loadMaze(bool & loaded, bool & startSet, bool & goalSet);


int main()
{
	bool loaded = false, solved = false, flag = true, goalSet = false, startSet = false;
	//Loaded -> Whether the maze has been loaded or not
	//Solved -> Whether the maze has been succesfully solved with DFS or BFS
	//Flag -> Keeps looping through options till exitting (Option 8 sets flag to false)
	//goalSet -> Whether the maze has a start or not yet
	//startSet -> Whether the maze has a goal or not yet
	int choice; //-> Stores option choice of user
	Maze maze; //-> Primary maze object
	Maze backupMaze; //backupMaze -> used to prevent DFS & BFS solution overlapping | For option 2 to be different from option 7 (Printing orginal maze vs its path)
	int Grow, Gcol, Srow, Scol;
	//Grow -> Goal row
	//Gcol -> Goal col
	//Srow -> Start row
	//Scol -> Start col
	while (flag)
	{
		//Menu
		cout << "1) Load Maze\n";
		cout << "2) Display Maze\n";
		cout << "3) Set start\n";
		cout << "4) Set goal\n";
		cout << "5) Find path (BFS)\n";
		cout << "6) Find path (DFS)\n";
		cout << "7) Display Path\n";
		cout << "8) Exit\n>> ";
		do { cin >> choice; } while (choice < 0 || choice > 8); //Do while loop to prevent invalid entries

		if (choice == 1) //1) Load Maze
		{
			//Resets all maze-related booleans
			//Because a user can load a maze, get all the booleans to become true then reload the maze and still have access
			//To all the functions which require those booleans to be true. For example: Load maze which has no start of goal
			//Set the start and goal, load maze again -> Now, there is no start or goal, but startSet and goalSet are still true!
			solved = false; goalSet = false; startSet = false; //This line of code prevents the forementioned issue.
			maze = loadMaze(loaded, startSet, goalSet); //Load maze function which also modifies loaded, startSet, goalSet
			backupMaze = maze; //Creates Backup
		}
		else if (choice == 2) //2) Display Maze
		{
			if (loaded) backupMaze.displayMaze(); //Displays unsolved maze (Hence using backupMaze object) only if it has been loaded
			else cout << "Please load a maze file first!\n"; //Error message if attempting to display maze before loading it
		}
		else if (choice == 3) //3) Set start
		{
			if (loaded) //Prevents invalid coordinates
			{
				cout << "Please enter start coordinates starting from 1 (row, column): ";
				//Behind the scenes uses indices starting from 0, but starting from 1 is more user friendly.
				//Therefore, -= 1 is applied to the user's entry to allow for easier programming, but good UI
				cin >> Srow; Srow -= 1;
				cin >> Scol; Scol -= 1;


				if (Srow < 0 || Scol < 0 || Srow >= maze.getWidth() || Scol >= maze.getHeight()) //Prevents invalid coordinates
				{
					cout << "Invalid start coordinates! Are you sure you loaded a file?\n"; //Error message if invalid coordinates
				}
				else //If coordinates are valid
				{
					solved = false; //New coordinates therefore solution has changed so the maze is marked as unsolved
					startSet = true; //Indicates that maze now has a start
					if (solved) maze = backupMaze; //Resets the maze if it has been solved
					maze.setStart(Srow, Scol); //Sets new start pointer for original maze
					backupMaze = maze; //Backs up maze
					cout << "Start coordinates changed successfully!\n"; //Success Message
				}
			}
			else //If file was not loaded
			{
				cout << "Please load a maze file first!\n"; //Error message if attempting to change start coordinates before loading a maze
			}
		}
		else if (choice == 4) //4) Set goal
		{
			if (loaded) //Prevents changing coordinate
			{
				cout << "Please enter goal coordinates starting from 1 (row, column): ";
				//Behind the scenes uses indices starting from 0, but starting from 1 is more user friendly.
				//Therefore, -= 1 is applied to the user's entry to allow for easier programming, but good UI
				cin >> Grow; Grow -= 1;
				cin >> Gcol; Gcol -= 1;

				if (Grow < 0 || Gcol < 0 || Grow >= maze.getWidth() || Gcol >= maze.getHeight()) //Prevents invalid coordinates
				{
					cout << "Invalid goal coordinates!\n"; //Error message if invalid coordinates
				}
				else //If coordinates are valid
				{
					solved = false; //New coordinates therefore solution has changed so the maze is marked as unsolved
					goalSet = true; //Indicates that maze now has a goal
					if (solved) maze = backupMaze; //Resets the maze if it has been solved
					maze.setGoal(Grow, Gcol); //Sets new goal for original maze
					backupMaze = maze; //Backs up maze
					cout << "Goal coordinates changed successfully!\n"; //Success Message
				}
			}
			else //If file was not loaded
			{
				cout << "Please load a maze file first!\n"; //Error message if attempting to change goal coordinates before loading a maze
			}
		}
		else if (choice == 5) //5) Find path (BFS)
		{
			if (loaded && startSet && goalSet) //Checks if maze is loaded and has both a start and goal
			{
				if (backupMaze != maze) //Resets maze if it has already been solved
				{
					maze = backupMaze;
				}
				solved = maze.BFS(); //Calls BFS function and sets its return value to the solved variable (To allow access to option 7 or not)
			}
			else //If no maze has been loaded or current maze does not have a start or goal set
			{
				cout << "Please make sure to load, set a start and a goal before using BFS search!\n";
			}
		}
		else if (choice == 6) //6) Find path (DFS)
		{
			if (loaded && startSet && goalSet) //Checks if maze is loaded and has both a start and goal
			{
				if (backupMaze != maze) //Resets maze if it has already been solved
				{
					maze = backupMaze; //Calls BFS function and sets its return value to the solved variable (To allow access to option 7 or not)
				}
				solved = maze.DFS();
			}
			else //If no maze has been loaded or current maze does not have a start or goal set
			{
				cout << "Please make sure to load, set a start and a goal before using DFS search!\n";
			}
		}
		else if (choice == 7) //7) Display Path
		{
			if (solved) maze.displayMaze(); //Displays solution if there exists one
			else cout << "No solution created yet! Use a BFS or DFS search first!\n"; //Displays error message if there's no solution yet
		}
		else if (choice == 8) //8)Exit
		{
			//Sets flag to false therefore exiting option menu loop.
			//Using this instead of exit(0) since that would prevent destructors from being calld
			flag = false;

		}
	}
	return 0;
}

//------------------------------------

//Note: Triple "///" indicates comments on code provided in the appendix.
//Loaded, startSet and goalSet are passed by reference so that the main can unlock options for the user or not
//Those options depend on whether the maze read succesfully or not and whether the maze file contains the start and goal already
Maze loadMaze(bool & loaded, bool & startSet, bool & goalSet) //The reason it is a non-member function: Because it was given in the script as a non-member function and wanted it to keep it as so
{
	int Xcurr, Ycurr; //Used to identify current cell's position | Will also be used as (Xcurr + 1) & (Ycurr + 1) later for maze height and width
	Cell newCell; //Object of type cell, will be constructed for each cell then inserted into cellVector
	vector<Cell> cellVector; //Will be filled with all cells then will be inserted into the maze class
	ifstream in("maze.txt"); ///Opens text file
	if (!in.fail()) //Only proceeds if file exists
	{
		///3 strings since each cell consists of 3 lines.
		char str1[100], str2[100], str3[100];
		in.getline(str1, 100);
		in.getline(str2, 100);
		in.getline(str3, 100);
		int line = 1, cell = 1; ///Counters for cells and lines
		while (!in.eof()) ///While the file didn't reach its end
		{
			cell = 1;
			int i = 0; ///Cell row index (For string 1)
			bool top, down, right, left;
			top = down = right = left = false; ///Default value for top, down, right, left is false (No walls)
			int j = 0; ///Cell row index (For string 2)
			int k = 1; ///Cell row index (For string 3)
			while (i < strlen(str1) - 1) ///Keeps looping throw the row until all cells have been read properly
			{
				top = down = right = left = false; ///Default value for top, down, right, left is false (No walls) [Why Again?]
				if (str1[i] == '+') i++; ///Checks for '+' which indicates a new cell then increments i by 1 (Moving it to the cell's top wall to check it)
				if (str1[i] == '-')top = true; else if (str1[i] == ' ')top = false;   i = i + 3; ///Checks if there is a wall above. Then increment i by 3 (Moving it to the next cell's '+')
				if (str2[j] == '|') left = true; else if (str2[j] == ' ')left = false; j = j + 4; ///Checks if there is a wall on the left. Then increments j by 4 (Moving it to this cell's right wall / Next cell's left wall)
				char status = str2[j - 2]; //Gets status of cell
				if (status == 'S') //If the cell is a start
				{
					startSet = true; //Indicates that the maze has a start -> One of the requirements to unlock DFS & BFS options in the main
				}
				else if (status == 'G') //If the cell is a goal
				{
					goalSet = true; //Indicates that the maze has a goal -> One of the requirements to unlock DFS & BFS options in the main
				}
				if (str2[j] == '|') right = true; else if (str2[j] == ' ')right = false; ///Checks if there is a wall on the right of the current cell
				if (str3[k] == ' ') down = false; else if (str3[k] == '-') down = true; k = k + 4; ///Checks if there is a wall on the bottom. Then increments k by 4 (Moving it to the next cell's bottom wall)
				cell++; ///Increments number of cells existing a row
				Xcurr = cell - 2; //column index of new cell
				Ycurr = line - 1; //row index of new cell
				Cell newCell(Ycurr, Xcurr, top, down, left, right, status); //Creation of cell object to be inserted to cellVector
				cellVector.push_back(newCell); //Push a new cell into the vector of cells
			}
			//Since all cells (Except for those in the 1st row) share the bottom of the cells above them
			//The bottom of the current row of cells will be the top of the next row of cells to be read
			//Therefore, we copy the current str3 (Bottom of current row of cells) to str1 (Top of next row of cells)
			strcpy(str1, str3);
			in.getline(str2, 100); //Read body of new row of cells normally
			in.getline(str3, 100); //Read bottom of new row of cells normally
			line++; //Increments number of rows of the maze
		}

		//Important: This is a replica of what's inside the (!in.eof()) while loop (With the exception of the last 4 lines)
		//The reason it exists is to allow the checking of the last row of cells and to insert them into the cellVector
		//Since (!in.eof()) would break too early for this to be possible to happen.
		//There are other ways to do it, other than copying the code, but this is very logically unintensive and easier to code.
		cell = 1;
		int i = 0;
		bool top, down, right, left;
		top = down = right = left = false;
		int j = 0, k = 1;
		while (i < strlen(str1) - 1)
		{
			top = down = right = left = false;
			if (str1[i] == '+') i++; //new cell
			if (str1[i] == '-')top = true; else if (str1[i] == ' ')top = false;   i = i + 3;
			if (str2[j] == '|') left = true; else if (str2[j] == ' ')left = false; j = j + 4;
			char status = str2[j - 2];
			if (status == 'S')
			{
				startSet = true;
			}
			else if (status == 'G')
			{
				goalSet = true;
			}
			if (str2[j] == '|') right = true; else if (str2[j] == ' ')right = false;
			if (str3[k] == ' ') down = false; else if (str3[k] == '-') down = true; k = k + 4;
			cell++;
			Xcurr = cell - 2;
			Ycurr = line - 1;
			Cell newCell(Ycurr, Xcurr, top, down, left, right, status);
			cellVector.push_back(newCell);
		}
		//The reason we pass Ycurr & Xcurr with (+1) is because they will be used to initialize the maze's height
		//and width (Unlike how Ycurr and Xcurr were used previously as indices for cells which start from 0)
		Maze maze(Ycurr + 1, Xcurr + 1); //Creates object of maze with (height = Ycurr + 1) & (width =  Xcurr + 1)
		for (int i = 0; i < cellVector.size(); i++) //Loops through the vector of cells
		{
			maze.insertCell(cellVector.at(i)); //Inserts each cell in the vector into the maze
		}
		cout << "Maze loaded successfully!\n"; //Success message
		loaded = true; //Used to allow access to a number of options in the main now that the maze has beed succesfully read
		return maze; //Return complete maze after succesfully reading it
	}
	else //If file failed to open
	{
		Maze failedMaze; //Dummy maze to be returned (Since the function MUST return a maze)
		cout << "Failed to open maze file!\n"; //Error message
		return failedMaze; //Return dummy maze
	}
} 

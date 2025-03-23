<div align="center">
    <img src="readmeResources/maze-solver-logo.svg" alt="Maze" width="150" height="150">
  <h3 align="center">C++ Maze Solver</h3>
  

[![C++](https://img.shields.io/static/v1?label=&message=C%2B%2B&color=3F78A9&logo=cplusplus)](https://www.cplusplus.com)
[![Visual Studio](https://img.shields.io/static/v1?label=&message=Visual%20Studio&color=5C2D91&logo=data:image/png;base64,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)](https://visualstudio.microsoft.com)
  
A C++ program that takes a maze file as an input and produces a solution using breadth-first search or depth-first search
</div>



## :flight_departure: How To Run
#### Unix:
1. `git clone https://github.com/ElixirForge/maze-solver.git` (Must have git installed on your OS) -OR- download the zip file and extract it in the desired directory
2. Install g++ (Most likely preinstalled with MacOS or your Linux Distribution)
3. In project directory: `g++ *.cpp -o output`
4. In project directory: `./output`

#### Windows (Visual Studio):
1. Install [Visual Studio](https://visualstudio.microsoft.com)
2. Make sure to install the "Desktop development with C++" component
3. Launch Visual Studio. File --> New --> Project --> Win32 Console Application
4. Download the code as a zip file and copy the contents to the Visual Studio project directory's source files
5. Run using the local Windows debugger or press Ctrl+F5

## :question: How To Use:
#### 1. The program takes in a maze (`maze.txt`) as an input; a valid maze must exist in the same directory as the cpp files. I have provided `maze.txt` & `maze2.txt` as examples in the repository. Here are examples of valid maze.txt files and the solutions provided by the algorithm:
```
        maze.txt (Unsolved)
+---+---+---+---+---+---+---+---+
| S |                           |
+   +   +   +---+---+---+---+---+
|   |   |                       |
+   +---+---+---+   +---+---+---+
|   |                           |
+   +   +---+---+   +---+---+---+
|       |                       |
+---+---+   +---+---+---+---+---+
|                             G 
+---+---+---+---+---+---+---+---+			


        maze.txt (Unsolved)                                    BFS
+---+---+---+---+---+---+---+---+		+---+---+---+---+---+---+---+---+
| S                             |		| S   *   *   *   *   *   *   * |
+   +---+---+---+---+---+---+   +		+   +---+---+---+---+---+---+   +
|   |                           |		| @ | *   *   *   *   *   *   * |
+   +   +---+---+---+---+---+---+		+   +   +---+---+---+---+---+---+ 
|                               |		| @   @   @   @   @   @   @     |
+---+---+   +---+   +---+   +---+		+---+---+   +---+   +---+   +---+
|           |       |         G 		| *   *   * |       |     @   G 
+   +---+---+---+---+   +---+---+		+   +---+---+---+---+   +---+---+
|                               |		| *   *   *                     |
+---+---+---+---+---+---+---+---+		+---+---+---+---+---+---+---+---+

            DFS (#1)                                 DFS (#2 – same as above)
+---+---+---+---+---+---+---+---+		+---+---+---+---+---+---+---+---+
| S                             |		| S   @   @   @   @   @   @   @ |
+   +---+---+---+---+---+---+   +		+   +---+---+---+---+---+---+   +
| @ |                           |		|   | @   @   @   @   @   @   @ |
+   +   +---+---+---+---+---+---+		+   +   +---+---+---+---+---+---+
| @   @   @                     |		|     @   @   @   @   @   @   * |
+---+---+   +---+   +---+   +---+		+---+---+   +---+   +---+   +---+
| @   @   @ |       | @   @   G 		|           |       |     @   G 
+   +---+---+---+---+   +---+---+		+   +---+---+---+---+   +---+---+
| @   @   @   @   @   @   *   * |		|                               |
+---+---+---+---+---+---+---+---+		+---+---+---+---+---+---+---+---+

Legend:
S: Start
G: Goal
@: Indicates the cell is part of the path from start to goal
*: Indicates the cell has been visited, but is not part of the path from start to finish
```


#### 2. When the program runs, you are presented with a set of options:-
```
1) Load Maze 
2) Display Maze
3) Set start
4) Set goal
5) Find path (BFS)
6) Find path (DFS)
7) Display Path
8) Exit
```
1 -> First step which must always be done; reads the maze file  
2 -> Displays the loaded maze file on the console  
3 -> Set start or modify existing start. Once selected, type in coordinates of the desired cell --> `1 1` is top left for example 
4 -> Set goal or modify existing goal. Once selected, type in coordinates of the desired cell  
5 -> Attempts to solve the maze with breadth-first search. If successful, displays the path coordinates  
6 -> Attempts to solve the maze with depth-first search. If successful, displays the path coordinates  
7 -> Displays the solved maze (With @ and * symbols) 
8 -> Exits the program safely

#### 3. :rocket: :rocket: Play around with different options and maze files :D :rocket: :rocket:

## :beetle: Bugs
There is a prominent bug that causes a segmentation error. I would have to review the code since I've written it a while back, but as of right now, here is how to use the program without triggering the error:
1. Load the maze <i>(Option 1)</i> such that it looks like:
```
+---+---+---+---+---+
| S |               |
+   +   +   +---+---+
|   |   |           |
+   +---+---+---+   +
|   |               |
+   +   +---+---+   +
|       |           |
+---+---+   +---+---+
|                 G   
+---+---+---+---+---+
```
3. Modify the maze.txt (Add the border on the bottom right) file and save so that it looks like:
```
+---+---+---+---+---+
| S |               |
+   +   +   +---+---+
|   |   |           |
+   +---+---+---+   +
|   |               |
+   +   +---+---+   +
|       |           |
+---+---+   +---+---+
|                 G | 
+---+---+---+---+---+
```
4. Load the maze again <i>(Option 1)</i>
5. You can now use options 5, 6, 7. Options 3 & 4 seem to also be broken due to the same bug.

## :tv: Demo
<div align="center">
<img src="readmeResources/maze-solver-demo.png" alt="demo">
</div>

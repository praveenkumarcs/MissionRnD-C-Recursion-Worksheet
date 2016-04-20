/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
1		1
1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/
#include<stdio.h>
#include<stdlib.h>

#define and &&
#define or ||
#define not !
#define equals ==
#define true 1
#define false 0

int inMaze(int row, int col, int rows, int cols){

	if (row >= 0 and row <= rows - 1 and col >= 0 and col <= cols - 1)
		return true;
	else                 
		return false;
	
}



int findpath(int **Maze, int **visited, int rows, int columns, int i, int j, int p, int q){

	if (inMaze(i, j, rows, columns)){

		if (Maze[i][j] == 1 and not visited[i][j]){

			visited[i][j] = true;

			if (i equals p and j equals q)
				return true;
			else{

				if (findpath(Maze, visited, rows, columns, i - 1, j, p, q) equals true)  /*going North*/
					return true;

				if (findpath(Maze, visited, rows, columns, i, j + 1, p, q) equals true)  /*going East*/
					return true;

				if (findpath(Maze, visited, rows, columns, i + 1, j, p, q) equals true)  /*going South*/
					return true;

				if (findpath(Maze, visited, rows, columns, i, j - 1, p, q) equals true)  /*going West*/
					return true;

				visited[i][j] = false;

				return false;

			}

		}
		else
			return false;
	}
	else
		return false;


}


int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int i, j, stat = 0;
	int **Maze = NULL, **visited = NULL, *ptr = NULL;

	if (x1 < 0 or y1 < 0 or rows < 0 or columns < 0 or x2 < 0 or y2 < 0)
		return 0;

	Maze = (int **)malloc(rows*sizeof(int *));
	visited = (int **)malloc(rows*sizeof(int *));
	for (i = 0; i < rows; i++){
		Maze[i] = NULL;
		visited[i] = NULL;
	}
	for (i = 0; i < rows; i++){
		ptr = (int *)malloc(columns*sizeof(int));
		Maze[i] = ptr;
		ptr = (int *)malloc(columns*sizeof(int));
		visited[i] = ptr;
	}

	for (i = 0; i < rows; i++)
		for (j = 0; j < columns; j++)
			Maze[i][j] = maze[i*columns + j];

	for (i = 0; i < rows; i++)
		for (j = 0; j < columns; j++)
			visited[i][j] = false;

	stat = findpath(Maze, visited, rows, columns, x1, y1, x2, y2);

	if (stat)
		return true;
	else
		return false;


}







/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
#define and && 
#define or ||

void spiralCopy(int *ptr,int rows,int cols,int **array){

	int i, j, k, pos = 0;

	i = 0; j = 0; k = 0;
	while (i < rows and j < cols){

		/*copy the first row*/
		for (k = j; k < cols; k++)
			ptr[pos++] = array[i][k];
		i++;

		/*copy the last column*/
		for (k = i; k < rows; k++)
			ptr[pos++] = array[k][cols - 1];
		cols--;

		/*copy the last row*/
		if (i < rows){
			for (k = cols - 1; k >= j; k--)
				ptr[pos++] = array[rows-1][k];
			rows--;
		}

		/*copy the first column*/
		if (j < cols){
			for (k = rows - 1; k >= i; k--)
				ptr[pos++] = array[k][j];
			j++;
		}

	}

}

int *spiral(int rows, int columns, int **input_array)
{
	int *ptr = NULL;

	if (rows <= 0 or columns <= 0 or input_array == NULL)
		return NULL;

	ptr = (int *)malloc(rows*columns*sizeof(int));

	spiralCopy(ptr, rows, columns, input_array);

	return ptr;

}

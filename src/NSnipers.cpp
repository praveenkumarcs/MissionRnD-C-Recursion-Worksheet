/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"

#define and &&
#define or ||
#define equals ==
#define true 1
#define false 0

int isFeasible(int *battlefield, int i, int j, int n){

	int row, col;
	row = i; col = j;
	while (row >= 0 and col >= 0){
		if (battlefield[row*n + col] != 1){
			row--;
			col--;
		}
		else
			break;
	}
	if (row >= 0 and col >= 0)
		return false;

	row = i; col = j;
	while (row >= 0 and col <= n - 1){
		if (battlefield[row*n + col] != 1){
			row--;
			col++;
		}
		else
			break;
	}
	if (row >= 0 and col <= n - 1)
		return false;

	row = i; col = j;
	while (row >= 0){
		if (battlefield[row*n + col] != 1)
			row--;
		else
			break;
	}
	if (row >= 0)
		return false;
	else
		return true;

}


int solveBoard(int *battlefield, int n, int i){
	int j;

	if (i == n)
		return true;

	for (j = 0; j < n; j++){
		if (isFeasible(battlefield, i, j, n)){
			battlefield[i*n + j] = 1;
			if (solveBoard(battlefield, n, i + 1) == true)
				return true;
		}
		battlefield[i*n + j] = 0;
	}
	
	return false;
}



int solve_nsnipers(int *battlefield, int n){

	int stat = 0;
	if (battlefield == NULL or n < 0)
		return 0;
	stat = solveBoard(battlefield, n,0);

	if (stat)
		return true;
	else
		return false;

}

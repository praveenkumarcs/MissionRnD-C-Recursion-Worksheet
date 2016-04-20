/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"


int fact(int n){
	int f = 1,i;
	for (i = n; i >= 1; i--)
		f = f*i;
	return f;

}

int get_steps(int s)
{
	int i, sum = 1,twos = 0;
	if (s <= 0)
		return 0;

	if (s % 2 == 0)
		twos = s / 2;
	else
		twos = (s - 1) / 2;

	for (i = 1; i <= twos; i++){
		sum += fact(s - i * 2 + i) / (fact(i)*fact(s-i*2));
	}

	return sum;

}

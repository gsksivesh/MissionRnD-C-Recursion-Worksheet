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

int check(int *battlefield, int n, int element_index)
{
	int left = 1, right = 1;
	int i = element_index - n;

	for (; i >= 0 && (i - left + 1) % n != 0 && (i + right) % n != 0; i -= n, left++, right++)
	{
		if (battlefield[i] == 1 || battlefield[i - left] == 1 || battlefield[i + right] == 1)
			return 0;
	}
	for (; i >= 0 && (i - left + 1) % n != 0; i -= n, left++)
	{
		if (battlefield[i] == 1 || battlefield[i - left] == 1)
			return 0;
	}
	for (; i >= 0 && (i + right) % n != 0; i -= n, right++)
	{
		if (battlefield[i] == 1 || battlefield[i + right] == 1)
			return 0;
	}
	for (; i >= 0; i -= n)
	{
		if (battlefield[i] == 1)
			return 0;
	}
	return 1;
}

void place_sniper(int *battlefield, int n, int row, int coloumn, int *flag)
{
	int index;
	if (row >= n)
	{
		*flag = 2;
		return;
	}

	index = row*n + coloumn;
	if (coloumn >= n)
	{
		*flag = 1;
		return;
	}
	if (check(battlefield, n, index))
	{
		battlefield[index] = 1;
		place_sniper(battlefield, n, row + 1, 0, flag);
		if (*flag == 1)
		{
			battlefield[index] = 0;
			*flag = 0;
		}
	}
	if (*flag == 2)
	{
		return;
	}
	place_sniper(battlefield, n, row, coloumn + 1, flag);
}

int solve_nsnipers(int *battlefield, int n)
{
	int flag = 0;
	if (n <= 0 || battlefield == NULL || n == 2 || n == 3)
		return 0;
	place_sniper(battlefield, n, 0, 0, &flag);
	return 1;
}

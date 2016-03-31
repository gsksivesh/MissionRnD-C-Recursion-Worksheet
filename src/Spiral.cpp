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
int copy_array(int **input_array, int *ans, int row_start, int coloumn_start, int row_increment, int coloumn_increment, int ans_index, int rows, int coloumns, int step_size)
{
	int i, j;
	int temp;
	temp = ans_index;
	for (i = rows - row_start, j = coloumns - coloumn_start; ((ans_index - temp) < step_size) ; j += coloumn_increment, i += row_increment, ans_index++)
	{
		ans[ans_index] = input_array[i][j];
	}
	return ans_index;
}
int * go_spiral(int **input_array, int *ans, int row_step_size, int coloumn_step_size, int right, int down, int left, int up, int ans_index, int rows, int coloumns)
{
	int i, j;
	if (row_step_size == -1 || coloumn_step_size == -1)
		return ans;
	if (right)
	{
		ans_index = copy_array(input_array, ans, rows - row_step_size, coloumns - coloumn_step_size, 0, 1, ans_index, rows, coloumns, coloumn_step_size);
		return go_spiral(input_array, ans, row_step_size - 1, coloumn_step_size, 0, 1, 0, 0, ans_index, rows, coloumns);
	}
	else if (down)
	{
		ans_index = copy_array(input_array, ans, rows - row_step_size, coloumn_step_size - 1, 1, 0, ans_index, rows, coloumns, row_step_size);
		return go_spiral(input_array, ans, row_step_size, coloumn_step_size - 1, 0, 0, 1, 0, ans_index, rows, coloumns);
	}
	else if (left)
	{
		ans_index = copy_array(input_array, ans, row_step_size, coloumn_step_size, 0, -1, ans_index, rows, coloumns, coloumn_step_size);
		return go_spiral(input_array, ans, row_step_size - 1, coloumn_step_size, 0, 0, 0, 1, ans_index, rows, coloumns);
	}
	else if (up)
	{
		ans_index = copy_array(input_array, ans, row_step_size, coloumns - coloumn_step_size - 1, -1, 0, ans_index, rows, coloumns, row_step_size);
		return go_spiral(input_array, ans, row_step_size , coloumn_step_size - 1, 1, 0, 0, 0, ans_index, rows, coloumns);
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	return NULL;
}

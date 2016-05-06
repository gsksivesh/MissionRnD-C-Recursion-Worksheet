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
void go_spiral(int **input_array, int *ans, int right, int down, int left, int up, int ans_index, int rows, int coloumns, int row_index, int coloumn_index, int start, int limit)
{
	if (ans_index == limit)
		return;
	if (rows < 0 || coloumns < 0)
		return;
	if (right)
	{
		if (coloumn_index == coloumns)
		{
			go_spiral((int**)input_array, ans, 0, 1, 0, 0, ans_index, rows, coloumns, row_index + 1, coloumn_index - 1, start, limit);
		}
		else
		{
			ans[ans_index] = input_array[row_index][coloumn_index];
			go_spiral((int**)input_array, ans, 1, 0, 0, 0, ans_index + 1, rows, coloumns, row_index, coloumn_index + 1, start, limit);
		}
	}
	else if (down)
	{
		if (row_index == rows)
		{
			go_spiral((int**)input_array, ans, 0, 0, 1, 0, ans_index, rows, coloumns, row_index - 1, coloumn_index - 1, start, limit);
		}
		else
		{
			ans[ans_index] = input_array[row_index][coloumn_index];
			go_spiral((int**)input_array, ans, 0, 1, 0, 0, ans_index + 1, rows, coloumns, row_index + 1, coloumn_index, start, limit);
		}
	}
	else if (left)
	{
		if (coloumn_index == start - 1)
		{
			go_spiral((int**)input_array, ans, 0, 0, 0, 1, ans_index, rows, coloumns, row_index - 1, coloumn_index + 1, start, limit);
		}
		else
		{
			ans[ans_index] = input_array[row_index][coloumn_index];
			go_spiral((int**)input_array, ans, 0, 0, 1, 0, ans_index + 1, rows, coloumns, row_index, coloumn_index - 1, start, limit);
		}
	}
	else if (up)
	{
		if (coloumn_index + 1 == coloumns)
			return;
		if (row_index == start)
		{
			go_spiral((int**)input_array, ans, 1, 0, 0, 0, ans_index, rows - 1, coloumns - 1, row_index + 1, coloumn_index + 1, start + 1, limit);
		}
		else
		{
			ans[ans_index] = input_array[row_index][coloumn_index];
			go_spiral((int**)input_array, ans, 0, 0, 0, 1, ans_index + 1, rows, coloumns, row_index - 1, coloumn_index, start, limit);
		}
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	int *ans;
	if (rows < 0 || columns < 0)
		return NULL;
	if (input_array == NULL)
		return NULL;
	if (rows == 0 || columns == 0)
		return NULL;
	ans = (int*)malloc(sizeof(int)*(rows*columns));
	go_spiral((int**)input_array, ans, 1, 0, 0, 0, 0, rows, columns, 0, 0, 0, rows*columns);
	return ans;
}

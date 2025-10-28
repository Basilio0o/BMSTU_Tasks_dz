#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX_SIZE 100

void ReflectionMainDiagonal(int matrix[][MAX_SIZE], int matrix1[][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix1[i][j] = matrix[j][i];
		}
	}
}

void ReflectionSecondaryDiagonal(int matrix[][MAX_SIZE], int matrix2[][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix2[i][j] = matrix[n - 1 - j][n - 1 - i];
		}
	}
}

void ReflectionVec(int matrix[][MAX_SIZE], int matrix3[][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix3[i][j] = matrix[i][n - 1 - j];
		}
	}
}

void ReflectionHor(int matrix[][MAX_SIZE], int matrix3[][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix3[i][j] = matrix[n - 1 - i][j];
		}
	}
}

void Output(int matrix[][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool Comparison(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(matrix1[i][j] != matrix2[i][j]) return false;
		}
	}
	return true;
}

int main()
{
	int n = 0, c = 0;
	cout << "Enter n: ";
	cin >> n;
	int matrix[MAX_SIZE][MAX_SIZE];
	int matrix1[MAX_SIZE][MAX_SIZE];
	int matrix2[MAX_SIZE][MAX_SIZE];
	int matrix3[MAX_SIZE][MAX_SIZE];
	int matrix4[MAX_SIZE][MAX_SIZE];
	cout << "Enter elements\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	Output(matrix, n);

	ReflectionMainDiagonal(matrix, matrix1, n);
	ReflectionSecondaryDiagonal(matrix, matrix2, n);
	ReflectionVec(matrix, matrix3, n);
	ReflectionHor(matrix, matrix4, n);

	Output(matrix1, n);
	Output(matrix2, n);
	Output(matrix3, n);
	Output(matrix4, n);

	if(Comparison(matrix1, matrix2, n))
	{
		c++;
		cout << "(1,2)";
	}
	if(Comparison(matrix1, matrix3, n))
	{
		c++;
		cout << "(1,3)";
	}
	if(Comparison(matrix1, matrix4, n))
	{
		c++;
		cout << "(1,4)";
	}
	if(Comparison(matrix2, matrix3, n))
	{
		c++;
		cout << "(2,3)";
	}
	if(Comparison(matrix2, matrix4, n))
	{
		c++;
		cout << "(2,4)";
	}
	if(Comparison(matrix3, matrix4, n))
	{
		c++;
		cout << "(3,4)";
	}
	if (c == 0) cout << "NONE";

	return 0;
}

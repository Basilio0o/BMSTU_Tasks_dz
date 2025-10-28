#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void FillingMatrix(double arr[4][4], double cd[4][4], double e[4][1], int q)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(j == q)
			{
				arr[i][j] = e[i][0];
			}
			else
			{
				arr[i][j] = cd[i][j];
			}
		}
	}
}

double CalculationDeterminant(double mat[4][4])
{
	int A1 = mat[0][0]*(mat[1][1]*(mat[2][2]*mat[3][3] - mat[3][2]*mat[2][3]) - mat[1][2]*(mat[2][1]*mat[3][3] - mat[3][1]*mat[2][3]) + mat[1][3]*(mat[2][1]*mat[3][2] - mat[3][1]*mat[2][2]));
	int A2 = mat[0][1]*(mat[1][0]*(mat[2][2]*mat[3][3] - mat[3][2]*mat[2][3]) - mat[1][2]*(mat[2][0]*mat[3][3] - mat[3][0]*mat[2][3]) + mat[1][3]*(mat[2][0]*mat[3][2] - mat[3][0]*mat[2][2]));
	int A3 = mat[0][2]*(mat[1][0]*(mat[2][1]*mat[3][3] - mat[3][1]*mat[2][3]) - mat[1][1]*(mat[2][0]*mat[3][3] - mat[3][0]*mat[2][3]) + mat[1][3]*(mat[2][0]*mat[3][1] - mat[3][0]*mat[2][1]));
	int A4 = mat[0][3]*(mat[1][0]*(mat[2][1]*mat[3][2] - mat[3][1]*mat[2][2]) - mat[1][1]*(mat[2][0]*mat[3][2] - mat[3][0]*mat[2][2]) + mat[1][2]*(mat[2][0]*mat[3][1] - mat[3][0]*mat[2][1]));
	return A1-A2+A3-A4;
}

int main()
{
	double coordinates[4][4];

	cout << "Enter coordinates\n";

	for (int i = 0; i < 4; i++)
	{
		cin >> coordinates[i][0] >> coordinates[i][1] >> coordinates[i][2];
		coordinates[i][3] = 1;
	}

	double e1 = -(pow(coordinates[0][0], 2) + pow(coordinates[0][1], 2) + pow(coordinates[0][2], 2));
	double e2 = -(pow(coordinates[1][0], 2) + pow(coordinates[1][1], 2) + pow(coordinates[1][2], 2));
	double e3 = -(pow(coordinates[2][0], 2) + pow(coordinates[2][1], 2) + pow(coordinates[2][2], 2));
	double e4 = -(pow(coordinates[3][0], 2) + pow(coordinates[3][1], 2) + pow(coordinates[3][2], 2));

	double e[4][1] = {e1, e2, e3, e4};

	double matrix[4][4], matrixA[4][4], matrixB[4][4], matrixC[4][4], matrixD[4][4];

	FillingMatrix(matrix, coordinates, e, -1);
	FillingMatrix(matrixA, coordinates, e, 0);
	FillingMatrix(matrixB, coordinates, e, 1);
	FillingMatrix(matrixC, coordinates, e, 2);
	FillingMatrix(matrixD, coordinates, e, 3);

	double dx = CalculationDeterminant(matrix);
	double dxA = CalculationDeterminant(matrixA);
	double dxB = CalculationDeterminant(matrixB);
	double dxC = CalculationDeterminant(matrixC);
	double dxD = CalculationDeterminant(matrixD);

	if(dx == 0){
		cout << "There is no equation";
		return 0;
	}

	double a = dxA/dx;
	double b = dxB/dx;
	double c = dxC/dx;
	double d = dxD/dx;

	double x0 = a/2;
	double y0 = b/2;
	double z0 = c/2;

	double r = sqrt(pow(x0, 2) + pow(y0, 2) + pow(z0, 2) - d);
	cout <<  fixed << setprecision(2);
	cout << "Equation of a sphere is " << r;
	cout << showpos;
	cout << "^2 = (x" << x0 << ")^2 + (y" << y0 << ")^2 + (z" << z0 <<")^2";

	return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double matrix[3][3];
	cout << "Enter coordinates\n";
	for (int i = 0; i < 3; i++)
	{
		cin >> matrix[i][0] >> matrix[i][1];
		matrix[i][2] = 1;
	}
	double A1 = (matrix[1][0]*matrix[2][1]) - (matrix[2][0]*matrix[1][1]);
	double A2 = (matrix[0][0]*matrix[2][1]) - (matrix[2][0]*matrix[0][1]);
	double A3 = (matrix[0][0]*matrix[1][1]) - (matrix[1][0]*matrix[0][1]);

	double s = A1 - A2 + A3;
	if(s == 0)
	{
		cout << "Collinear";
	}
	else
	{
		cout << "Not Collinear";
	}
	return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

int CalcDet2(int matrix[2][2])
{
	return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
}

int CalcDet3(int mat[3][3])
{
	return mat[0][0]*(mat[1][1]*mat[2][2] - mat[2][1]*mat[1][2]) - mat[0][1]*(mat[1][0]*mat[2][2] - mat[2][0]*mat[1][2]) + mat[0][2]*(mat[1][0]*mat[2][1] - mat[2][0]*mat[1][1]);
}

int main()
{
	int a1 = 0, b1 = 0, c1 = 0, d1 = 0, a2 = 0, b2 = 0, c2 = 0, d2 = 0, a3 = 0, b3 = 0, c3 = 0, d3 = 0;
	cout << "Enter coefficients\n";
	cin >> a1 >> b1 >> c1 >> d1;
	cin >> a2 >> b2 >> c2 >> d2;
	cin >> a3 >> b3 >> c3 >> d3;
	cout <<  fixed << setprecision(2);

//	//10 x = 2.35, y = 2.76
//	int matrix2[2][2] = {{a1, b1}, {a2, b2}}, matrix2x[2][2] = {{d1, b1}, {d2, b2}}, matrix2y[2][2] = {{a1, d1}, {a2, d2}};
//	int det2 = CalcDet2(matrix2);
//	int det2x = CalcDet2(matrix2x);
//	int det2y = CalcDet2(matrix2y);
//	cout << "Task 10\n";
//	cout << "x = " << (double)det2x / det2 << ", y = " << (double)det2y / det2;

//	//11 x = -2.40, y = 1.60, z = 6.80
//	int matrix3_1[3][3] = {{a1, b1, c1}, {a2, b2, c2}, {a3, b3, c3}}, matrix3_1x[3][3] = {{d1, b1, c1}, {d2, b2, c2}, {d3, b3, c3}},
//			matrix3_1y[3][3] = {{a1, d1, c1}, {a2, d2, c2}, {a3, d3, c3}}, matrix3_1z[3][3] = {{a1, b1, d1}, {a2, b2, d2}, {a3, b3, d3}};
//
//	int det3 = CalcDet3(matrix3_1);
//	int det3x = CalcDet3(matrix3_1x);
//	int det3y = CalcDet3(matrix3_1y);
//	int det3z = CalcDet3(matrix3_1z);
//
//	cout << "Task 11\n";
//	cout << "x = " << (double)det3x / det3 << ", y = " << (double)det3y / det3 << ", z = " << (double)det3z / det3;

//	//12 x = 3.79, y = -1.36, z = -3.86
//	int matrix3_1[3][3] = {{a1, b1, c1}, {a2, b2, c2}, {a3, b3, c3}}, matrix3_1x[3][3] = {{d1, b1, c1}, {d2, b2, c2}, {d3, b3, c3}},
//				matrix3_1y[3][3] = {{a1, d1, c1}, {a2, d2, c2}, {a3, d3, c3}}, matrix3_1z[3][3] = {{a1, b1, d1}, {a2, b2, d2}, {a3, b3, d3}};
//
//	int det3 = CalcDet3(matrix3_1);
//	int det3x = CalcDet3(matrix3_1x);
//	int det3y = CalcDet3(matrix3_1y);
//	int det3z = CalcDet3(matrix3_1z);
//
//	cout << "Task 12\n";
//	cout << "x = " << (double)det3x / det3 << ", y = " << (double)det3y / det3 << ", z = " << (double)det3z / det3;

	return 0;
}

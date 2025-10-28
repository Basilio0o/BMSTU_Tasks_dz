#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double vec1[2], vec2[2], ang = 0;
	cout << "Enter coordinates\n";
	cin >> vec1[0] >> vec1[1];
	cout << "Enter an angle\n";
	cin >> ang;
	double matrix[2][2] = {{cos(ang * M_PI / 180), sin(ang * M_PI / 180)}, {-sin(ang * M_PI / 180), cos(ang * M_PI / 180)}};
	for(int i = 0; i < 2; i++)
	{
		double s = 0;
		for(int j = 0; j < 2; j++)
		{
			s += matrix[i][j]*vec1[j];
		}
		vec2[i] = s;
		s = 0;
	}
	cout << "x = " << vec1[0] << ", y = " << vec1[1] << endl;
	cout << "x1 = " << vec2[0] << ", y1 = " << vec2[1] << endl;
	cout << cos(ang * M_PI / 180);
	return 0;
}

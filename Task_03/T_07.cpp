#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cout << "Enter n, m\n";
	cin >> n >> m;
	int matrix[n][m];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}
	int matRows_min[n];
	fill(matRows_min, matRows_min + n, 10000000);
	int matRows_max[n];
	fill(matRows_max, matRows_max + n, -10000000);
	int matCols_min[m];
	fill(matCols_min, matCols_min + m, 10000000);
	int matCols_max[m];
	fill(matCols_max, matCols_max + m, -10000000);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int value = matrix[i][j];

			if (value < matRows_min[i]) matRows_min[i] = value;
			if (value > matRows_max[i]) matRows_max[i] = value;

			if (value < matCols_min[j]) matCols_min[j] = value;
			if (value > matCols_max[j]) matCols_max[j] = value;
		}
	}

	bool found = false;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int value = matrix[i][j];

			if (value == matRows_min[i] && value == matCols_max[j])
			{
				cout << "Type A " << value << " (" << i + 1<< " " << j + 1 << ")" << endl;
				found = true;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int value = matrix[i][j];

			if (value == matRows_max[i] && value == matCols_min[j])
			{
				cout << "Type B " << value << " (" << i+1 << " " << j+1 << ")" << endl;
				found = true;
			}
		}
	}
	if(!found){
		cout << "NONE";
	}

	return 0;
}

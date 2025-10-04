#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int n = 0, m = 0;
	cout << "Enter n, m ";
	cin >> n >> m;
	int matrix[n][m];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}

	for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}

	int top = 0, bottom = n - 1, right = m - 1, left = 0;
	while(top <= bottom && left <= right)
	{
		for(int l = left; l <= right; l++)
		{
			cout << matrix[top][l] << " ";
		}
		top++;
		for(int t = top; t <= bottom; t++)
		{
			cout << matrix[t][right] << " ";
		}
		right--;
		if (left <= right)
		{
			for(int r = right; r >= left; r--)
			{
				cout << matrix[bottom][r] << " ";
			}
			bottom--;
		}
		if (top <= bottom)
		{
			for(int b = bottom; b >= top; b--)
			{
				cout << matrix[b][left] << " ";
			}
			left++;
		}

	}

	return 0;
}

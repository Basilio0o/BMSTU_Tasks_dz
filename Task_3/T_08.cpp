#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int n;
	cout << "Enter n ";
	cin >> n;
	int matrix[n][n];
	int num = 1;
	int top = 0, bottom = n - 1, right = n - 1, left = 0;
	while(top <= bottom)
	{
		for(int l = left; l <= right; l++)
		{
			matrix[top][l] = num++;
		}
		top++;
		for(int t = top; t <= bottom; t++)
		{
			matrix[t][right] = num++;
		}
		right--;
		if (left <= right)
		{
			for(int r = right; r >= left; r--)
			{
				matrix[bottom][r] = num++;
			}
			bottom--;
		}
		if (top <= bottom)
		{
			for(int b = bottom; b >= top; b--)
			{
				matrix[b][left] = num++;
			}
			left++;
		}

	}


	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << setw(2) << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

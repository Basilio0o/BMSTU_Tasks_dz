#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter n = ";
	cin >> n;
	int matrix[n][n];
	cout << "Enter numbers\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	int s1 = 0, s2 = 0;

	for(int j = 0; j < n; j++)
	{
		s1 += matrix[0][j];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s2 += matrix[i][j];
		}
		if (s1 != s2)
		{
			cout << "NO";
			return 0;
		}
		s2 = 0;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			s2 += matrix[i][j];
		}
		if (s1 != s2)
		{
			cout << "NO";
			return 0;
		}
		s2 = 0;
	}
	for (int j = 0; j < n; j++)
	{
		s2 += matrix[j][j];
	}
	if (s1 != s2)
	{
		cout << "NO";
		return 0;
	}
	s2 = 0;
	for (int j = 0; j < n; j++)
	{
		s2 += matrix[j][n - 1 - j];
	}

	if (s1 != s2)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}

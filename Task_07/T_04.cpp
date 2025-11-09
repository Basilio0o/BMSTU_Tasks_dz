#include <iostream>

using namespace std;

void Output(int **matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void free2D(int **arr, int n)
{
	for(int i = 0; i < n; i++) delete[] arr[i];
	delete[] arr;
}

int **transpose(int **matrix, int n, int m)
{
	int **result = new int*[m];
	for(int i = 0; i < m; i++) result[i] = new int[n];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) result[j][i] = matrix[i][j];
	return result;
}

int main()
{
	srand(time(0));
	int n, m;
	cout << "Введите размеры массива: ";
	cin >> n >> m;
	int** array = new int*[n];
	for(int i = 0; i < n; i++) array[i] = new int[m];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) array[i][j] = rand()%100;
	cout << "Прямая матрица: " << endl;
	Output(array, n, m);
	int **res = transpose(array, n, m);
	cout << "Транспонированная матрица: " << endl;
	Output(res, m, n);
	free2D(array, n);
	free2D(res, m);
	return 0;
}

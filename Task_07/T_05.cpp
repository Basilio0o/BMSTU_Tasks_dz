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

int Sum(int *row, int m)
{
	int s = 0;
	for(int i = 0; i < m; i++) s += row[i];
	return s;
}

void SortArr(int **arr, int n, int m)
{
	int *sums = new int[n];
	for(int i = 0; i < n; i++) sums[i] = Sum(arr[i], m);
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(sums[j] > sums[j+1]){
				int *tpptr = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tpptr;

				int temp = sums[j];
				sums[j] = sums[j+1];
				sums[j+1] = temp;
			}
		}
	}

	delete[] sums;
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
	cout << "Массив до сортировки: " << endl;
	Output(array, n, m);
	SortArr(array, n, m);
	cout << "Массив после сортировки: " << endl;
	Output(array, n, m);
	free2D(array, n);
	return 0;
}

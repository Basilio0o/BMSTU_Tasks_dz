#include <iostream>
#include <iomanip>
using namespace std;

void free2D(int **arr, int n)
{
	for(int i = 0; i < n; i++) delete[] arr[i];
	delete[] arr;
}

int main()
{
	srand(time(0));
	int n, m;
	cout << "Введите размеры массива (кол-во строк небольше кол-ва столбцов): ";
	cin >> n >> m;
	if(n > m){
		cout << "Ошибка в формировании массива" << endl;
		return 0;
	}
	int** array = new int*[n];

	for(int i = 0; i < n; i++) array[i] = new int[m];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m - i; j++)
		{
			array[i][j] = rand()%100;
			cout << setw(2) << array[i][j] << " ";
		}
		cout << endl;
	}
	free2D(array, n);
	return 0;
}

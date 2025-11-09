#include <iostream>

using namespace std;

int sumElements(int **arr, int n, int m)
{
	int s = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) s += *(*(arr + i) + j);
	return s;
}

int main()
{
	int n, m;
	cout << "Введите размеры массива: ";
	cin >> n >> m;
	int** array = new int*[n];
	for(int i = 0; i < n; i++) array[i] = new int[m];
	cout << "Заполните массив: " << endl;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> array[i][j];
	cout << "Ваш массив:" << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << array[i][j] << " ";
		cout << endl;
	}
	int sm = sumElements(array, n, m);
	cout << "Сумма элементов массива: " << sm;
	for(int i = 0; i < n; i++) delete[] array[i];
	delete[] array;
	return 0;
}

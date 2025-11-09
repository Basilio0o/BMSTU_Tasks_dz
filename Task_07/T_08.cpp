#include <iostream>
#include <iomanip>

using namespace std;

void InitialState(double **plate, int n, int m)
{
	int ci = n / 2;
	int cj = m / 2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!(ci == i && cj == j)) plate[i][j] = 20.0;
			else plate[i][j] = 100.0;
		}
	}
}

void Output(double **plate, int n, int m)
{
	cout << fixed << setprecision(2);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << setw(7) << *(*(plate+i)+j) << " ";
		cout << endl;
	}
}

void freePlate(double **plate, int n)
{
	for(int i = 0; i < n; i++) delete[] *(plate + i);
	delete[] plate;
}

double **allocatePlate(int n, int m)
{
	double **plate = new double*[n];
	for(int i = 0; i < n; i++) plate[i] = new double[m];
	return plate;
}

void updateTemperature(double **plate, int n, int m)
{
	double **temp = allocatePlate(n, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) *(*(temp+i)+j) = *(*(plate+i)+j);
	}
	int ci = n/2;
	int cj = m/2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(ci == i && cj == j) continue;
			double sum = 0.0;
			int count = 0;
			if(i > 0){
				sum += *(*(temp+i-1)+j);
				count++;
			}
			if(i < n-1){
				sum += *(*(temp+i+1)+j);
				count++;
			}
			if(j > 0){
				sum += *(*(temp+i)+j-1);
				count++;
			}
			if(j < m-1){
				sum += *(*(temp+i)+j+1);
				count++;
			}
			*(*(plate+i)+j) = sum / count;
		}
	}
	freePlate(temp, n);
}

int main()
{
	int n, m, k;

	cout << "Введите размеры пластины: ";
	cin >> n >> m;
	if(n <= 0 || m <= 0){
		cout << "Ошибка ввода!";
		return 0;
	}

	cout << "Введите количество интераций: ";
	cin >> k;
	if(k <= 0){
		cout << "Ошибка ввода!";
		return 0;
	}

	double **plate = allocatePlate(n, m);
	InitialState(plate, n, m);
	cout << "Начальное распределение температуры на пластине:" << endl;
	Output(plate, n, m);
	cout << endl;
	for(int i = 0; i < k; i++) updateTemperature(plate, n, m);
	cout << "Конечное распределение температуры на пластине:" << endl;
	Output(plate, n, m);
	freePlate(plate, n);
	return 0;
}

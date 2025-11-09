#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int **CreateLoad(int n, int t)
{
	int **load = new int*[n];
	for(int i = 0; i < n; i++) load[i] = new int[t];
	cout << "Вводите нагрузку на каждый узел: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < t; j++){
			cin >> load[i][j];
			if(load[i][j] < 0 || load[i][j] > 100){
				cout << "Ошибка ввода!";
				exit(1);
			}
		}
	}
	return load;
}

double *AverageLoadPerNode(int **load, int n, int t)
{
	double *averages = new double[n];
	for(int i = 0; i < n; i++){
		double s = 0.0;
		for(int j = 0; j < t; j++){
			s += load[i][j];
		}
		averages[i] = s / t;
	}
	return averages;
}

void NormalizeLoad(int **load, int n, int t)
{
	double *averages = AverageLoadPerNode(load, n, t);
	for(int i = 0; i < n; i++){
		if(averages[i] > 80){
			for(int j = 0; j < t; j++){
				if(load[i][j] > 80){
					int dl = round(load[i][j] * 0.1);

					if(n > 1){
						int ddlbs = dl / (n-1);
						int ost = dl % (n-1);
						load[i][j] = load[i][j] - dl;
						int count = 0;
						for(int k = 0; k < n; k++){
							if(k != i){
								int db = ddlbs;
								if(count < ost){
									db++;
									count++;
								}
								load[k][j] = load[k][j] + db;
								if(load[k][j] > 100) load[k][j] = 100;
							}
						}
					}
				}
			}
		}
	}
	delete[] averages;
}

int FindCriticalInterval(int **load, int n, int t)
{
	int idx = 0;
	int max = 0;
	for(int j = 0; j < t; j++){
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += *(*(load + i) + j);
		}
		if(sum > max){
			max = sum;
			idx = j;
		}
	}
	cout << "Критический интервал: " << idx << " (Суммарная нагрузка = " << max << "%)";
	return idx;
}

void PrintMatrix(int **load, int n, int t)
{
	for(int i = 0; i < n; i++){
		cout << "Узел " << i << ": ";
		for(int j = 0; j < t; j++) cout << setw(3) << load[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int n, t;
	cout << "Введите количество узлов и интервалов: ";
	cin >> n >> t;
	if(n <= 0 || t <= 0){
		cout << "Ошибка ввода!";
		return 1;
	}
	int **load = CreateLoad(n, t);
	cout << "Начальное распределение нагрузки:" << endl;
	PrintMatrix(load, n, t);
	double *averages = AverageLoadPerNode(load, n, t);
	cout << fixed << setprecision(2);
	for(int i = 0; i < n; i++) cout << "Средняя нагрузка на узле " << i << ": " << *(averages + i) << endl;
	cout << fixed << setprecision(0);
	NormalizeLoad(load, n, t);
	cout << "Распределение нагрузки после нормализации:" << endl;
	PrintMatrix(load, n, t);
	FindCriticalInterval(load, n, t);

	for (int i = 0; i < n; i++) delete[] load[i];
	delete[] load;
	delete[] averages;
	return 0;
}

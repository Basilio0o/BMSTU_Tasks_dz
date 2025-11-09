#include <iostream>
#include <iomanip>

using namespace std;

double **allocateWeights(int n, int m)
{
	double **weights = new double*[n];
	for(int i = 0; i < n; i++) weights[i] = new double[m];
	return weights;
}

void CreateWeights(double **weights, int n, int m)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) weights[i][j] = (rand() / (double)RAND_MAX) * 2.0 - 1.0;
	}
}

double *CreateInputs(int m)
{
	double *inputs = new double[m];
	cout << "Введите входные значения: " << endl;
	for(int i = 0; i < m; i++) cin >> inputs[i];
	return inputs;
}

double *Forward(double **weights, double *inputs, int n, int m)
{
	double *outputs = new double[n];
	for(int i = 0; i < n; i++){
		double sum = 0.0;
		for(int j = 0; j < m; j++){
			sum += weights[i][j]*inputs[j];
		}
		outputs[i] = sum;
	}
	return outputs;
}

void Normalization(double **weights, int n, int m)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) weights[i][j] /= m;
	}
}

void Output(double **arr, int n, int m)
{
	cout << fixed << setprecision(3);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << setw(8) << arr[i][j] << " ";
		cout << endl;
	}
}

void freeWeights(double **arr, int n)
{
	for(int i = 0; i < n; i++) delete[] arr[i];
	delete[] arr;
}

int main()
{
	srand(time(0));
	int n, m;
	cout << "Задайте кол-во нейронов: ";
	cin >> n;
	cout << "Задайте кол-во входов: ";
	cin >> m;
	double *inputs = CreateInputs(m);
	double **weights = allocateWeights(n,m);
	CreateWeights(weights, n, m);
	cout << "Таблица весов до нормализации:" << endl;
	Output(weights, n, m);
	Normalization(weights, n, m);
	cout << "Таблица весов после нормализации:" << endl;
	Output(weights, n, m);
	double *outputs = Forward(weights, inputs, n, m);
	cout << "Результат вычислений:" << endl;
	for(int i = 0; i < n; i++) cout << outputs[i] << " ";
	delete[] inputs;
	delete[] outputs;
	freeWeights(weights, n);
	return 0;
}

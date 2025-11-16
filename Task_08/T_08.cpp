#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

void Input(unique_ptr<double[]>& arr, int n){
	for(int i = 0; i < n; i++) cin >> *(arr.get() + i);
}

double Average(unique_ptr<double[]>& arr, int n){
	double sm = 0.0;
	for(int i = 0; i < n; i++) sm += *(arr.get() + i);
	return sm / n;
}

int main()
{
	int n;
	cout << "Введите количество значений: ";
	cin >> n;
	unique_ptr<double[]> temperature = make_unique<double[]>(n);
	unique_ptr<double[]> pressure = make_unique<double[]>(n);
	unique_ptr<double[]> humidity = make_unique<double[]>(n);
	cout << "Введите значения температуры: ";
	Input(temperature, n);
	cout << "Введите значения давления: ";
	Input(pressure, n);
	cout << "Введите значения влажности: ";
	Input(humidity, n);
	double average_temp = Average(temperature, n);
	double average_press = Average(pressure, n);
	double average_hum = Average(humidity, n);
	cout << fixed << setprecision(2) << endl;
	cout << "Параметр    Среднее значение" << endl;
	cout << "Температура" << setw(12) << average_temp << endl;
	cout << "Давление" << setw(15) << average_press << endl;
	cout << "Влажность" << setw(14) << average_hum << endl;
	return 0;
}

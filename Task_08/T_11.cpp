#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

int main()
{
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	vector<double> signals(n);
	cout << "Вводите данные: ";
	for(int i = 0; i < n; i++) cin >> signals[i];

	cout << "Исходные данные: ";
	for(int i = 0; i < n; i++) cout << signals[i] << " ";
	cout << endl;

	unique_ptr<double[]> temp = make_unique<double[]>(n);
	for(int i = 0; i < n; i++) temp[i] = signals[i];

	auto mean = [](unique_ptr<double[]>& temp, int n){
		return accumulate(temp.get(), temp.get() + n, 0.0) / n;
	};

	auto mx = max_element(signals.begin(), signals.end());

	auto normalize = [](unique_ptr<double[]>& temp, auto mx, int n){
		transform(temp.get(), temp.get() + n, temp.get(), [&mx](double x){return x / *mx;});
	};

	 auto copyBack = [](unique_ptr<double[]>& arr, vector<double>& vec, int n){
		for(int i = 0; i < n; i++) vec[i] = arr[i];
	};

	auto average_temp = mean(temp, n);
	normalize(temp, mx, n);
	copyBack(temp, signals, n);

	cout << "Среднее значение: " << average_temp;
	cout << fixed << setprecision(3) << endl;
	cout << "Нормализованные сигналы: ";
	for(int i = 0; i < n; i++) cout << signals[i] << " ";

	return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void analyzePressure(const vector<double>& data, double& minVal, double& maxVal, double& avgVal)
{
	const double* p = data.data();
	size_t ln = data.size();
	double sum = 0.0;
	for(size_t i = 0; i < ln; i++)
	{
		if(*(p+i) < minVal) minVal = *(p+i);
		if(*(p+i) > maxVal) maxVal = *(p+i);
		sum += *(p+i);
	}
	avgVal = sum/ln;
}

int main()
{
	int k;
	cout << "Введите количество элементов: ";
	cin >> k;
	vector<double> pressure(k);
	cout << "Вводите элементы:\n";
	for(int i = 0; i < k; i++) cin >> pressure[i];
	double min = pressure[0];
	double max = pressure[0];
	double av = 0.0;
	analyzePressure(pressure, min, max, av);
	cout << fixed << setprecision(2) << endl;
	cout << "Min pressure: " << min << endl;
	cout << "Max pressure: " << max << endl;
	cout << "Average pressure: " << av << endl;
	return 0;
}

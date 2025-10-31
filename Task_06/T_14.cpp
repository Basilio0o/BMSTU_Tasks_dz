#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double computeRMS(const vector<double>& signal)
{
	double r = 0.0;
	const double* p = signal.data();
	size_t ln = signal.size();
	for(size_t i = 0; i < ln; i++)
	{
		r += pow(*(p+i), 2);
	}
	r = sqrt(r/ln);
	return r;
}

int main()
{
	int k;
	cout << "Введите количество элементов: ";
	cin >> k;
	vector<double> signal(k);
	cout << "Вводите элементы:\n";
	for(int i = 0; i < k; i++) cin >> signal[i];
	double rms = computeRMS(signal);
	cout << "RMS value: " << rms << endl;
	return 0;
}

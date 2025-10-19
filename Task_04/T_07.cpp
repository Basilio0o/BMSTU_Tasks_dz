#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iomanip>
using namespace std;
int main()
{
	srand(time(0));
	long unsigned int c = 0;
	int n = 0;
	cout << "Enter the length of the vector\n";
	cin >> n;
	vector<double> temperature(n);
	generate(temperature.begin(), temperature.end(), [](){return rand() % 141 - 70 + (double)(rand()%101)/100;});
	for_each(temperature.begin(), temperature.end(), [](double x){cout << x << " ";});
	temperature.erase(remove_if(temperature.begin(), temperature.end(), [](double x){return abs(x) > 50;}), temperature.end());
	cout << "\nThe vector after cleaning\n";
	for_each(temperature.begin(), temperature.end(), [](double x){cout << x << " ";});
	auto mx = max_element(temperature.begin(), temperature.end());
	auto mn = min_element(temperature.begin(), temperature.end());
	double sm = accumulate(temperature.begin(), temperature.end(), 0.0);
	cout << "\nmax = " << *mx << ", min = " << *mn << ", average value = " << fixed << setprecision(2) << sm/(temperature.size());
	for_each(temperature.begin(), temperature.end(), [&c](double x){if(x > -10) c++;});
	if (c != temperature.size()) cout << "\nnot all values ​​are greater than -10";
	else cout << "\nall values ​​are greater than -10";
	return 0;
}

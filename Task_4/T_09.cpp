#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	srand(time(0));
	long unsigned int c = 0;
	vector<double> power(20);
	generate(power.begin(), power.end(), [](){return rand() % 121 - 30 + (double)(rand()%101)/100;});
	for_each(power.begin(), power.end(), [](double x){cout << x << " ";});
	power.erase(remove_if(power.begin(), power.end(), [](double x){return x < 0;}), power.end());
	cout << "\nThe vector after cleaning\n";
	for_each(power.begin(), power.end(), [](double x){cout << x << " ";});
	double av = accumulate(power.begin(), power.end(), 0);
	cout << "\naverage power = " << fixed << setprecision(2) << av/(power.size()) << " kW";
	auto mx = max_element(power.begin(), power.end());
	auto mn = min_element(power.begin(), power.end());
	cout << "\nmax power is " << *mx << " kW, min power is " << *mn << " kW\n";

	for_each(power.begin(), power.end(), [&c](double x){if(x >= 10 and x <= 90) c++;});

	if (c == power.size()) cout << "the power was in the range from 10 kW to 90 kW";
	else cout << "the power wasn't in the range from 10 kW to 90 kW";

	sort(power.begin(), power.end());

	cout << "\nmedian = " << ((double)power[9] + (double)power[10]) / 2 << " kW";

	return 0;
}

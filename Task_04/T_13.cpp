#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(0));
	long unsigned int c = 0;
	vector<double> pressure(50);
	generate(pressure.begin(), pressure.end(), [](){return (rand() % 10 + 1 + pow(-1, rand())*(double)(rand() % 41)/10);});
	for_each(pressure.begin(), pressure.end(), [](double x){cout << x << " ";});
	pressure.erase(remove_if(pressure.begin(), pressure.end(), [](double x){return (x > 12 || x < 0);}), pressure.end());

	cout << "\nThe vector after cleaning\n";
	for_each(pressure.begin(), pressure.end(), [](double x){cout << x << " ";});
	double sum = accumulate(pressure.begin(), pressure.end(), 0);
	cout << "\nThe average pressure is " << setprecision(3) << sum/pressure.size();

	auto mn = min_element(pressure.begin(), pressure.end());
	auto mx = max_element(pressure.begin(), pressure.end());

	cout << "\nmin = " << *mn << " bar" << ", max = " << *mx << " bar\n";

	for_each(pressure.begin(), pressure.end(), [&c](double x){if(x > 8) cout << x << " ";});

	return 0;
}

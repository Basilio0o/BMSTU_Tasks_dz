#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	srand(time(0));
	vector<double> power(30);

	generate(power.begin(), power.end(), [](){return rand() % 10 + 15 + (double)(rand()%101)/100;});

	for_each(power.begin(), power.end(), [](double x){cout << x << " ";});

	double sm = accumulate(power.begin(), power.end(), 0);

	cout << "\nThe total electricity consumption per month = " << sm << " kW*h";

	cout << "\nThe average power consumption per day = " << fixed << setprecision(2) << sm/30 << " kW*h";
	auto mx = max_element(power.begin(), power.end());
	auto mn = min_element(power.begin(), power.end());

	cout << "\nThe max power consumption (" << *mx <<" kW*h) was in " << mx - power.begin() + 1
			<< " day, the min power consumption (" << *mn << " kW*h) was in " << mn - power.begin() + 1 << " day";

	power.erase(remove_if(power.begin(), power.end(), [&sm](double x){return x > 1.2*sm/30;}), power.end());
	cout << "\nThe vector after cleaning\n";
	for_each(power.begin(), power.end(), [](double x){cout << x << " ";});
	return 0;
}

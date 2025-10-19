#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(0));
	vector<int> consumption(24);
	vector<double> deviations(24);
	generate(consumption.begin(), consumption.end(), [](){return rand() % 401 + 100;});
	for_each(consumption.begin(), consumption.end(), [](int x){cout << x << " ";});

	int sum = accumulate(consumption.begin(), consumption.end(), 0);

	cout << "\nThe total consumption per day is " << sum << " kW*h, the average consumption per hour is " << setprecision(3) << (double)sum/24 << " kW*h";

	auto mx = max_element(consumption.begin(), consumption.end());
	int mxc = count(consumption.begin(), consumption.end(), *mx);
	cout << "\nPeak consumption (" << *mx << " kW*h) hour(s): ";

	int c = 1;
	for(int i = 0; i < 24; i++)
	{
		if((consumption[i] == *mx) && (mxc == c))
		{
			cout << i + 1 << " hour";
			c++;
		}
		else if((consumption[i] == *mx) && (mxc != c))
		{
			cout << i + 1 << " hour, ";
			c++;
		}
	}
	cout << "\n";
	transform(consumption.begin(), consumption.end(), deviations.begin(), [&sum](int x){return x - (double)sum/24;});
	sort(deviations.begin(), deviations.end());
	for(int i = 0; i < 5; i++)
	{
		auto temp = find(consumption.begin(), consumption.end(), deviations[i]+(double)sum/24);
		cout << i + 1 << ". " << temp - consumption.begin() + 1 << " hour (" << deviations[i]+(double)sum/24 << " kW*h) ";
	}
	return 0;
}

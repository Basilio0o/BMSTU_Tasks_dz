#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	srand(time(0));
	vector<double> speed(50);
	generate(speed.begin(), speed.end(), [](){return rand() % 180 + (double)(rand()%101)/100;});
	for_each(speed.begin(), speed.end(), [](double x){cout << x << " ";});
	speed.erase(remove_if(speed.begin(), speed.end(), [](double x){return x > 120;}), speed.end());
	cout << "\nThe vector after cleaning\n";
	for_each(speed.begin(), speed.end(), [](double x){cout << x << " ";});
	double av = accumulate(speed.begin(), speed.end(), 0);
	cout << "\naverage value = " << fixed << setprecision(2) << av/(speed.size());
	auto p0 = find(speed.begin(), speed.end(), 0);
	if (p0 != speed.end()) cout << "\nThe car stopped\n";
	else cout << "\nThe car didn't stopped\n";
	sort(speed.begin(), speed.end(), greater<int>());
	if(speed.size() >= 10)
	{
		for(int i = 0; i < 10; i++)
		{
			cout << speed[i] << " ";
		}
	}
	else for_each(speed.begin(), speed.end(), [](double x){cout << x << " ";});
	return 0;
}

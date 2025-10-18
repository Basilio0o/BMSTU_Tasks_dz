#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	srand(time(0));
	vector<double> fuel(50);
	generate(fuel.begin(), fuel.end(), [](){return (rand() % 80 + 1 + (double)(rand() % 201)/10);});
	for_each(fuel.begin(), fuel.end(), [](double x){cout << x << " ";});

	auto mn = min_element(fuel.begin(), fuel.end());
	cout << "\nmin = " << *mn << " l";

	if (*mn < 5) cout << "\nThe fuel level was below 5% of maximum level";
	else cout << "\nThe fuel level wasn't below 5% of maximum level";

	if(*fuel.begin() > *(fuel.end() - 1)) cout << "\naverage consumption is " << (*fuel.begin() - *(fuel.end() - 1));
	else cout << "\nError";

	sort(fuel.begin(), fuel.end());
	cout << "\nmedian = " << ((double)fuel[24] + (double)fuel[25]) / 2 << " l";

	return 0;
}

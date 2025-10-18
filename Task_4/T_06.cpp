#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	srand(time(0));
	vector<int> vec(20);
	generate(vec.begin(), vec.end(), [](){return rand() % 101 - 50;});
	for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});
	cout << "\n";
	auto i7 = find(vec.begin(), vec.end(), 7);
	if (i7 != vec.end())
	{
		cout << "7 in vector\n";
	}
	else
	{
		cout << "7 not in vector\n";
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});
	return 0;
}

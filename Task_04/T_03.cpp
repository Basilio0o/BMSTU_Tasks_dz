#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	srand(time(0));
	vector<int> vec(20);
	generate(vec.begin(), vec.end(), []() {return rand() % 101;});
	for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});
	auto mx = max_element(vec.begin(), vec.end());
	cout << "\nmax = " << *mx;
	return 0;
}

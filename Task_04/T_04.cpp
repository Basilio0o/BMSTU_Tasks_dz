#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	vector<int> vec(20);
	generate(vec.begin(), vec.end(), []() {return rand() % 201 - 100;});
	for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});
	vec.erase(remove_if(vec.begin(), vec.end(), [](int i) {return i < 0;}), vec.end());
	cout << "\n";
	for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});
	return 0;
}

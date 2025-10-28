#include <iostream>
#include <vector> //vector
#include <numeric> //iota
#include <algorithm> //for_each
using namespace std;
int main()
{
	vector<int> numbers(10);
	iota(numbers.begin(), numbers.end(), 1);
	for_each(numbers.begin(), numbers.end(), [](int x){cout << x << "\n";});
	return 0;
}

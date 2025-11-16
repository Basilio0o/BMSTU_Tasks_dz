#include <iostream>
#include <memory>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

void ProcessA(shared_ptr<std::vector<int>>& arr, int n){
	for_each(arr->begin(), arr->end(), [](int& x){return x += 1;});
}

void ProcessB(shared_ptr<std::vector<int>>& arr, int n){
	for_each(arr->begin(), arr->end(), [](int& x){return x *= 2;});
}

int main()
{
	int n = 10;
	shared_ptr<std::vector<int>> buffer = make_shared<std::vector<int>>(n);
	iota(buffer->begin(), buffer->end(), 1);
	ProcessA(buffer, n);
	ProcessB(buffer, n);
	for(int i = 0; i < n; i++) cout << (*buffer)[i] << " ";
	return 0;
}

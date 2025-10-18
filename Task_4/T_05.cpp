#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <numeric>


using namespace std;

int main()
{
	srand(time(0));
	int n = 0;
	cout << "Enter the length of the vector\n";
	cin >> n;
	vector<int> vec(n);
	generate(vec.begin(), vec.end(), [](){return rand() % 201 - 100;});
	for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});
	auto mx = max_element(vec.begin(), vec.end());
	auto mn = min_element(vec.begin(), vec.end());
	cout << "\nmax = " << *mx << ", min = " << *mn;
	double sm = accumulate(vec.begin(), vec.end(), 0);
	cout << "\naverage value = " << sm/n << endl;
	sort(vec.begin(), vec.end()); // sort(vec.begin(), vec.end(), greater<int>()); для убывания
	for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});

	if(vec.size()%2 == 0)
	{
		cout << "\nmedian = " << ((double)vec[vec.size()/2 - 1] + (double)vec[vec.size()/2]) / 2;
	}
	else
	{
		cout << "\nmedian = " << vec[vec.size()/2];
	}

	return 0;
}

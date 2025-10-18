#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
	vector<double> engine(50);
	long unsigned int c = 0;
	generate(engine.begin(), engine.end(), [](){return (rand() % 11 + (double)(rand() % 101)/100);});
	for_each(engine.begin(), engine.end(), [](double x){cout << x << " ";});
	engine.erase(remove_if(engine.begin(), engine.end(), [](double i) {return i < 0.1;}), engine.end());
	cout << "\nThe vector after cleaning\n";
	for_each(engine.begin(), engine.end(), [](double x){cout << x << " ";});

	auto mx = max_element(engine.begin(), engine.end());
	double sum = accumulate(engine.begin(), engine.end(), 0);
	cout << "\naverage value is " << sum/engine.size() << ", max is " << *mx;

	for(long unsigned int i = 0; i < engine.size(); i++) if (engine[i] > 0.5) c++;

	if (c == engine.size())
	{
		cout << "\nall values ​​are greater than 0.5";
	}
	else
	{
		cout << "\nnot all values ​​are greater than 0.5";
	}
	sort(engine.begin(), engine.end(), greater<int>());
	cout << "\n";
	if(engine.size() >= 10)
	{
		for(int i = 0; i < 10; i++)
		{
			cout << engine[i] << " ";
		}
	}
	else for_each(engine.begin(), engine.end(), [](double x){cout << x << " ";});
	return 0;
}

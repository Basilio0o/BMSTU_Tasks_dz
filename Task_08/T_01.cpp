#include <iostream>
#include <memory>

using namespace std;

int main()
{
	unique_ptr<int> ptr = make_unique<int>();
	*ptr = 10;
	cout << *ptr << endl;
	*ptr = 25;
	cout << *ptr << endl;
	return 0;
}

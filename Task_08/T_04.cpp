#include <iostream>
#include <memory>

using namespace std;

int main()
{
	unique_ptr<int> ptr1 = make_unique<int>(42);
	unique_ptr<int> ptr2 = move(ptr1);
	if(!ptr1) cout << "ptr1 пуст" << endl;
	if(ptr2) cout << "Значние в ptr2: " << *ptr2 << endl;
	return 0;
}

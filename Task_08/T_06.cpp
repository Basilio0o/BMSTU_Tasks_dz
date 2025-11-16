#include <iostream>
#include <memory>

using namespace std;

int main(){
	shared_ptr<int> ptr1 = make_shared<int>(50);
	shared_ptr<int> ptr2 = ptr1;
	cout << "Количество указателей, указывающих на один объект: " << ptr1.use_count() << endl;
	shared_ptr<int> ptr3 = ptr1;
	cout << "Количество указателей, указывающих на один объект: " << ptr1.use_count() << endl;
	ptr1.reset();
	if(!ptr1) cout << "ptr1 пуст!" << endl;
	cout << "Количество указателей, указывающих на один объект: " << ptr2.use_count();
	return 0;
}

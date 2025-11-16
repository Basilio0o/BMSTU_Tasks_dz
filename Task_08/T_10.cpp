#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int[]> CreateArray(int n){
	unique_ptr<int[]> arr = make_unique<int[]>(n);
	for(int i = 0; i < n; i++) *(arr.get() + i) = i+1;
	return arr;
}

int main()
{
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	unique_ptr array = CreateArray(n);
	for(int i = 0; i < n; i++) cout << *(array.get() + i) << " ";
	return 0;
}

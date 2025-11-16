#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	unique_ptr<int[]> array = make_unique<int[]>(n);
	for(int i = 0; i < n; i++){
		array[i] = i+1;
		cout << array[i] << " ";
	}

	return 0;
}

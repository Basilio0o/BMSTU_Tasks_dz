#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k;
	cout << "Введите количество элементов: ";
	cin >> k;
	vector<int> num(k);
	cout << "Вводите числа:\n";
	for(int i = 0; i < k; i++) cin >> num[i];
	int* p = num.data();
	for(int* ptr = p; ptr < p + k; ptr++)
	{
		*ptr += 10;
		cout << *ptr << " ";
	}
	return 0;
}







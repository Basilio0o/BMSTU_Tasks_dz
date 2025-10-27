#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k;
	int s = 0;
	cout << "Введите количество элементов: ";
	cin >> k;
	vector<int> num(k);
	cout << "Вводите числа:\n";
	for(int i = 0; i < k; i++) cin >> num[i];
	int* p = &num[0];
	for(int* ptr = p; ptr < p + k; ptr++) s += *ptr;
	cout << "Сумма элементов: " << s;
	return 0;
}

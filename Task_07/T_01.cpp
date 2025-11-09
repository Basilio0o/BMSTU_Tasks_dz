#include <iostream>

using namespace std;

void swapPointers(int **a, int **b)
{
	int *temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x, y;
	cout << "Введите два числа: ";
	cin >> x >> y;
	int *p1 = &x;
	int *p2 = &y;
	cout << "Первый адрес: " << p1 << ", второй адрес: " << p2 << endl;
	cout << "Значение в первом адресе: " << *p1 << ", значение во втором адресе: " << *p2 << endl;
	swapPointers(&p1, &p2);
	cout << "Первый адрес: " << p1 << ", второй адрес: " << p2 << endl;
	cout << "Значение в первом адресе: " << *p1 << ", значение во втором адресе: " << *p2 << endl;
	return 0;
}

#include <iostream>
using namespace std;

int myStrLen(const char* str)
{
	int ln = 0;
	while(*str != '\0')
	{
		ln++;
		str++;
	}
	return ln;
}

int main()
{
	int k;
	cout << "Введите максимальную длину строки: ";
	cin >> k;
	cin.ignore();
	char* str = new char[k+1];
	cout << "Введите вашу строку: ";
	cin.getline(str, k+1);
	cout << "Ваша строка: "<< str << endl;
	cout << "Длина строки: " << myStrLen(str);
	delete[] str;
	return 0;
}

#include <iostream>
using namespace std;

void myStrCopy(char* dest, const char* src)
{
	while(*src != '\0') *(dest++) = *(src++);
}

int main()
{
	int k;
	cout << "Введите длину строки: ";
	cin >> k;
	cin.ignore();
	char* str1 = new char[k+1];
	char* str2 = new char[k+1];
	cout << "Введите вашу строку: ";
	cin.getline(str1, k+1);
	myStrCopy(str2, str1);
	cout << "Ваша строка: " << str2 << endl;
	delete[] str1;
	delete[] str2;
	return 0;
}

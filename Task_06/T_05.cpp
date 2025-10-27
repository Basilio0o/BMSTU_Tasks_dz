#include <iostream>

using namespace std;

void Replace(char* str)
{
	while(*str != '\0')
	{
		if(*str == ' ') *str = '_';
		str++;
	}
}

int main()
{
	int k;
	cout << "Введите длину строки: ";
	cin >> k;
	cin.ignore();
	char* str = new char[k+1];
	cout << "Введите вашу строку: ";
	cin.getline(str, k+1);
	Replace(str);
	cout << "Новая строка: " << str << endl;
	delete[] str;
	return 0;
}

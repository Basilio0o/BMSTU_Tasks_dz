#include <iostream>

using namespace std;

void reverse(char* str)
{
	char* end = str;
	while(*end != '\0') end++;
	end--;
	char temp;
	while(str < end)
	{
		temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
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
	reverse(str);
	cout << "Перевёрнутая строка: " << str << endl;
	delete[] str;
	return 0;
}

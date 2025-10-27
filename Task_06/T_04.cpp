#include <iostream>

using namespace std;

int myCountStr(const char* str, char ch)
{
	int c = 0;
	while(*str != '\0')
	{
		if(*(str++) == ch) c++;
	}
	return c;
}

int main()
{
	int k;
	char q;
	cout << "Введите длину строки: ";
	cin >> k;
	cin.ignore();
	char* str = new char[k+1];
	cout << "Введите вашу строку: ";
	cin.getline(str, k+1);
	cout << "Введите символ: ";
	cin >> q;
	cout << "Количество " << q << " в строке: " << myCountStr(str, q) << endl;
	delete[] str;
	return 0;
}

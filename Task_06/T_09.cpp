#include <iostream>

using namespace std;

void delspace(char* str1, char* str2)
{
	while(*str1 != '\0')
	{
		if(*str1 != ' ')
		{
			*str2 = *str1;
			str2++;
		}
		str1++;

	}
	*str2 = *str1;
}

int main()
{
	int k;
	cout << "Введите максимальную длину строки: ";
	cin >> k;
	cin.ignore();
	char* str1= new char[k+1];
	char* str2 = new char[k+1];
	cout << "Введите вашу строку: ";
	cin.getline(str1, k+1);
	cout << "Ваша строка: "<< str1 << endl;
	delspace(str1, str2);
	cout << "Очищенная строка: " << str2;
	delete[] str1;
	delete[] str2;
	return 0;
}

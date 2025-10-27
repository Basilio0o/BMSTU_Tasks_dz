#include <iostream>

using namespace std;

int myStrCmp(const char* s1, const char* s2)
{
	while(*s1 != '\0' && *s2 != '\0')
	{
		if(*s1 != *s2) return *s1 - *s2;
		s1++;
		s2++;
	}
	return 0;
}
int main()
{
	int k;
	cout << "Введите максимальную длину строки: ";
	cin >> k;
	cin.ignore();
	char* str1 = new char[2*k+1];
	char* str2 = new char[k+1];
	cout << "Введите первую строку строку: ";
	cin.getline(str1, k+1);
	cout << "Введите вторую строку строку: ";
	cin.getline(str2, k+1);
	int q = myStrCmp(str1, str2);
	if(q == 0) cout << "Строки равны";
	else if(q > 0) cout << "Первая строка больше второй";
	else cout << "Вторая строка больше первой";
	delete[] str1;
	delete[] str2;
	return 0;
}

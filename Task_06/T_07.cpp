#include <iostream>

using namespace std;

bool isPalindrome(const char* str)
{
	bool f = true;
	const char* end = str;
	while(*end != '\0') end++;
	end--;
	while(str < end)
	{
		if(*(str++) != *(end--))
		{
			f = false;
			break;
		}
	}
	return f;
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
	if(isPalindrome(str)) cout << "Палиндром" << endl;
	else cout << "Не палиндром" << endl;
	delete[] str;
	return 0;
}

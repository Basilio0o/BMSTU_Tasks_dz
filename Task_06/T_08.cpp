#include <iostream>

using namespace std;

const char* findSubstring(const char* text, const char* word)
{
	const char* temp = word;
	const char* end = word;
	while(*end != '\0') end++;
	end--;
	bool f = true;
	while(*text != '\0')
	{
		if(*text == *temp) temp++;
		else temp = word;
		if(*temp == '\0')
		{
			temp = text - (end - word);
			f = false;
			break;
		}
		text++;
	}
	if(f) temp = nullptr;
	return temp;
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
	cout << "Введите строку, которую нужно найти: ";
	cin.getline(str2, k+1);
	const char* q = findSubstring(str1, str2);
	if(q == nullptr) cout << "Подстрока не найдена";
	else cout << "Подстрока найдена на позиции: " << q - str1;
	delete[] str1;
	delete[] str2;
	return 0;
}

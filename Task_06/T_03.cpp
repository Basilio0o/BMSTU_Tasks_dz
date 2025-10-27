#include <iostream>
using namespace std;

void myStrCat(char* dest, const char* src)
{
	while(*dest != '\0') dest++;
	while(*src != '\0') *(dest++) = *(src++);

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
	myStrCat(str1, str2);
	cout << "Объединённые строки: " << str1 <<endl;

	delete[] str1;
	delete[] str2;
	return 0;
}

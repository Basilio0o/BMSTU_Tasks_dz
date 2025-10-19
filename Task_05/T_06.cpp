#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
	char str[100];
	int n = 0;
	cout << "Enter the string: ";
	cin.getline(str, 100);
	cout << "Enter shift: ";
	cin >> n;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z') str[i] = (str[i] - 'A' + n) % 26 + 'A';
		if(str[i] >= 'a' && str[i] <= 'z') str[i] = (str[i] - 'a' + n) % 26 + 'a';
	}
	cout << str;
	return 0;
}

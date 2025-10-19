#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
	int n = 0;
	cout << "Enter the length of the string: ";
	cin >> n;

	cin.ignore();

	cout << "Enter the string: ";
	char* str = new char[n + 1];
	cin.getline(str, n+1);

	for(size_t i = 0; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}

	str[0] = toupper(str[0]);

	for(size_t i = 0; i < strlen(str); i++)
	{
		if(str[i] == '.' || str[i] == '!' || str[i] == '?')
		{
			if (i + 2 < strlen(str)) {
				str[i+2] = toupper(str[i+2]);
			}
		}
	}
    cout << "\nResult: " << str << endl;
    delete[] str;
    return 0;
}

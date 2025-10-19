#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
	char str[100];
	char vowels[] = {'A', 'E', 'I', 'O', 'U', 'Y', '\0'};
	int cvow = 0, ccon = 0;
	cout << "Enter the string: ";
	cin.getline(str, 100);
	int i = 0;
	while(str[i] != '\0')
	{
		if(toupper(str[i]) >= 'A' && toupper(str[i]) <= 'Z')
		{
			if(strchr(vowels, toupper(str[i])) != nullptr) cvow++;
			else ccon++;
		}
		i++;
	}
	cout << "\nThe Number of vowels is " << cvow;
	cout << "\nThe Number of consonants is " << ccon;
	return 0;
}

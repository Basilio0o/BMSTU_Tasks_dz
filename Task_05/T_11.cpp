#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	int k = 0;
	cout << "Enter k: ";
	cin >> k;
	cin.ignore();
	cout << "Enter the string: ";
	char str[100];
	cin.getline(str, 100);
	char strsub[1000] =  "";

	for (size_t start = 0; start <= strlen(str) - k; start++)
	{
		char temp[100] = "";

		strncpy(temp, str + start, k);
		temp[k] = '\0';

		bool f = true;

		for(int i = 0; i < k; i++)
		{
			for(int j = i + 1; j < k; j++)
			{
				if (temp[i] == temp[j])
				{
					f = false;
					break;
				}
			}
		}
		if(f && (strstr(strsub, temp) == nullptr)) cout << temp << "\n";
		strcat(strsub, temp);

	}
	return 0;
}

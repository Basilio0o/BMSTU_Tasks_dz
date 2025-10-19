#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str1[100];
	char str2[100];
	cout << "Enter the first string: ";
	cin.getline(str1, 100);
	cout << "Enter the second string: ";
	cin.getline(str2, 100);

	char longest_common[100] = "";
	size_t max = 0;

	for (size_t start = 0; start < strlen(str2); start++)
	{

		for (size_t len = 1; len <= strlen(str2) - start; len++)
		{
			char temp[100] = "";
			strncpy(temp, str2 + start, len);
			temp[len] = '\0';
			if (strstr(str1, temp) != nullptr)
			{
				if (len > max)
				{
					max = len;
					strcpy(longest_common, temp);
				}
			}
			else break;
		}
	}
	cout << max << " " << longest_common;
    return 0;
}

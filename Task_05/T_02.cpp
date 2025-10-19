#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cout << "Enter the string: ";
    cin.getline(str, 100);
    int c = 0;
    cout << "Unique characters: ";
    for (long unsigned int i = 0; i < strlen(str); i++)
    {
        bool uniq = true;
        for (long unsigned int j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                uniq = false;
                break;
            }
        }
        if (uniq)
		{
        	cout << str[i];
        	c++;
		}
    }
    cout << "\nNumber of unique symbols in the string: " << c;
    return 0;
}

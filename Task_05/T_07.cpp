#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n = 0;
	cout << "Enter the length of the string: ";
	cin >> n;

	cin.ignore();

	cout << "Enter the string: ";
	char* str = new char[n + 1];
	char* RLEstr = new char[2*n + 1];
	RLEstr[0] = '\0';
	int rle_i = 0;
	cin.getline(str, n+1);
	char temp = str[0];
	int c = 1;
    for (int i = 1; i < strlen(str) + 1; i++)
    {
        if (str[i] == temp) c++;
        else
        {
        	RLEstr[rle_i++] = temp;
        	RLEstr[rle_i++] = (char)(c+48);
        	temp = str[i];
        	c = 1;
        }
    }

    cout << "\nResult: " << RLEstr << endl;
    delete[] str;
    delete[] RLEstr;
    return 0;
}

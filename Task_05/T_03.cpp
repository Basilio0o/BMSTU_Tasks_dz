#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cout << "Enter the string: ";
    cin.getline(str, 100);
    char* newstr = new char[strlen(str) + 1];
    int k = 0;
    for (long unsigned int i = 0; i < strlen(str); i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9')) newstr[k++] = str[i];
    }
    newstr[k] = '\0';
    cout << "The string after cleaning is : " << newstr;
    delete[] newstr;
    return 0;
}

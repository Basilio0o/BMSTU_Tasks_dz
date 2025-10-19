#include <iostream>
#include <string>
using namespace std;

int main()
{
    int c = 0;
    string strA;
    string strB;
    cout << "Enter the first string: ";
    cin >> strA;
    cout << "Enter the second string: ";
    cin >> strB;
    for(int i = 0; i < strB.length() ; i++)
    {
        for(int j = 0; j < strA.length(); j++) if(strB[i] == strA[j]) c += 1;
		if(c == 0)
		{
        cout << "Letter: " << strB[i] << " not in Astring. The answer is NO";
        return 0;
		}
    }
    cout << "All symbols in Bstring are in Astring. The answer is YES";
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int c = 0;
    char q;
    string vowels {"AaEeIiOoUuYy"};
    cout << "Enter a string\n";
    cin >> q;
    while (q != '0')
    {   
        for (int i = 0; i < 12; i++)
        {
            if (vowels[i] == q){
            c++;
            break;
            }
        }
        cin >> q;
    }
    cout << "The number of vowels is " << c;
    return 0;
}
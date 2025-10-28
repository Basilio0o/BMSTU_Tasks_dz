#include <iostream>
using namespace std;
int main()
{
    double n; 
    cout << "Enter a number ";
    cin >> n;
    if (n > 0)
        cout << n << " > 0";
    else if (n < 0)
        cout << n << " < 0";
    else
        cout << n << " = 0";
    return 0;
}
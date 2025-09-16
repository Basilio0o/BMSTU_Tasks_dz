#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number ";
    cin >> num;
    if (num % 15 == 0)
        cout << "Divisible by 3 and 5";
    else if(num % 5 == 0)
        cout << "Divisible by 5";
    else if(num % 3 == 0)
        cout << "Divisible by 3";
    else
        cout << "Not divisible by 3 and 5";
    return 0;
}
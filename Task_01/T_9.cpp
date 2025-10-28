#include <iostream>
using namespace std;
int main()
{
    int n = 0, s = 0;
    cout << "Enter a number ";
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % 2 == 0 || i % 5 == 0)
            s += i;
    }
    cout << "Sum is " << s;
    return 0;
}
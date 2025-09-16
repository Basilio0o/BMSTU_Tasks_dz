#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number ";
    cin >> n;
    for(int i = 1; i < n + 1; i++)
    {
        cout << pow(i, 2) << endl;
    }
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n = 0, c = 0;
    cout << "Enter a number of elements: ";
    cin >> n;
    unsigned int arr[n];
    cout << "Enter numbers\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] > pow(2, i+1)) c++;
    }
    cout << "count = " << c;
    return 0;
}
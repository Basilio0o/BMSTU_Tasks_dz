#include <iostream>
using namespace std;
int main()
{
    int mx = 0, chet = 0, n = 0;
    cout << "Enter a number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter numbers\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] % 2 == 0) chet++;
        else{
            if (arr[i] > mx) mx = arr[i];
        }
    }
    cout << "Max nechet = " << mx << ", count chet = " << chet;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    double arr[15];
    cout << "Enter numbers\n";
    for (int i = 0; i < 15; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < 15; i++){
        cout << arr[i] << " ";
    }
    double mx = 0, mn = arr[0];
    for (int i = 0; i < 15; i++){
        if (arr[i] < mn) mn = arr[i];
        else if (arr[i] > mx) mx = arr[i];
    }
    swap(arr[0], mn);
    swap(arr[14], mx);
    cout << "\n";
    for (int i = 0; i < 15; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
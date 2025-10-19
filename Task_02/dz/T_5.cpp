#include <iostream>
using namespace std;
int main()
{
    double arr[10];
    cout << "Enter numbers\n";
    for (int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    double mx = 0, mn = arr[0];
    for (int i = 0; i < 10; i++){
        if (arr[i] < mn){
            mn = arr[i];
        }
        else if (arr[i] > mx){
            mx = arr[i];
        }
    }
    cout << "\n";
    if (mn == arr[4] && mx == arr[9]){
        cout << (mx+mn) / 2;
    }
    else {
        cout << "Error";
    }
    return 0;
}
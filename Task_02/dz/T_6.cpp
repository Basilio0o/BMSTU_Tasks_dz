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
        if (arr[i] < mn){
            mn = arr[i];
        }
        else if (arr[i] > mx){
            mx = arr[i];
        }
    }
    cout << "\n";
    if (mn == arr[1] && mx == arr[0]){
        for (int i = 0; i < 15; i++){
        arr[i] /= 2;
        cout << arr[i] << " ";
        }
    }
    else {
        cout << "Error";
    }
    return 0;
}
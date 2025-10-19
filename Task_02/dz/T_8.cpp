#include <iostream>
using namespace std;
int main()
{
    int arr[10];
    cout << "Enter numbers\n";
    for (int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    int mx = 0, mn = arr[0];
    for (int i = 0; i < 10; i++){
        if (arr[i] < mn){
            mn = arr[i];
        }
        else if (arr[i] > mx){
            mx = arr[i];
        }
    }
    cout << "\n";
    if (mn == arr[4] && mx == arr[1]){
        for (int i = 5; i < 10; i++){
            arr[i] = mx;
        }
    }
    else {
        cout << "Error";
        return 0;
    }

    for (int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
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
    int mx_index = 0, mn_index = 0;
    for (int i = 0; i < 15; i++){
        if (arr[i] <= mn){
            mn = arr[i];
            mn_index = i;
        }
        else if (arr[i] > mx){
            mx = arr[i];
            mx_index = i;
        }
    }
    cout << "\n";
    if (mn_index - mx_index > 0) {
        cout << mx*mn;
    }
    else {
        cout << "Error";
    }
    return 0;
}
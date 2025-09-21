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
    if (mn == 0 || mx == 0){
        for(int i = 0; i < mn_index; i++){
            arr[i] = 0;
        }
    }
    else {
        cout << "Error";
        return 0;
    }

    for (int i = 0; i < 15; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
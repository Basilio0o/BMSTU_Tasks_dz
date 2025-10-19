#include <iostream>
using namespace std;
int main()
{
    double coord[3][2];
    double c_x = 0.0, c_y = 0.0;
    cout << "Enter coordinates\nX Y\n";
    for (int i = 0; i < 3; i++){
        cin >> coord[i][0] >> coord[i][1];
    }
    if ((coord[1][0] - coord[0][0]) / (coord[2][0] - coord[1][0]) == (coord[1][1] - coord[0][1]) / (coord[2][1] - coord[1][1]))
        cout << "The points belong to the same line";
    else
        cout << "The points belong to different lines";
    return 0;
}
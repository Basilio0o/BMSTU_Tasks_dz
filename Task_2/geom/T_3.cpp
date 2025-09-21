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
    c_x = (coord[0][0] + coord[1][0] + coord[2][0]) / 3;
    c_y = (coord[0][1] + coord[1][1] + coord[2][2]) / 3;
    cout << "Cx = " << c_x << ", Cy = " << c_y;
    return 0;
}
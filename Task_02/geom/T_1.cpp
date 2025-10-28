#include <iostream>
using namespace std;
int main()
{
    double coord[3][2];
    double s;
    cout << "Enter coordinates\nX Y\n";
    for (int i = 0; i < 3; i++){
        cin >> coord[i][0] >> coord[i][1];
    }
    s = 0.5*(coord[0][0]*(coord[1][1] - coord[2][1]) + coord[1][0]*(coord[2][1] - coord[0][1]) + coord[2][0]*(coord[0][1] - coord[1][1]));
    cout << "Square = " << s;
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double coord[4][2];
    double d;
    cout << "Enter coordinates\nX Y\n";
    for (int i = 0; i < 4; i++){
        cin >> coord[i][0] >> coord[i][1];
    }
    d = sqrt(pow(coord[0][0] - coord[2][0],2) + pow(coord[0][1] - coord[2][1],2));
    cout << "Diagonal = " << d;
    return 0;
}
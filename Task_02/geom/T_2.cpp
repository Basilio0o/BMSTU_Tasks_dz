#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double coord[4][2];
    double p;
    cout << "Enter coordinates\nX Y\n";
    for (int i = 0; i < 4; i++){
        cin >> coord[i][0] >> coord[i][1];
    }
    for (int i = 0; i < 3; i++){
        p += sqrt(pow(coord[i+1][0] - coord[i][0],2) + pow(coord[i+1][1] - coord[i][1],2));
    }
    p += sqrt(pow(coord[3][0] - coord[0][0],2) + pow(coord[3][1] - coord[0][1],2));
    cout << "Perimeter = " << p;
    return 0;
}
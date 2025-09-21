#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int orient(double a[2], double b[2], double c[2])
{
    double n = (a[0] - b[0])*(c[1] - b[1]) - (a[1] - b[1])*(c[0] - b[0]);
    if (n > 0)
        return 1;
    else if (n < 0)
        return -1;
    else 
        return 0;
}

bool segment(double a[2], double b[2], double c[2])
{
    return b[0] <= max(a[0], c[0]) && b[0] >= min(a[0], c[0]) && b[1] <= max(a[1], c[1]) && b[1] >= min(a[1], c[1]);
}

bool intersect(double arr1[2][2], double arr2[2][2])
{
    int o1 = orient(arr1[0], arr1[1], arr2[0]);
    int o2 = orient(arr1[0], arr1[1], arr2[1]);
    int o3 = orient(arr2[0], arr2[1], arr1[0]);
    int o4 = orient(arr2[0], arr2[1], arr1[1]);

    if ((o1 != o2) && (o3 != o4)) return true;

    if (o1 == 0 && segment(arr1[0], arr2[0], arr1[1])) return true;
    if (o2 == 0 && segment(arr1[0], arr2[1], arr1[1])) return true;
    if (o3 == 0 && segment(arr2[0], arr1[0], arr2[1])) return true;
    if (o4 == 0 && segment(arr2[0], arr1[1], arr2[1])) return true;

    return false;
}

int main()
{
    double v1[2][2];
    double v2[2][2];
    cout << "Enter coordinates\nX Y\n";
    for (int i = 0; i < 2; i++){
        cin >> v1[i][0] >> v1[i][1];
    }
    for (int i = 0; i < 2; i++){
        cin >> v2[i][0] >> v2[i][1];
    }
    if (intersect(v1, v2)){
        cout << "The segments intersect";
    }
    else{
            cout << "The segments don't intersect";
    }
    return 0;
}
#include <iostream>
#include <math.h>
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

bool intersect(double arr1[2], double arr2[2], double arr3[2][2])
{
    int o1 = orient(arr1, arr2, arr3[0]);
    int o2 = orient(arr1, arr2, arr3[1]);
    int o3 = orient(arr3[0], arr3[1], arr1);
    int o4 = orient(arr3[0], arr3[1], arr2);

    if ((o1 != o2) && (o3 != o4)) return true;

    if (o1 == 0 && segment(arr1, arr3[0], arr2)) return true;
    if (o2 == 0 && segment(arr1, arr3[1], arr2)) return true;
    if (o3 == 0 && segment(arr3[0], arr1, arr3[1])) return true;
    if (o4 == 0 && segment(arr3[0], arr2, arr3[1])) return true;

    return false;
}

int main()
{
    int n = 0, m = 0, c = 0;
    double x = 0, y = 0;
    cout << "n = ";
    cin >> n;
    cout << "Enter coordinates\n";
    double arr1[n][2];
    for (int i = 0; i < n; i++){
        cin >> arr1[i][0] >> arr1[i][1];
    }
    cout << "m = ";
    cin >> m;
    cout << "Enter coordinates\n";
    double arr2[m][2];
    for (int i = 0; i < m; i++){
        cin >> arr2[i][0] >> arr2[i][1];
    }
    
    for(int j = 0; j < n-1; j++){
        double arr_p[2][2] = {{arr1[j][0], arr1[j][1]}, {arr1[j+1][0], arr1[j+1][1]}};
        for (int i = 0; i < m-1; i++){
        if (intersect(arr2[i], arr2[i+1], arr_p)) c++;
        }
        if (intersect(arr2[0], arr2[m-1], arr_p)) c++;
    }
    double arr_p[2][2] = {{arr1[0][0], arr1[0][1]}, {arr1[n-1][0], arr1[n-1][1]}};
        for (int i = 0; i < m-1; i++){
        if (intersect(arr2[i], arr2[i+1], arr_p)) c++;
        }
        if (intersect(arr2[0], arr2[m-1], arr_p)) c++;
    if (c == 0){
        cout << "Don't intersect";
    }
    else{
        cout << "Intersect";
    }
    return 0;
}
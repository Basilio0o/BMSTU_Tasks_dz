#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double x1, y1, x2, y2;
    cout << "Enter coordinates\n";
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cout << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return 0;
}
#include <iostream>
#include <iomanip>

int main()
{
    double temp;
    std::cout << "Temperature in degrees Celsius is ";
    std::cin >> temp;
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << "Temperature in degrees Fahrenheit is " << temp * 9 / 5 + 32;
    return 0;
}
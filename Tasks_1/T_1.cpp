#include <iostream>

int main()
{
    int sm;
    std::cout << "Enter length ";
    std::cin >> sm;
    std::cout << sm / 100 << " meters " << sm % 100 << " centimeters";
    return 0;
}
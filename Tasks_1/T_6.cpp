#include <iostream>

int main()
{
    int age;
    std::cout << "Enter your age ";
    std::cin >> age;
    if(age < 18)
        std::cout << "You are under 18 years old";
    else if(18 <= age <= 60)
        std::cout << "You are between 18 and 60 years old";
    else
        std::cout << "You are over 60 years old";
    return 0;
}
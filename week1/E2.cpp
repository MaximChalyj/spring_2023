#include <iostream>
using namespace std;

int deg(int base, int power)
{
    int s = 1;
    for (int i = 0; i < power; i += 1)
    {
    s *= base;
    }
    return s;
}

int main()
{
    int base;
    int power;
    std::cin >> base;
    std::cin >> power;
    std::cout << deg(base, power) << std::endl;
}
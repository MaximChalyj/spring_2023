#include <iostream>
using namespace std;
int recursive_power(int, int);

int main()
{
    int base;
    int power;
    std::cin >> base;
    std::cin >> power;
    int result = recursive_power(base, power);
    std::cout << result;
}

int recursive_power(int base, int power)
{
    if (power > 0)
        return base*recursive_power(base, power - 1);
    return 1;
}
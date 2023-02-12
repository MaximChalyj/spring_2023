#include <iostream>
using namespace std;

int main()
{
    int N;
    int x;
    int y;
    int z;
    int local_min = 0;
    int local_max = 0;
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> x;
        if (i > 2)
        { 
            if (y < x && y < z)
                local_min += 1;
            if (y > x && y > z)
                local_max += 1;
        }

        if (i > 1)
            z = y;
        y = x; 
    }

    if (local_min > local_max)
        std::cout << "MIN";
    if (local_min < local_max)
        std::cout << "MAX";
    if (local_min == local_max)
        std::cout << "EQUAL";
}
#include <iostream>
using namespace std;

int main()
{
    int N;
    int x;
    int y;
    int A = 0;
    int B = 0;
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> x;
        if (i > 1)
        { 
            if (x > y)
                A += 1;
            if (x < y)
                B += 1;
        }
        y = x;
    }

    if (A > B)
        std::cout << "MAX";
    if (A < B)
        std::cout << "MIN";
}
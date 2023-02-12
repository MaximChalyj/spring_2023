#include <iostream>
using namespace std;

int five(int N)
{
    int i = 5;
    int s_5 = 0;
    while (N / i > 0)
    {
        s_5 += N / i;
        i *= 5;
    }
    return s_5;
}

int main()
{
    int N;
    std::cin >> N;
    if (N < 5)
    std::cout << 0;
    else
    std::cout << five(N) << endl;
}
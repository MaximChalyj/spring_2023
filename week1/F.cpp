#include <iostream>
using namespace std;
int fibonacci(int);
 
int main()
{
    int i;
    std::cin >> i;
    int result = fibonacci(i);
    std::cout << result << std::endl;
}

int fibonacci(int i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}
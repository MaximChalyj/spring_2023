#include <iostream>
#include <string>
using namespace std;

string foo(int N)
{
    string message = "0";
    if (N % 4 == 0)
    {
    message = "YES";
    return message;
    }
    else
    {
    message = "NO";
    return message;
    }
}

int main()
{
    int N;
    std::cin >> N;
    std::cout << foo(N) << std::endl;
}
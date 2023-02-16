#include <iostream>
#include <string>
using namespace std;

string foo(int N)
{
    string message = "0";
    if (N % 4 == 0)
    {
        if (N % 100 == 0)
        {
            if (N % 400 ==0)
                message = "YES";
            else
                message = "NO";
        }
        else
            message = "YES";
    }
    else
    message = "NO";
    return message;
}

int main()
{
    int N;
    std::cin >> N;
    std::cout << foo(N) << std::endl;
}
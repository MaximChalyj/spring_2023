#include <iostream>
#include <string>
using namespace std;

string palindrom(int N) 
{   
    string message = "0";
    int a = N;
    int b = 0;

    while (a != 0) 
    {
        b = b * 10 + a % 10;
        a /= 10;
    }
    
    if (N == b)
        message = "YES";
    else 
        message = "NO";
        return message;     
}
 
int main()
{ 
    int N;
    std::cin >> N;
    std::cout << palindrom(N) << std::endl;
}
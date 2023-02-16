#include <iostream>
#include <cmath>
using namespace std;

int is_prime(int N)
{
	for(int i = 2; i<=sqrt(N); i++)
		if(N % i == 0)
			return false;
	return true;
}

int main()
{
    int N;
    std::cin >> N;
    std::cout << is_prime(N) << std::endl;
}
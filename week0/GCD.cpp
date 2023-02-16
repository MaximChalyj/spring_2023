#include <iostream>
using namespace std;

int greatest_common_divisor(int a, int b) 
{
  if (a % b == 0)
    return b;
  if (b % a == 0)
    return a;
  if (a > b)
    return greatest_common_divisor(a%b, b);
  return greatest_common_divisor(a, b%a);
}

int main()
{
  int a;
  std::cin >> a;
  int b;
  std::cin >> b;
  std::cout << greatest_common_divisor(a, b) << std::endl;
}
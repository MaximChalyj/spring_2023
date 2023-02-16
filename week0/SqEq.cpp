#include <iostream> 
#include <cmath> 
 
using namespace std;
 
int main()
{  
  double a, b, c, d, x1, x2; 
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;

  d = b * b - 4 * a * c;
  if (d > 0) 
  {
    x1 = ((-b) + sqrt(d)) / (2 * a);
    x2 = ((-b) - sqrt(d)) / (2 * a);
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
  }
  if (d == 0) 
  {
    x1 = -(b / (2 * a));
    std::cout << "x1 = x2 = " << x1 << std::endl;
  }
  if (d < 0) 
    std::cout << "Действительных решений не существует" << std::endl;
}
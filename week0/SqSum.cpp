#include <iostream>
#include <iostream>

int main()
{
    int C;
    int flag = 0;
    std::cin >> C;
    for (int i = 1; i <= C - 1; i++)
    {
        for (int j = 1; j <= C - 1; j++)
        {
            if (i * i + j * j == C*C)
                flag += 1;
        }
    }
    if (flag > 0)
        std::cout << "Числа, удовлетворяющие уравнению A * A + B * B = " << C << ", существуют" << std::endl;
    else
        std::cout << "Чисел, удовлетворяющих уравнению A * A + B * B = " << C << ", не существует" << std::endl;
}
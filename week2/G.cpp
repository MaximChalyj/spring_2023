#include <iostream>

#ifndef N
#define N 9 // actual size of the array
#endif

void readArray(int (&a)[N])
{
    for (int i=0; i<N; i++)
    {
        std::cin>>a[i];
    }
}

void printArray(int (&a)[N])
{
    for (int i=0; i<N; i++)
    {
        std::cout<<a[i];
    }
}

int findUnique(int (&a)[N])
{
    int XOR = 0;
    for (int i=0; i<N; i++)
    {
        XOR ^= a[i];
    }
    return XOR;
}

int main()
{
    int a[N];
    readArray(a);
    std::cout<<findUnique(a)<<std::endl;
}

#include <iostream>

#ifndef N
#define N 10 // actual size of the array
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
        std::cout<<a[i]<<" ";
    }
}

void shiftRight(int (&a)[N], int k)
{
    int b[N];
    for (int i=0; i<N; i++)
    {
        b[(i+k)%N] = a[i];
    } 
    for (int i=0; i<N; i++)
    {
        a[i] = b[i];
    }       
}

int main()
{
    int k;
    std::cin>>k;
    int a[N];
    readArray(a);
    shiftRight(a, k);
    printArray(a);
}
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

void moveNegativeToEnd(int (&a)[N])
{
    int positive = -1;
    int negative = -1;
    int b[N];
    for (int i=0; i<N; i++)
    {
        if (a[i]>0)
        {
            positive += 1;
            b[positive] = a[i];
        }
    }
    for (int i=0; i<N; i++)
    {
        if (a[i]<0)
        {
            negative += 1;
            b[positive+negative+1] = a[i];
        }
    }
    for (int i=0; i<N; i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int a[N];
    readArray(a);
    moveNegativeToEnd(a);
    printArray(a);
}
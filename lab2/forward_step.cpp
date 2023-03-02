#include <iostream>

#ifndef N
#define N 10 // actual size of the array
#endif

void readArray(int a[N])
{
    for (int i=0; i<N; i++)
    {
        std::cin>>a[i];
    }
}

void printArray(int a[N])
{
    for (int i=0; i<N; i++)
    {
        std::cout<<a[i]<<" ";
    }
}

void forward_step(int a[N], int begin_idx, int end_idx)
{
    for (int i=1; i<N; i++)
    {
        for (int j=1; j<N; j++)
        {
            if (a[j]<a[j-1])
            {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

int main()
{
    int a[N];
    readArray(a);
    forward_step(a, 0, N-1);
    printArray(a);
}
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

void backward_step(int a[N], int begin_idx, int end_idx)
{
    for (int i=N-2; i>=0; i--)
    {
        for (int j=N-2; j>=0; j--)
        {
            if (a[j+1] < a[j])
            {
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main()
{
    int a[N];
    readArray(a);
    backward_step(a, 0, N-1);
    printArray(a);
}
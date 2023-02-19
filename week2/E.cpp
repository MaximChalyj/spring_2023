#include <iostream>

#ifndef N
#define N 10 // actual size of the array
#endif

void readArray(int (&a)[N], int (&b)[N])
{
    for (int i=0; i<N; i++)
    {
        std::cin>>a[i];
    }
    for (int i=0; i<N; i++)
    {
        std::cin>>b[i];
    }
}

void printArray(int (&c)[2*N])
{
    for (int i=0; i<2*N; i++)
    {
        std::cout<<c[i]<<" ";
    }
}

void mergeArrays(int (&a)[N], int (&b)[N], int (&c)[2*N])
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    for (int k=0; k<2*N; k++)
    {
        if (i>N-1)
        {
            x = b[j];
            c[k] = x;
            j++;
        }
        else if (j>N-1)
        {
            x = a[i];
            c[k] = x;
            i++;
        }  
        else if (a[i]<b[j])
        {
            x = a[i];
            c[k] = x;
            i++;
        }
        else
        {
            y = b[j];
            c[k] = y;
            j++;
        }
    }
}

int main()
{
    int a[N];
    int b[N];
    int c[2*N];
    readArray(a, b);
    mergeArrays(a, b, c);
    printArray(c);
}
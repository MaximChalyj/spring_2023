#include <iostream>

#ifndef N
#define N 10 // actual size of the array
#endif

void printArray(int (&a)[N])
{
    for (int i=0; i<N; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void pancake_sort(int (&a)[N])
{
    for (int j=N-1; j>0; j--)
    {
        int max = -1000;
        int index;
        for (int i=0; i<=j; i++)
        {
            if (a[i]>max)
            {
                max = a[i];
                index = i;
            }
        }
        if (index!=j)
        {
            int b[index+1];
            for (int i=0; i<=index; i++)
            {
                b[i] = a[index-i];
            }

            for (int i=0; i<=index; i++)
            {
                a[i] = b[i];
            }

            int c[j+1];
            for (int i=0; i<=j; i++)
            {
                c[i] = a[j-i];
            } 

            for (int i=0; i<=j; i++)
            {
                a[i] = c[i];
            }
            
        }
    }
}

int main()
{
int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
pancake_sort(a);
printArray(a);
}
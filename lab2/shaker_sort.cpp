#include <iostream>
using namespace std;

#ifndef N
#define N 5
#endif
 
void readArray (int a[N])
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

void forward_step(int &begin_idx, int &end_idx, int &last, int a[N]) 
{
    for (int i=begin_idx; i<end_idx; i++) 
    {
        if (a[i]>a[i+1])
        { 
            int tmp = a[i+1];
            a[i+1] = a[i];
            a[i] = tmp;
            last = i;
        } 
    }
    end_idx = last;
}

void backward_step(int &begin_idx, int &end_idx, int &last, int a[N]) 
{
    for (int i = end_idx; i > begin_idx; i--) 
    {
        if (a[i-1]>a[i]) 
        {
            int tmp = a[i-1];
            a[i-1] = a[i];
            a[i] = tmp;
            last = i;  
        }
    }
    begin_idx = last;
}

void shaker_sort(int a[N]) 
{
    int begin_idx = 0;
    int end_idx = N - 1;
    int last = N - 1;
    while (begin_idx<end_idx)
    {
        forward_step(begin_idx, end_idx, last, a);
        backward_step(begin_idx, end_idx, last, a);
    }
}

int main() 
{
    int a[N];
    readArray(a);
    shaker_sort(a);
    printArray(a);
}





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

 int findLastZero(int (&a)[N])
 {
    int x = 0;
    int y = N-1;
    int sum = 0;
    bool flag = false;
    int index = 0;
    while ((x<=y) and (flag!=true))
    {
        int z = (x + y)/2;
        for (int i=x; i<=z; i++)
        {
            sum += a[i];
        }
        if (sum>0)
        {
            y = z;
            if (a[z-1]==0)
            {
                flag = true;
                index = z-1;
            }
        }
        else 
        {
            x = z;
            if (a[z+1]==1)
            {
                flag = true;
                index = z;
            }
        }
    }
    return index;
} 

int main()
{
    int a[N];
    readArray(a);
    std::cout<< findLastZero(a) <<std::endl;
}
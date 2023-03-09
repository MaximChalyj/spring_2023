#include <iostream>
#include <random>
#include <chrono>

int fibonacci(int);

int fibonacci(int i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

int back_fibonacci(int F)
{
    int i = 0;
    while (fibonacci(i)!=F)
    {
        i += 1;
    }
    return i;
}

void readArray(int a[], int N)
{
    for (int i=0; i<N; i++)
    {
        std::cin>>a[i];
    }
}

void printArray(int a[], int N)
{
    for (int i=0; i<N; i++)
    {
        std::cout<<a[i]<<" ";
    }
}

void Shell_sort(int a[], int N)
{
    int permutation = 0;
    int i = 0;
    while (fibonacci(i)<=N)
    {
        i += 1;
    }
    
    int begin = fibonacci(i-1);
    for (int step=begin; step>0; step=fibonacci(back_fibonacci(step)-1))
    {
        for (int i=step; i<N; i++)
        {
            for (int j=i-step; j>=0 && a[j]>a[j+step]; j-=step)
            {
                int tmp = a[j+step];
                a[j+step] = a[j];
                a[j] = tmp;
                permutation += 1;
            }
        }
    }
    //std::cout << N << " ";
    //std::cout << permutation << std::endl;
}

int main() 
{
    for (int N=1000; N<500000; N*=1.2)
    {
        int a[N];

        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        unsigned seed = 1001;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned>dstr(0 , 9);

        for (int i=0; i<N; i++)
        {
            a[i] = arr[dstr(rng)];
            //std::cout << a[i] << " ";
        }

        int S = 0;
        for (int i=0; i<100; i++)
        {
        auto begin = std::chrono::steady_clock::now();

        Shell_sort(a, N);

        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        S+=time_span.count();
        }

        std::cout << N << " ";
        std::cout << S/100 << std::endl; 
    }
}
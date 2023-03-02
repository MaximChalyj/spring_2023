#include <iostream>
#include <random>
#include <chrono>

#ifndef factor
#define factor 1.247
#endif

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

void comb_sort(int a[], int N)
{
    int permutation = 0;
    int step = N;
    bool isSwaps = true;
    while ((step>1) || (isSwaps==true))
    {
        step = (int) (step / factor);
        isSwaps = false;
        for (int i=0; i<N-step; i++)
        {
            if (a[i]>a[i+step])
            {
                int tmp = a[i+step];
                a[i+step] = a[i];
                a[i] = tmp;
                isSwaps = true;
                permutation += 1;
            }
        }
    }
    //std::cout << N << " ";
    //std::cout << permutation << std::endl;
}

int main() 
{
    for (int N=1000; N<500000; N+=1000)
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

        auto begin = std::chrono::steady_clock::now();

        comb_sort(a, N);

        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        std::cout << N << " ";
        std::cout << time_span.count() << std::endl; 
    }
}
#include <iostream>
#include <random>
#include <chrono>

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
    for (int step=(int)(log2(N+1)); step>0; step=(step-1)/2)
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
    for (int N=1000; N<100000; N+=1000)
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

        Shell_sort(a, N);

        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " ";
        std::cout << time_span.count() << std::endl; 
    }
}
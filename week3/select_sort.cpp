#include <iostream>
#include <random>
#include <chrono>

void printArray(int a[], int N)
{
    for (int i=0; i<N; i++)
    {
        std::cout << a[i] << std::endl;
    }
}


void select_sort(int a[], int N)
{
    int key;
    int tmp;
    for (int i=0; i<N-2; i++)
    {
        tmp = a[i];
        key = i;
        for (int j=i+1; j<N; j++)
        {
            if (a[j]<a[key]) 
            {
                key = j;
            }
        }
        if (key!=i)
            {
                a[i] = a[key];
                a[key] = tmp;
            }
    }
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

        select_sort(a, N);

        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " ";
        std::cout << time_span.count() << std::endl; 
    }
}
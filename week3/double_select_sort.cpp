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

void double_select_sort(int a[], int N) 
{
    
    for (int i=0; i<N/2; i++)
    {
        int key_min = i;
        int key_max = N-i-1;
        int tmp_min = a[i];
        int tmp_max = a[N-i-1];
        for (int j=i; j<N-i; j++)
        {
            if (a[j]<a[key_min]) 
            {
                key_min = j;
            }
        }
        if (key_min!=i)
            {
                a[i] = a[key_min];
                a[key_min] = tmp_min;
            }
        for (int j=i; j<N-i; j++)
        {
            if (a[j]>a[key_max]) 
            {
                key_max = j;
            }
        }
        if (key_max!=N-i-1)
            {
                a[N-i-1] = a[key_max];
                a[key_max] = tmp_max;
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

        double_select_sort(a, N);

        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " ";
        std::cout << time_span.count() << std::endl; 
    }
}
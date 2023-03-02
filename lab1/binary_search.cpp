#include <iostream>
#include <random>
#include <chrono>

int comparison_function(const void*a, const void*b)
{
    return (*(int*)a - *(int*)b);
}

int binary_search(int a[], int N, int key)
{
    int x = 0;
    int y = N-1;
    bool flag = false;
    int z;

    while ((x <= y) && (flag != true)) 
    {
        z = (x + y) / 2; 
        if (a[z] == key) flag = true; 
        if (a[z] > key) y = z - 1; 
        else x = z + 1;
    }
    if (flag)
    {
        return z;
    }
    return -1;
}

int main()
{
    int key = -1;
    for (int N=1000; N<500000; N+=1000)
    {
        int a[N];
    
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        unsigned seed = 1001;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 9);

        for (int i=0; i<N; i++)
        {
            a[i] = arr[dstr(rng)];
        }

        qsort(a, N, sizeof(int), comparison_function);

        for (int i=0; i<N; i++)
        {
            //std::cout << a[i] << " ";
        }
    
    
        auto begin = std::chrono::steady_clock::now();
        for(unsigned cnt = 100000; cnt != 0 ; --cnt)

        binary_search(a, N, key);

        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        std::cout << N << " "; 
        std::cout << time_span.count() << std::endl; 
    }
}
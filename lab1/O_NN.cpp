#include <iostream>
#include <random>
#include <chrono>

int O_NN(int a[], int N, int key)
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if ((a[i]+a[j] == key) && (i != j))
            {
                return 1;
            }
        }
    }
    return -1;
}

int main()
{
    int key = -1;
    for (int N=1000; N<100000; N+=1000)
    {
        int a[N];

        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        unsigned seed = 1001;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 9);

        for (int i=0; i<N; i++)
        {
            a[i] = arr[dstr(rng)];
            //std::cout << a[i] << " ";
        }

        auto begin = std::chrono::steady_clock::now();

        O_NN(a, N, key);

        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " "; 
        std::cout << time_span.count() << std::endl;
    }
}
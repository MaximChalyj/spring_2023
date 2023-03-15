#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#ifndef N
#define N 1000000
#endif

void lin_search(long long* arr, long long n, long long num) 
{
    for (long long i = 0; i < num; i++) 
    {
        if (*(arr + i) == n) 
        {
            i = num + 1;
        }
    }
}

int main() 
{
    long long num = 100;
    unsigned int seed = 1001;
    std::default_random_engine rng(seed);
    long long* arr = new long long[N];
    for (long long i = 0; i < N; i++) 
    {
        *(arr + i) = i;
    }
    for (num; num <= N; num *= 2) 
    {
        std::uniform_int_distribution<unsigned> dstr(0, num - 1);
        auto begin = std::chrono::steady_clock::now();
        for (unsigned long long cnt = 100000; cnt != 0; --cnt) 
        {
            lin_search(arr, *(arr + dstr(rng)), num);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "\n\n";
        std::cout << time_span.count() << ' ' << num << std::endl;
    }
    delete[] arr;
    return 0;
}
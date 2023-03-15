using namespace std;  
#include <iostream>  
#include <fstream>  
#include <chrono>  
#include <random>  
  
#ifndef N  
#define N 1000000  
#endif  
  
void bin_search(long long *a, long long val, long long num)   
{  
    long long l = 0;  
    long long r = num;  
    while (r > l)   
    {  
        long long m = (l + r) / 2;    
        if (*(a + m) < val)   
        {  
            l = m + 1;  
        }   
        else if (*(a + m) > val)   
        {  
            r = m - 1;  
        }   
        else  
        {  
            break;  
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
            bin_search(arr, *(arr + dstr(rng)), num);  
        }  
        auto end = std::chrono::steady_clock::now();  
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);  
        std::cout << "\n\n";  
        std::cout << time_span.count() << ' ' << num << std::endl;    
    }  
    delete[] arr;  
    return 0;  
}
#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
using namespace std;
#ifndef N
#define N 500// actual size of the array
#endif
std::mt19937 gen(static_cast<unsigned>(time(nullptr))); // seed the generator
int dice(int min, int max){
        uniform_int_distribution<> distr(min, max); // define the range
        return distr(gen);
    }
void move(int (&mas)[N][N], int real_size){
    for(int i = 0; i < real_size; ++i){
        for(int j = 0; j < real_size; ++j){
            mas[i][j] = 0; 
        }
    }
    mas[real_size/2][real_size/2] = 1;
    int y, x;
    y = real_size/2;
    x = real_size/2;
    while ((y != 0) && (x != 0) && (x != real_size-1) && (y != real_size-1)){
    int a = dice(0, 3);
    if (a == 0){
        mas[y][x] = 0;
        mas [y+1][x] = 1;
        y += 1;
    }
    if (a == 1){
        mas[y][x] = 0;
        mas [y][x+1] = 1;
        x += 1;
    }
    if (a == 2){
        mas[y][x] = 0;
        mas [y-1][x] = 1;
        y -= 1;
    }
    if (a == 3){
        mas[y][x] = 0;
        mas [y][x-1] = 1;
        x -= 1;
    }
    }
    return;
}
int time_count( int (&mas)[N][N], int real_size){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000; cnt != 0 ; --cnt)
        move(mas, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    int mas[N][N];
    int real_size = N;
    for (int real_size = 10; real_size  < N; real_size = real_size + 10){
        time_count(mas, real_size);
    }
}
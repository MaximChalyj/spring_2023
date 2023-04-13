#include <iostream>
#include <chrono>
#include <random>
#include <thread>

#ifndef N
#define N 300
#endif

using namespace std;

std::default_random_engine rng(100);

struct point 
{
    int is_dislocation;
    int movement;
    int x;
    int y;
};

int RandInt(int min, int max)
{
    std::uniform_int_distribution<int> dstr(min, max);
    return dstr(rng);
}

void Make_Crystal(point (&points)[N][N], int real_size)
{
    points[real_size/2][real_size/2].is_dislocation = 1;
    points[real_size/2][real_size/2].movement = RandInt(1, 4);
    for (int i = 0; i < real_size; i++)
    {
        for (int j = 0; j < real_size; j++)
        {
            if (i != real_size/2 && j != real_size/2)
            {
                points[i][j].is_dislocation = 0;
                points[i][j].movement = 0;
            }
            points[i][j].x = i;
            points[i][j].y = j;
        }
    }
}

void Move_Dislocations(point (&points)[N][N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        for (int j = 0; j < real_size; j++)
        {
            if (points[i][j].movement == 1)
            {
                points[i][j].is_dislocation = 0;
                points[i][j+1].is_dislocation = 1;

            }
            else if (points[i][j].movement == 2)
            {
                points[i][j].is_dislocation = 0;
                points[i-1][j].is_dislocation = 1;
            }
            else if (points[i][j].movement == 3)
            {
                points[i][j].is_dislocation = 0;
                points[i][j-1].is_dislocation = 1;
            }
            else if (points[i][j].movement == 4)
            {
                points[i][j].is_dislocation = 0;
                points[i+1][j].is_dislocation = 1;
            }
        }
    }
}

void Make_Random_Movement(point (&points)[N][N], int real_size)
{
    for (int i = 0; i < real_size; i++)
        {
        for (int j = 0; j < real_size; j++)
        {
            if (points[i][j].is_dislocation == 1)
            {
                points[i][j].movement = RandInt(1, 4);
            }
            else 
            {
                points[i][j].movement = 0;
            }
        }
    }
}

void Make_Movement(point (&points)[N][N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        for (int j = 0; j < real_size; j++)
        {
            if 
            (
            points[i][j].x == 0 ||
            points[i][j].y == 0 ||
            points[i][j].x == real_size-1 ||
            points[i][j].y == real_size-1 
            )
            {
                points[i][j].movement = 0;
            }
        }
    }
}

bool Check_Crystal(point (&points)[N][N], int real_size)
{
    bool flag;
    int counter = 0;

    Make_Movement(points, real_size);
    for (int i = 0; i < real_size; i++)
    {
        for (int j = 0; j < real_size; j++)
        {
            if (points[i][j].movement != 0)
            {
                counter ++;
            }
        }
    }
    if (counter == 0)
    {
        flag = false;
    }
    else 
    {
        flag = true;
    }
    return flag;
}

void Print_Crystal(point (&points)[N][N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        for (int j = 0; j < real_size; j++)
        {
            if (points[i][j].is_dislocation == 1)
            cout << "+";
            else
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    point points[N][N];
    for (int real_size = 10; real_size <= N; real_size += 5)
    {
        int S = 0;
        for (int i= 0; i < 100; i++)
        {
            auto begin = std::chrono::steady_clock::now();
            Make_Crystal(points, real_size);
            //Print_Crystal(points, real_size);
            while (Check_Crystal(points, real_size))
            {
                Make_Movement(points, real_size);
                Move_Dislocations(points, real_size);
                Make_Random_Movement(points, real_size);
                //Print_Crystal(points, real_size);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            S += time_span.count();
        }
        cout << real_size << " ";
        cout << S/100 << endl;
    }
    return 0;   
}
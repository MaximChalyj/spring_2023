#include <iostream>
#include <chrono>
#include <random>
#include <thread>

#ifndef N
#define N 300
#endif

using namespace std;

std::default_random_engine rng(10);

struct point 
{
    int is_dislocation;
    int movement;
    int x;
};

int RandInt(int min, int max)
{
    std::uniform_int_distribution<int> dstr(min, max);
    return dstr(rng);
}

void Make_Crystal(point (&points)[N], int real_size)
{
    points[real_size/2].is_dislocation = 1;
    points[real_size/2].movement = RandInt(1, 2);
    for (int i = 0; i < real_size; i++)
    {
        if (i != real_size/2)
        {
            points[i].is_dislocation = 0;
            points[i].movement = 0;
        }
        points[i].x = i;
    } 
}

void Test(point (&points)[N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        points[i].is_dislocation = 0;
        points[i].movement = 0;
        points[i].x = i;
    }
    points[3].is_dislocation = 1;
    points[3].movement = 1;
    points[2].is_dislocation = 1;
    points[2].movement = 1;

}

void Move_Dislocations(point (&points)[N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        if (points[i].movement == 1)
        {
            points[i].is_dislocation = 0;
            points[i+1].is_dislocation = 1;
        }
        else if (points[i].movement == 2)
        {
            points[i].is_dislocation = 0;
            points[i-1].is_dislocation = 1;
        }
    }
}

void Make_Random_Movement(point (&points)[N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        if (points[i].is_dislocation == 1)
        {
            points[i].movement = RandInt(1, 2);
        }
        else 
        {
            points[i].movement = 0;
        }
    }   
}

void Make_Movement(point (&points)[N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        for (int j = 0; j < real_size; j++)
        {
            if 
            (
            points[i].x == 0 ||
            points[i].x == real_size-1 
            )
            {
                points[i].movement = 0;
            }
        }
    }
}

bool Check_Crystal(point (&points)[N], int real_size)
{
    bool flag;
    int counter = 0;

    Make_Movement(points, real_size);
    for (int i = 0; i < real_size; i++)
    {
        if (points[i].movement != 0)
        {
            counter ++;
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

void Print_Crystal(point (&points)[N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        if (points[i].is_dislocation == 1)
        cout << "+";
        else
        cout << "*";
    }
    cout << endl;
}

void Print_Movement(point (&points)[N], int real_size)
{
    for (int i = 0; i < real_size; i++)
    {
        cout << points[i].movement;
    }
    cout << endl;
}

int main()
{
    point points[N];
    for (int real_size = 10; real_size <= N; real_size += 5)
    {
        int S = 0;
        for (int i = 0; i < 100; i++)
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
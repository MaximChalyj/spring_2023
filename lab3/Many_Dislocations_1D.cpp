#include <iostream>
#include <chrono>
#include <random>
#include <thread>

#ifndef N
#define N 500
#endif

using namespace std;

std::default_random_engine rng(100);

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

void Make_Crystal(point (&points)[N], int limitation)
{
    int mas[limitation];
    int k = 0;
    while (k < limitation)
    {
        bool flag = true;
        int a = RandInt(1, N-2);
        for (int i = 0; i < limitation; i++)
        {
            if (a == mas[i])
            {
                flag = false;
            }   
        }
        if (flag == true)
        {
            mas[k] = a;
            points[a].is_dislocation = 1;
            k++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (points[i].is_dislocation == 1)
        {
            points[i].movement = RandInt(1, 2);
        }
        else 
        {
            points[i].movement = 0;
        }
        points[i].x = i;
    }
}

void Test(point (&points)[N])
{
    for (int i = 0; i < N; i++)
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

void Move_Dislocations(point (&points)[N])
{
    for (int i = 0; i < N; i++)
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

void Make_Random_Movement(point (&points)[N])
{
    for (int i = 0; i < N; i++)
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

void Make_Movement(point (&points)[N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if 
            (
            points[i].x == 0 ||
            points[i].x == N-1 ||
            points[i-1].is_dislocation == 1 || 
            points[i+1].is_dislocation == 1 || 
            (points[i-2].is_dislocation == 1 && points[i-2].movement == 1 && points[i].movement == 2)
            )
            {
                points[i].movement = 0;
            }
        }
    }
}

bool Check_Crystal(point (&points)[N])
{
    bool flag;
    int counter = 0;

    Make_Movement(points);
    for (int i = 0; i < N; i++)
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

void Print_Crystal(point (&points)[N])
{
    for (int i = 0; i < N; i++)
    {
        if (points[i].is_dislocation == 1)
        cout << "+";
        else
        cout << "*";
    }
    cout << endl;
}

void Print_Movement(point (&points)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << points[i].movement;
    }
    cout << endl;
}

int main()
{
    point points[N];
    for (float limitation = 1; limitation < 1000; limitation += 5)
    {
        auto begin = std::chrono::steady_clock::now();
        Make_Crystal(points, limitation);
        //Print_Crystal(points);
        while (Check_Crystal(points))
        {
            Make_Movement(points);
            Move_Dislocations(points);
            Make_Random_Movement(points);
            //Print_Crystal(points);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        float area_ratio = limitation/N;
        cout << area_ratio << " ";
        cout << time_span.count() << endl;
    }
    return 0;
}
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

void Make_Crystal(point (&points)[N][N], int limitation)
{
    int mas[limitation][2];
    int k = 1;
    while (k < limitation)
    {
        bool flag = true;
        int a = RandInt(1, N-2);
        int b = RandInt(1, N-2);
        for (int i = 0; i < limitation; i++)
        {
            if (a == mas[i][0] && b == mas[i][1])
            {
                flag = false;
            }   
        }
        if (flag == true)
        {
            mas[k][0] = a;
            mas[k][1] = b;
            points[a][b].is_dislocation = 1;
            k++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (points[i][j].is_dislocation == 1)
            {
                points[i][j].movement = RandInt(1, 4);
            }
            else 
            {
                points[i][j].movement = 0;
            }
            points[i][j].x = i;
            points[i][j].y = j;
        }
    }
}

void Test(point (&points)[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            {
                points[i][j].is_dislocation = 0;
                points[i][j].movement = 0;
            }
            points[i][j].x = i;
            points[i][j].y = j;
        }
    }
    points[3][3].is_dislocation = 1;
    points[3][3].movement = 3;
    points[2][2].is_dislocation = 1;
    points[2][2].movement = 4;

}

void Move_Dislocations(point (&points)[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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

void Make_Random_Movement(point (&points)[N][N])
{
    for (int i = 0; i < N; i++)
        {
        for (int j = 0; j < N; j++)
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

void Make_Movement(point (&points)[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if 
            (
            points[i][j].x == 0 ||
            points[i][j].y == 0 ||
            points[i][j].x == N-1 ||
            points[i][j].y == N-1 ||
            points[i-1][j].is_dislocation == 1 || 
            points[i+1][j].is_dislocation == 1 || 
            points[i][j-1].is_dislocation == 1 || 
            points[i][j+1].is_dislocation == 1 ||
            (points[i][j-2].is_dislocation == 1 && points[i][j-2].movement == 1 && points[i][j].movement == 3) ||
            (points[i-2][j].is_dislocation == 1 && points[i-2][j].movement == 4 && points[i][j].movement == 2) ||
            (points[i-1][j-1].is_dislocation == 1 && points[i-1][j-1].movement == 1 && points[i][j].movement == 2) ||
            (points[i-1][j-1].is_dislocation == 1 && points[i-1][j-1].movement == 4 && points[i][j].movement == 3) ||
            (points[i+1][j-1].is_dislocation == 1 && points[i+1][j-1].movement == 2 && points[i][j].movement == 3) ||
            (points[i+1][j-1].is_dislocation == 1 && points[i+1][j-1].movement == 1 && points[i][j].movement == 4) 
            )
            {
                points[i][j].movement = 0;
            }
        }
    }
}

bool Check_Crystal(point (&points)[N][N])
{
    bool flag;
    int counter = 0;

    Make_Movement(points);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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

void Print_Crystal(point (&points)[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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

void Print_Movement(point (&points)[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << points[i][j].movement;
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    point points[N][N];
    for (float limitation = 1; limitation < 300; limitation += 5)
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
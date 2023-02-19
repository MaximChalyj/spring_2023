#include <iostream>

#ifndef N
#define N 1 // actual size of the array
#endif

#ifndef M
#define M 3 // actual size of the array
#endif

void readArray(int (&A)[N][M])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            std::cin>>A[i][j];
        }
    }
}

void print_transposed(int (&A)[N][M], int (&B)[M][N])
{
    int K = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            B[j][i] = A[i][j];
        }
    }
}

int main()
{
    int A[N][M];
    int B[M][N];
    readArray(A);
    print_transposed(A, B);
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            std::cout<<B[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
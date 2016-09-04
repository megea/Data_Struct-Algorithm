
/**
如矩阵（蛇形矩阵）：
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
找出规律，并输入N，打印N*N的矩阵：

*/

#include <stdio.h>
#include <string.h>

void spiral_to(int N)
{
    int r = N/2;
    int i, j, m = 1;
    int Arr[N][N];
    int temp;

    memset(Arr, 0, sizeof(int)*N*N);    //需要初始化为0
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < N - i; j++)
        {
            if(Arr[i][j] == 0)
                Arr[i][j] = m++;
            temp = Arr[i][j];
        }
        for(j = i + 1; j < N - i; j++)
        {
            if(Arr[j][N-1-i] == 0)
                Arr[j][N-1-i] = m++;
                temp = Arr[j][N-1-i];
        }
        for(j = N-i-1; j >i; j--)
        {
            if(Arr[N-1-i][j] == 0)
                Arr[N-i-1][j] = m++;
                temp = Arr[N-i-1][j];
        }
        for(j = N-i-1; j > i; j--)
        {
            if(Arr[j][i] == 0)
                Arr[j][i] = m++;
                temp = Arr[j][i];
        }

    }
    if(N%2 == 1)
    {
        Arr[N/2][N/2] = m++;
    }
    for(i = 0; i< N; i++)
    {
        for(j = 0; j< N; j++)
            printf("%d", Arr[i][j]);
        printf("\n");
    }
}

int main()
{
    int num;
    printf("Input the number:");
    scanf("%d", &num);
    spiral_to(num);

    return 0;
}

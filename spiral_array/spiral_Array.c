/**
* 看清以下数字排列的规律, 设1点的坐标是(0,0), x方向向右为正,
* y方向向下为正. 例如, 7的坐标为(-1，-1), 2的坐标为(0,1),
* 3的坐标为(1,1). 编程实现输入任意点的坐标, 输出所对应的数字.
* 43 44 45 46 47 ..    ..
* 42 21 22 23 24 25 26
* 41 20 07 08 09 10 27
* 40 19 06 01 02 11 28
* 39 18 05 04 03 12 29
* 38 17 16 15 14 13 30
* 37 36 35 34 33 32 31
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
思路：最开始的1为第0圈，依次向外扩展，第t圈以内（不包含t圈），总共有(2t-1)^2个数。
      第t圈第一个元素是(2t-1)^2+1；所以：
        坐标     参数值
    右:(t, 0)   (2t-1)^2 + t
    下:(0, -t)  (2t-1)^2 + t +2t
    左:(-t, 0)  (2t-1)^2 + t + 2t + 2t
    上:(0, t)   (2t-1)^2 + t + 2t + 2t + 2t
注意：因为每一圈的最后一个元素属于上，不属于右，所以上在右之前检查；
*/

int func(int x, int y)
{
    int iRet;
    int t = abs(x) > abs(y) ? abs(x) :abs(y);
    int sum_t = (2*t - 1)*(2*t - 1);  //t圈内元素个数

    //上
    if(t == y)
    {
        iRet = sum_t + 7* t + x;
    }

    if(t == x)
    {
        iRet = sum_t + t + y;
    }

    if(t == -y)
    {
        iRet = sum_t + 3* t + x;
    }
    if(t == -x)
    {
        iRet = sum_t + 5* t + y;
    }

    return iRet;
}
int main(void)
{
    int x, y, ret;
    scanf("%d%d",&x, &y);
    ret = func(x, y);
    printf("%d", ret);

    return 0;
}


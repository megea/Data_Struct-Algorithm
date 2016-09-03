/**
* 归并排序(mergesort)：
* 原理：将两个已经排序好的序列合并。因为两个序列是已排序的，所以若将输出放到第三个表中时，
*       该算法可以通过对输入数据一趟排序来完成。归并排序是递归的一个很好的实例。
*
* 时间复杂度：O(log N)，
* 但是很难用于主存排序，主要在于它需要额外的内存，在整个算法中还花费将数据拷贝到临时数组再
* 拷贝回来这样附加的工作。
*
*/
// 3 1 44 32 22 15
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void myMerge(int *A, int *pTemp, int start, int mid, int end)
{
    int leftStart = start;
    int leftEnd = mid;
    int rightStart = mid + 1;
    int last = end;
    int index_temp = 0, i = 0;

    //注意是'<='和'>='
    while((leftStart <= leftEnd) && (rightStart <= last))
    {
        if(A[leftStart] <= A[rightStart])
        {
            pTemp[index_temp++] = A[leftStart++];
        }
        else
        {
            pTemp[index_temp++] = A[rightStart++];
        }
    }
    while(leftStart <= leftEnd)
    {
        pTemp[index_temp++] = A[leftStart++];
    }
    while(rightStart <= last)
    {
        pTemp[index_temp++] = A[rightStart++];
    }

    for(i = 0; i < index_temp; i++) //注意是'<'
    {
        A[i + start] = pTemp[i];
    }
}

void mergesort(int *A, int *pTemp, int start, int end)
{
    if(start < end)
    {
        int center = (start + end)/2;
        mergesort(A, pTemp, start, center);     //前半部分排序
        mergesort(A, pTemp, center + 1, end);   //后半部分排序
        myMerge(A, pTemp, start, center, end);  //合并
    }
}

void mergeSort(int array[], int N)
{
    int *pTemp = malloc(N * sizeof(int));
    if (NULL != pTemp)
    {
        mergesort(array, pTemp, 0, N-1);
        free(pTemp);
    }
    else
    {
        printf("No space for temp array!");
    }
}

int main(void)
{
    int i, j;
    int array[MAX] = {0};
//    int arr[] = {1,2,5,3};
    char c;
    int sum;

    printf("Input the array to be sorted:\n");
    for(i = 0; i < MAX; i++)
    {
        scanf("%d%c", &array[i], &c);
        if (c == '\n')
            break;
    }
    sum = i + 1;
    for(j = 0; j < sum; j++)
    {
        if('\0' == array[j])
            break;
        printf("%d,", array[j]);
    }
    printf("\n");

    mergeSort(array, sum);
    for(j = 0; j < sum; j++)
    {
        if('\0' == array[j])
            break;
        printf("%d ", array[j]);
    }

    return 0;
}




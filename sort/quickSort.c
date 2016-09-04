/**
* 快速排序(quicksort)：
* 原理：从队列中找到一个基准元素（安全方式是找到），然后将将小于它的值交换到队列的前部分，
*       大于它的值交欢到队列的后部分。
*
* 时间复杂度：O(Nlog N)，并且是稳定的。
*
*/
// 3 1 44 32 22 15

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int low, int high)
{
    int pivotKey = array[low];
    while(low < high)
    {
        while((low < high) && (array[high] >= pivotKey))
            high--;
        swap(&array[low], &array[high]);
        while((low < high) && (array[low] <= pivotKey))
            low++;
        swap(&array[low], &array[high]);

    }
    return low;
}

void quickSort(int *array, int low, int high)
{
    if(low < high)
    {
        int pivotKey = partition(array, low, high);
        quickSort(array, low, pivotKey - 1);
        quickSort(array, pivotKey + 1, high);
    }
}

int main(void)
{
    int arr[MAX];
    int i, iNum;
    char c;

    printf("Please input the array to be sorted:\n");
    for(i = 0; i < MAX; i++)
    {
        scanf("%d%c", &arr[i], &c);
        if(c == '\n')
        {
            i++;
            break;
        }
    }
    iNum = i;

    quickSort(arr, 0, iNum-1);
    for(i = 0; i < iNum; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

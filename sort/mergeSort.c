/**
* �鲢����(mergesort)��
* ԭ���������Ѿ�����õ����кϲ�����Ϊ����������������ģ�������������ŵ�����������ʱ��
*       ���㷨����ͨ������������һ����������ɡ��鲢�����ǵݹ��һ���ܺõ�ʵ����
*
* ʱ�临�Ӷȣ�O(log N)��
* ���Ǻ�����������������Ҫ��������Ҫ������ڴ棬�������㷨�л����ѽ����ݿ�������ʱ������
* ���������������ӵĹ�����
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

    //ע����'<='��'>='
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

    for(i = 0; i < index_temp; i++) //ע����'<'
    {
        A[i + start] = pTemp[i];
    }
}

void mergesort(int *A, int *pTemp, int start, int end)
{
    if(start < end)
    {
        int center = (start + end)/2;
        mergesort(A, pTemp, start, center);     //ǰ�벿������
        mergesort(A, pTemp, center + 1, end);   //��벿������
        myMerge(A, pTemp, start, center, end);  //�ϲ�
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




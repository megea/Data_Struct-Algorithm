//这个是指针数组和数组指针的测试结果。

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int p = 1;
    int y = p++;
    printf("y: %d", y);
    return 0;
}
    /*
    char *a[] = {"hello","the","world"};
    char **pa = a;
    char *b = "hello";

    pa++;

    printf("*pa:%s\n*pa[1]:%c\npa[1]:%s\n",*pa, *pa[1],pa[1]);
    printf("b[1]:%c\nb:%s\n",b[1],b);
    return 0;
}*/
/**输出结果为：
*pa:the
*pa[1]:w
pa[1]:world
b[1]:e
b:hello

Process returned 0 (0x0)   execution time : 2.348 s
Press any key to continue.
*/

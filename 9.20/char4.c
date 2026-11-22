#include <stdio.h>

int main()
{
    int i;
    int a[10];

    printf("请输入10个数字：\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("你输入的数字是：\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

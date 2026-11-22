#include <stdio.h>

int main()
{
    int i, j, temp;
    int a[10];

    printf("请输入10个数字：\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    // 正序排序：从小到大
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("正序排序（从小到大）：");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    // 逆序排序：从大到小
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("逆序排序（从大到小）：");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}

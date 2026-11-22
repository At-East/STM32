#include <stdio.h>

// 求和函数
int sum(int num_list[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += num_list[i];
    return s;
}

// 找最大值函数
int max(int num_list[], int n)
{
    int m = num_list[0];         
    for (int i = 1; i < n; i++)
    {
        if (num_list[i] > m)     
            m = num_list[i];
    }
    return m;
}

int main()
{
    int n;
    printf("请输入要处理的数字个数：\n");
    scanf("%d", &n);

    int a[100];              
    printf("请输入 %d 个数字：\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("sum=%d\n", sum(a, n));
    printf("max=%d\n", max(a, n));

    return 0;
}

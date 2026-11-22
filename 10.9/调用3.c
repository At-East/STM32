#include <stdio.h>

int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];
    return s;
}

int main()
{
    int n;
    printf("请输入要相加的数字个数：\n");
    scanf("%d", &n);

    int a[10000];  
    printf("请输入 %d 个数字：\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("sum=%d\n", sum(a, n));
    return 0;
}

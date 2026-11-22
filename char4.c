#include <stdio.h>

int main()
{
    int i,j;
    int a[10];

    printf("请输入10个数字：\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("%d ", a[i]);
    printf("\n");

    return 0;
}


#include <stdio.h>

int main()
{
    int i;
    int a[10];
    int sum = 0;       
    float average;

    printf("请输入10个数字：\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];   // 每输入一个数，就加到 sum 里
    }

    average = sum / 10.0;   // 注意这里写 10.0，不是 10

    printf("总和是：%d\n", sum);
    printf("平均数是：%.2f\n", average);

    return 0;
}

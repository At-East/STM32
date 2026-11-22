#include <stdio.h>

int main()
{
    int i;
    int a[10];
    int sum=0;
    float average;

    printf("请输入10个数字：\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        sum=sum+a[i];
    }
	average = sum / 10.0;
    printf("平均数是：%.2f\n", average);
    printf("\n");

    return 0;
}




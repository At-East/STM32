#include <stdio.h>

int pr()
{
    printf("这是一个自定义的函数\n");
    return 0;
}

int sum(int x, int y)
{
    int s = 0;
    s = x + y;      // 改成 x + y
    return s;
}

int main()
{
    int a, b;       // 定义两个整型变量
    int su;

    printf("请输入第一个数字：\n");
    scanf("%d", &a);   // 读入到 a

    printf("请输入第二个数字：\n");
    scanf("%d", &b);   // 读入到 b

    su = sum(a, b);    // 传参 a, b
    printf("sum=%d\n", su);

    return 0;
}

#include <stdio.h>

int main()
{
    int i = 1;
    int s = 0;   // 用于累加的和
    int n;       // 求和上限

    printf("请输入一个整数进行累加求和:");
	scanf("%d", &n);
	
    for(i = 1; i <= n; i++)
    {
        s = s + i;
      
    }

    printf("从1到%d累加的和为= %d\n", n, s);

    return 0;
}

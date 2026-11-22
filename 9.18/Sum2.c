#include <stdio.h>

int main()
{
    int i,n,s;
    s=0;
    printf("请输入一个整数进行累加求和:");
	scanf("%d", &n);
	
    for(i = 1; i <= n; i++)
    {
        s = s + i;
      
    }

    printf("从1到%d累加的和为= %d\n", n, s);

    return 0;
}

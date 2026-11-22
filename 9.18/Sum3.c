#include <stdio.h>

int main()
{
    int i,n, s = 0;
    
    //printf("请输入一个整数对1-这个数之间的偶数进行累加求和:\n"); //如果下面是100那么这行注释掉
    
	//scanf("%d",&n); //如果下面是100那么这行注释掉 
	
    for(i = 1; i <= 100; i++)//n也可以是100 
    {
        if(i % 2 == 0)   // 判断是否为偶数
            s = s + i;
        
    }

    printf("1~100之间偶数的和=%d\n", s);

    return 0;
}

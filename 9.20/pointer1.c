#include <stdio.h>
int main()
{
	int *pc,c;
	c = 5;
	pc = &c;
	printf("c的数值为：%d",c);
	printf("\nc的地址为：%p",pc);
	return 0;
}

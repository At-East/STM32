#include <stdio.h>
int main()
{
	int *pc,c,d;
	c = 5;
	d=-15;
	pc = &c; printf("%d",pc);
	pc = &d; printf("\nc的地址为：%p",pc);
	return 0;
}

#include <stdio.h>
int main()
{
    int *pc, c, d;
    c = 5;
    d = -15;

    pc = &c;
    printf("%p", pc);          // 原来 %d 改成 %p

    pc = &d;
    printf("\nd的地址为：%p", pc);  // 原来写“c的地址”，改成“d的地址”

    return 0;
}

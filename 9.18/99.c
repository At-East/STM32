#include <stdio.h>
int main()

{
	int i,j;

	for(j=1;j<=9;i++)
	{
		for(j = 1; j <= i; j++)//Êä³ö¿Õ¸ñ 
        { 
            printf("%d*%d=%d\t",j,i,j*i);
        }
		
		
		printf("\n");
	}
	
	return 0;
 } 

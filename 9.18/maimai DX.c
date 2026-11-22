#include <stdio.h>

int main()
{
    int i, j;   // i 行号，j 列号

    for(i = 1; i <= 5; i++)// 行：1~5
    {
        for(j = 1; j <= 6; j++)// 列：1~6
        
        {
            printf("%4d", 2 * i + 5 * j);
        }
        
        printf("\n");
    }

    return 0;
}

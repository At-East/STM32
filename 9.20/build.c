#include <stdio.h>
struct student
{
	char name[20];
	char id[20];
	int age;
	float high;
}st1 = {"张三","0123",19,178.6};
int main()
{
	printf("姓名：%s\n学号:%s\n年龄:%d\n身高:%.2f",st1.name,st1.id,st1.age,st1.high);
	return 0;
 } 

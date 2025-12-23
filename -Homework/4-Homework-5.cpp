#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
4-Homework-5
设计平方根计算器.
*/

int main()
{
	double a;
	scanf("%lf", &a);
	if (a > 0 && a < 1000)
	{
		printf("此数字的平方根为%.0lf（保留整数）",sqrt(a));
	}
	else
	{
		printf("请重新输入");
	}
	return 0;
}
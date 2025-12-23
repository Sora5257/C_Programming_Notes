#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
4-Homework-6
设计分段函数计算器.
*/

int main()
{
	double a;
	scanf("%lf", &a);
	if (a < 1)
	{
		printf("函数的值为%lf", a);
	}
	else if (a >= 1 && a < 10)
	{
		printf("函数的值为%lf", 2 * a - 1);
	}
	else
	{
		printf("函数的值为%lf", 3 * a - 11);
	}
	return 0;
}
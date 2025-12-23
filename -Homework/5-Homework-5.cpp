#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
5-Homework-5
求 Sn=a+aa+aaa+……+aa…a之值.
*/

int main()
{
	int a, n, a1;
	printf("请分别输入a,n的值\n");
	scanf("%d,%d", &a, &n);
	a1 = a;
	int Sn = a1;
	if (a >= 0 && a <= 9)
	{
		for (int i = 1; i <= (n - 1); ++i)
		{
			a = a1 + (a * 10);
			Sn += a;
		}
		printf("Sn=%d\n", Sn);
	}
	else
		printf("请重新输入\n");
	return 0;
}
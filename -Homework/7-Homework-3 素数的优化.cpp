#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
7-Homework-3
判断素数.
*/

/*
素数的优化-缩短时长
如果n不是素数，则有 n = a*b ，不妨假设a <= b (1）
又n = n^1/2 * n^1/2 (2)
由(1)(2)知 a <= n^1/2 （3）
反证: a > n^1/2 ，b >= a > n^1/2 , a*b > n^1/2 * n^1/2 = n ，则原假设不成立
*/

void Prio(int n)
{
	int i = 2;
	int tmp = -1;
	for (int i = 2; i < n; ++i);
	{
		if (n % i == 0)//找到能整除的数字
		{
			printf("%d不是素数\n", n);
			tmp = 0;
		}
	}
	if (tmp != 0)
		printf("%d是素数\n", n);
}

void Pri(int n)
{
	int tmp = -1;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			printf("%d不是素数\n", n);
			tmp = 0;
		}
	}
	if (tmp != 0)
		printf("%d是素数\n", n);
}

int main()
{
	int n;
	printf("请输入数字：");
	scanf("%d", &n);
	Pri(n);
	return 0;
}
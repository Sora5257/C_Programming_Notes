#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
5-Homework-3
求两数的最大公约数和最小公倍数.
*/

int main()
{
	int m, n, d, lit, e;
	scanf("%d,%d", &m, &n);
	printf("输入的两数为：%d,%d\n", m, n);
	if (m < n)
	{
		lit = m;
		d = n % m;
	}
	else
	{
		lit = n;
		d = m % n;
	}
	for (int i; d == 0;)//辗转相除法：通过不断取余来计算
	{
		i = d;
		lit = i;
		d = lit % d;
	}
	e = (m * n) / d;//两个数的乘积等于这两个数的最大公约数与最小公倍数的积
	printf("最大公因数为%d，最小公倍数为%d", d, e);
	return 0;
}
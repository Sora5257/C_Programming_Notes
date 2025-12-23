#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
7-Homework-1
求两数的最大公约数和最小公倍数.
*/

int Gcd(int m, int n)
{
	int gcd, lit;
	if (m < n)
	{
		lit = m;
		gcd = n % m;
	}
	else
	{
		lit = n;
		gcd = m % n;
	}
	for (int i; gcd == 0;)//辗转相除法：通过不断取余来计算
	{
		i = gcd;
		lit = i;
		gcd = lit % gcd;
	}
	return gcd;
}

int Lcm(int m, int n)
{
	int lcm;
	return lcm = (m * n) / Gcd(m, n);//两个数的乘积等于这两个数的最大公约数与最小公倍数的积
}

int main()
{
	int m, n;//greatest common divisor：最大公约数；least common multiple：最小公倍数
	printf("请输入两个数字：");
	scanf("%d,%d", &m, &n);
	printf("输入的两数为：%d,%d\n", m, n);
	printf("最大公约数为%d，最小公倍数为%d", Gcd(m, n), Lcm(m, n));
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
3-Homework-3：购房从银行贷了一笔款d，准备每月还款额为p，月利率为r，计算多少月能还清.
设d=300 000，p=6 000，r=1%.
对求得的月份取小数点后一位，对第2位按四舍五入处理.
*/

int main()
{
	int d = 300000;
	int p = 6000;
	double r = 0.01;
	double m = (log(p / (p - d * r)) / (log(1 + r)));
	printf("%.1lf月能还清\n", m);
	return 0;
}
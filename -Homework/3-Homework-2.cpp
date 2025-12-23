#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
3_Homework-2:计算存款利息.有1000元，想存5年，有以下5种方法：
a.一次存5年期；
b.先存2年期，到期后将本息再存3年期；
c.先存3年期，到期后将本息再存2年期；
d.存1年期，到期后将本息再存1年期，连续存5次；
e.存活期存款.活期利息每一季度结算一次.

2017年的银行存款利息为：
定期：1年期1.5%；2年期2.1%；3年期2.75%；5年期3%.
活期：0.35%（一季度结算一次）
*/

int main()
{
	double r1 = 0.015;
	double r2 = 0.021;
	double r3 = 0.0275;
	double r5 = 0.03;
	double r0 = 0.0035;
	double pa = 1000 * (1 + 5 * r5);
	double pb = 1000 * (1 + 2 * r2) * (1 + 3 * r3);
	double pc = 1000 * (1 + 3 * r3) * (1 + 2 * r2);
	double pd = 1000 * pow((1 + r1), 5);
	double pe = 1000 * pow((1 + (r0 / 4)), 4 * 5);
	printf("一次存5年期的本息和为%.2lf\n",pa);
	printf("先存2年期，到期后将本息再存3年期的本息和为%.2lf\n", pb);
	printf("先存3年期，到期后将本息再存2年期的本息和为%.2lf\n", pc);
	printf("存1年期，到期后将本息再存1年期，连续存5次的本息和为%.2lf\n", pd);
	printf("存活期存款.活期利息每一季度结算一次的本息和为%.2lf\n", pe);
	return 0;
}
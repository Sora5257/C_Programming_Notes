#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//3-Homework-1：设我国GDP的年增长率为7%，计算10年后我国GDP与现在相比增长多少百分比.

int main()
{
	double r = 0.07;//年增长率
	int n = 10;//年数
	double p = pow((1 + r), n);//公式
	printf("10年后我国GDP与现在相比增长百分比为%lf", p);
	return 0;
}
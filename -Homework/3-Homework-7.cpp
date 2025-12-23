#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#define PI M_PI

/*
3-Homework-7
设计圆、圆球、圆柱计算器.
*/

int main()
{
	double r, h;
	printf("圆、圆球、圆柱计算器\nPI=%lf\n\n请分别（回车）输入圆半径,圆柱高：\n",PI);
	scanf("%lf", &r);
	scanf("%lf", &h);
	printf("\n圆周长：%lf\n", 2 * PI * r);
	printf("圆面积：%lf\n", r * PI * r);
	printf("圆球表面积：%lf\n", r * PI * r * 4);
	printf("圆球体积：%lf\n", (4.0 / 3) * PI * r * r * r);
	printf("圆柱体积：%lf\n", 2 * r * PI * r * h);
	return 0;
}
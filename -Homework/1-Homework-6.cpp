#include<stdio.h>

//Homework1-6：编写一个C程序，运行时输入a,b,c三个值，输出其中值最大者.

int Max2(int x, int y)
{
	return x >= y ? x : y;
}

int Max3(int x, int y, int z)
{
	int w = Max2(x, y);
	return w >= z ? w : z;
}

int main()
{
	printf("在下面输入三个数字，格式例为：1，2，3");
	int a, b, c;
	scanf_s("%d,%d,%d", &a, &b, &c);
	printf("测试输入的数据：%d,%d,%d\n", a, b, c);
	int d = Max3(a, b, c);
	printf("最大值：%d\n", d);
	return 0;
}
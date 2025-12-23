#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
5-Homework-8
输出所有的水仙花数.
*/

int main()
{
	int sxh = 0, i1 = 0, i2 = 0, i3 = 0;
	for (int i = 0; i1 * 100 + i2 * 10 + i3 <= 1000; ++i)
	{
		sxh = i1 * i1 * i1 + i2 * i2 * i2 + i3 * i3 * i3;
		if ((i1 * 100 + i2 * 10 + i3) == sxh && sxh != 0 && sxh != 1 && sxh != 1000)
		{
			printf("%d\n", sxh);
		}
		++i3;
		if (i3 == 10)
		{
			i3 = 0;
			++i2;
		}
		if (i2 == 10)
		{
			i3 = 0;
			i2 = 0;
			++i1;
		}
	}
	return 0;
}
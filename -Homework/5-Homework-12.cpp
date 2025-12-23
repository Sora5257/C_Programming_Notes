#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
5-Homework-12
∫Ô◊”≥‘Ã“Œ Ã‚.
*/

int main()
{
	int r = 0, t = 2;//remainder,total
	for (;; ++t)
	{
		r = t;
		for (int i = 1; i <= 9; ++i)
		{
			r = (r / 2) - 1;
		}
		if (r == 1)
			break;
	}
	printf("%d\n", t);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
5-Homework-9
ÕÒ³ö¡°ÍêÊý¡±.
*/

int main()
{
	int a = 0;
	for (int n = 2; n <= 1000; ++n)
	{
		for (int i = 1; i < n; ++i)
		{
			if ((n % i) == 0)
				a += i;
		}
		if (a == n)
		{
			printf("%d it factors are ", n);
			for (int i = 1; i < n; ++i)
			{
				if ((n % i) == 0)
					printf("%d ", i);
			}
			printf("\n");
		}
		a = 0;
	}
	return 0;
}
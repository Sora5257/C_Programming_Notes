#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
5-Homework-17
找出乒乓球队的比赛名单.
*/

int main()
{
	int A = 0, B = -1, C = 0, X = 1, Y = -1, Z = 1;
	for (int i = 1; i <= 3; ++i)
	{
		for (;; ++Y)
		{
			if (C == Y)
			{
				C = 'C';
				Y = C;
				break;
			}
		}

	}
	return 0;
}
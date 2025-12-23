#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
6-Homework-3
求一3*3整形矩阵对角线元素之和.
*/

int main()
{
	int arr[3][3];
	for (int i = 0; i < 3; i++)//行
	{
		for (int j = 0; j < 3; j++)//列
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int sum = arr[0][0] + arr[0][2] + arr[1][1] + arr[2][0] + arr[2][2];
	printf("sum=%d\n",sum);
	return 0;
}
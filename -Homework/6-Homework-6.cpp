#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
6-Homework-6
输出10行杨辉三角形.
*/

int main()
{
	int arr[10][10];
	for (int i = 0; i < 10; ++i)//初始化
	{
		for (int j = 0; j < 10; ++j)
			arr[i][j] = 0;
	}
	for (int i = 0; i < 10; ++i)
		arr[i][0] = 1;
	for (int i = 1; i < 10; ++i)//加法生成
	{
		for (int j = 1; j < 10; ++j)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
	}
	for (int i = 0; i < 10; ++i)//输出
	{
		for (int j = 0; j < 10; ++j)
		{
			if (arr[i][j] == 0)//替换0
				continue;
			else
				printf("%-4d ", arr[i][j]);//3d：每个数字占四格，-表示左对齐
		}	
		printf("\n\n");
	}
	return 0;
}
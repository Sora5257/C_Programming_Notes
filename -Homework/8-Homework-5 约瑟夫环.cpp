#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
8-Homework-5
约瑟夫环.
*/

void Act(int arr[], int len)
{
	int brr[2][2000];
	for (int i = 0; i < 2000; i++)
		brr[0][i] = 0;
	for (int i = 0; i < 2000; i++)
		brr[1][i] = 0;
	int end = 0;
	int tmp2 = 1;
	for (int i = 0; i < len; i++)//定义
		brr[0][i] = *(arr + i);
	for (int i = 0; i < len; i += 3)
	{
		brr[1][i] = 1;
		brr[1][i + 1] = 2;
		brr[1][i + 2] = 3;
	}
	for (int ii = 0; ii < len; ii++)
	{
		if (brr[0][1] == 0)
			break;
		for (int i = 0; i < len; i++)//去除第三位
		{
			if (brr[1][i] = 3)
			{
				for (int j = i; j < len; j++)
					brr[0][j] = brr[0][j + 1];
			}
		}
		for (int i = 0; i < len; i++)//检测结尾
		{
			if (brr[0][i] == 0)
			{
				end = i;
				tmp2 = brr[1][i];
			}
		}
		for (int i = 0; i <= end; i += 3)//成环编号
		{
			brr[1][i] = tmp2 + 1;
			brr[1][i + 1] = tmp2 + 2;
			brr[1][i + 2] = tmp2;
		}
	}
	printf("Output:%d\n", brr[0][0]);
}

int main()
{
	int Inarr_Joseph(int arr[]);
	int arr[4095];
	int len = Inarr_Joseph(arr);
	Act(arr, len);
	return 0;
}

int Inarr_Joseph(int arr[])
{
	int len = 0;
	printf("Input length:");
	scanf_s("%d", &len);
	for (int i = 0; i < 4095; i++)
		*(arr + i) = 0;
	for (int i = 0; i < len; i++)
		*(arr + i) = (i + 1);
	return len + 1;
}

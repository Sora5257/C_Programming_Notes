#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
8-Homework-16
统计字符串的整数个数.
*/

int Num(char a)
{
	if (a >= '0' && a <= '9')
		return 1;
	else
		return 0;
}

int Act(int arr[], char str[])
{
	int len = 0;
	for (int i = 0; i < 2000; i++)
	{
		if (Num(str[i - 1]) == 0 && Num(str[i]) == 1)
		{
			char strtmp[2000] = " ";
			for (int j = 0; Num(str[i]) == 1; i++, j++)
				strtmp[j] = str[i];
			arr[len] = atoi(strtmp);
			len++;
		}
	}
	return len;
}

int main()
{
	void Outarr(int arr[], int len);
	int arr[2000];
	for (int i = 0; i < 2000; i++)
		arr[i] = 0;
	char str[2000] = " ";
	printf("Input:");
	fgets(str, 2000, stdin);
	int len = Act(arr, str);
	printf("\nTotal: %d numbers, they are:\n", len);
	Outarr(arr, len);
	return 0;
}

void Outarr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

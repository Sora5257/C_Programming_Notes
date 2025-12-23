#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
7-Homework-17
整形数据转换为字符串.
*/

int Its(char arr[],int a)
{
	int len = strlen(arr) - 1;
	int n = 0;
	if (a >= 0 && a < 10)
		;
	else
		return Its(arr, a);
}

int main()
{
	int a = 0;
	char arr[4096];
	printf("Input:");
	scanf("%d", &a);
	Its(arr,a);
	puts(arr);
	return 0;
}
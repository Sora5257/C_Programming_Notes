#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
6-Homework-2
用选择法对10个整数排序.
*/

int main()
{
	int arr[] = { 5,0,1,8,6,2,3,4,9,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int min, rec;
	for (int i = 0; i < len; ++i)
	{
		min = arr[i];
		rec = i;
		for (int c = i; c < len; c++)
		{
			if (min > arr[c])
			{
				rec = c;
				min = arr[c];
			}
		}
		for (int c = rec; c > i; c--)
			arr[c] = arr[c - 1];
		arr[i] = min;
	}
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
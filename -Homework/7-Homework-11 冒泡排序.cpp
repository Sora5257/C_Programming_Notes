#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
7-Homework-11
冒泡排序：从头到尾，两两比较，大的往后，小的往前.
*/

int Bs(int arr[],int len)
{
	int tmp;
	for (int i = 0; i < len - 1; ++i)//循环的趟数
	{
		for (int j = 0; j + 1 < len - i; ++j)//每一趟需要从头到“尾”（不包括一句有序的数据）遍历
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return len;
}

int main()
{
	int arr[] = { 23,45,6,12,25,68,79,80,55,52 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Bs(arr,len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
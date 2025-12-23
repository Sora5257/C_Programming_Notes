#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
6-Homework-9
用折半查找法查找数组中的元素.
*/

int main()
{
	int ipt, opt = 0, ykn = 0;
	scanf("%d", &ipt);
	int arr[] = { 3,5,23,65,12,76,13,32,98,123,765,45,33,7,77 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 15; ++i)//判断数组中是否有此数
	{
		if (ipt == arr[i])
			ykn = 1;
	}
	if (ykn != 1)
	{
		printf("无此数\n");
		return 0;
	}
	else
	{
		int min, rec;//选择法排序
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
		int low = 0;//折半查找法
		int high = len - 1;
		int mid;
		for (int i = 1; high >= low; ++i)
		{
			mid = (low + high) / 2;
			if (ipt > arr[low] && ipt < arr[mid])
				high = mid - 1;
			else if (ipt > arr[mid] && ipt < arr[high])
				low = mid + 1;
			else if (ipt == arr[mid])
			{
				opt = mid;
				break;
			}
			else if (ipt == arr[low])
			{
				opt = low;
				break;
			}
			else if (ipt == arr[high])
			{
				opt = high;
				break;
			}
			else
				continue;
		}
		printf("%d\n", opt+1);
		return 0;
	}
}
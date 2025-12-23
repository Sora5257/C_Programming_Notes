#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
8-Homework-3
输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换.
*/

int Max83(int arr[], int len)
{
	int tmp = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[tmp] < arr[i])
			tmp = i;
	}
	return tmp;
}

int Min(int arr[], int len)
{
	int tmp = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[tmp] > arr[i])
			tmp = i;
	}
	return tmp;
}

void Input(int* arr)
{
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	printf("\n");
}

void Output(int* arr)
{
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void Do(int*arr)
{
	int max = Max83(arr, 11);
	int min = Min(arr, 11);
	int tmp;
	tmp = arr[0];
	arr[0] = arr[min];
	arr[min] = tmp;
	tmp = 0;
	tmp = arr[9];
	arr[9] = arr[max];
	arr[max] = tmp;
	tmp = 0;
}

int main()
{
	int arr[11];
	Input(arr);
	Do(arr);
	Output(arr);
	return 0;
}
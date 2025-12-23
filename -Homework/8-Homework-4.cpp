#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
8-Homework-4
Êý×éË³ÐòºóÒÆ.
*/

void Act(int* arr, int len)
{
	int c = 0;
	printf("\n");
	printf("Input the exchanging location:");
	scanf_s("%d", &c);
	int brr[100] = { 0 };
	int crr[100] = { 0 };
	for (int i = 0; i < c; i++)
		brr[i] = arr[i];
	int j = 0;
	for (int i = c; i < len; i++, j++)
		crr[j] = arr[i];
	j = 0;
	for (int i = 0; i < len - c; i++, j++)
		arr[j] = crr[i];
	for (int i = 0; i < c; i++, arr++)
		arr[j] = brr[i];
	printf("\n");
}

int main()
{
	int arr[100] = { 0 };
	int Inarr(int arr[]);
	int len = Inarr(arr);
	void Outarr(int arr[], int len);
	Act(arr, len);
	Outarr(arr, len);
	return 0;
}

int Inarr(int arr[])
{
	int len = 0;
	char stop = ' ';
	printf("Input (Press / to end):\n");
	for (int i = 0; stop != '/'; i++)
	{
		scanf_s("%d", &arr[i]);
		scanf("%c", &stop);
		if (stop == '/')
		{
			len = i;
			break;
		}
	}
	return len;
}

void Outarr(int arr[], int len)
{
	printf("\nOutput:");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

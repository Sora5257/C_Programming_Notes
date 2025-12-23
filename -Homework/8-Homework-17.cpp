#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
8-Homework-17
Ä£Äâstrcmpº¯Êý.
*/

int Strcmp(char str1[], char str2[])
{
	int len = 0;
	if (strlen(str1) > strlen(str2))
		len = strlen(str1);
	else
		len = strlen(str2);
	for (int i = 0; i < 4095; i++)
	{
		if (str1[i] > str2[i])
			return str1[i] - str2[i];
		else if (str1[i] < str2[i])
			return str2[i] - str1[i];
		else
			continue;
	}
}

int main()
{
	char str1[4095] = " ";
	char str2[4095] = " ";
	fgets(str1, 4095, stdin);
	fgets(str2, 4095, stdin);
	printf("%d\n", Strcmp(str1, str2));
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
7-Homework-5
反序存放字符串并输出.
*/

char stro[4096] = " ";

void Isdcs(char stri[], int len)
{
	char strtmp[2] = " ";
	for (int i = len - 1; i >= 0; i--)
	{
		strtmp[0] = stri[i];
		strcat(stro, strtmp);
	}
}

int main()
{
	char stri[4096] = " ";
	printf("请输入一串字符：");
	fgets(stri, 4096, stdin);
	int len = strlen(stri);
	Isdcs(stri, len);
	puts(stro);
	return 0;
}

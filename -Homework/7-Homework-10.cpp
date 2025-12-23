#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
7-Homework-10
输出字符串中最长的单词.
*/

void Lw(char str[], int len)
{
	char strtmp[250] = { 0 };
	char strw[250] = { 0 };
	char strlw[1000] = { 0 };
	for (int i = len - 1; i >= 0; i--)
		str[i + 1] = str[i];
	str[0] = ' ';
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i - 1]) == 0 && isalpha(str[i]) != 0)//进入单词（不是；是）
		{
			int n = 0;
			for (int j = 0; isalpha(str[i]) != 0; i++, j++)
			{
				n++;
				strtmp[j] = str[i];
			}
			strcpy(strw, strtmp);
			for (int a = 0; a < 250; a++)
				strtmp[a] = { 0 };
			int last = 0;
			if (n > last)
			{
				strcpy(strlw, strw);
				for (int a = 0; a < 250; a++)
					strw[a] = { 0 };
			}
			else if (n == last)
			{
				for (int k = 0; k < n; k++)
				{
					if (isalpha(strw[k]) == isalpha(strlw[k]) && isalpha(strlw[k]) != 0 && isalpha(strw[k]) != 0)
						if (strw[k] != strlw[k])//无重复
						{
							strtmp[0] = '&';
							strcat(strtmp, strlw);
							strcat(strw, strtmp);
							strcpy(strlw, strw);
							for (int a = 0; a < 250; a++)
								strtmp[a] = { 0 };
						}
				}
				for (int a = 0; a < 250; a++)
					strw[a] = { 0 };
			}
			else
			{
				for (int a = 0; a < 250; a++)
					strw[a] = { 0 };
				for (int a = 0; a < 250; a++)
					strtmp[a] = { 0 };
			}
			puts(strlw);//TEST,cb ctt crr ctt c
			last = n;
			n = 0;
		}
	}
	printf("The Longest word:");
	puts(strlw);
}

int main()
{
	char str[4096] = " ";
	printf("Input here:");
	fgets(str, 4096, stdin);
	int len = strlen(str);
	Lw(str, len);
	return 0;
}

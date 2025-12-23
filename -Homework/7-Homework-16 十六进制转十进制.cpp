#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
7-Homework-16
十六进制转十进制.
*/

int C1610(char str[], int len)
{
	int a = 0;
	int p = 1;//Place
	int wrong = 0;
	char place1[] = "0123456789ABCDEF";
	char place2[] = "abcdef";
	char place3[] = "GHIJKLMNOPQRSTUVWXYZghijklmnopqrstuvwxyz";
	for (int i = len - 2; i >= 0; i--)
	{
		for (int j = 0; j <= 15; j++)
		{
			if (str[i] == place1[j])
				a += (j * p);
		}
		for (int j = 0; j <= 5; j++)
		{
			if (str[i] == place2[j])
				a += ((j + 10) * p);
		}
		for (int j = 1; j <= 40; j++)
		{
			if (str[i] == place3[j])
			{
				printf("Wrong Input!\n");
				break;
				wrong = 1;
			}
				
		}
		if (wrong == 1)
			return NULL;
		p = 16 * pow(10, len - 3);
	}
	return a;
}

int main()
{
	char str[4096] = "";
	printf("Input:");
	fgets(str, 4096, stdin);
	int len = strlen(str);
	printf("Output:%d\n", C1610(str,len));
	return 0;
}
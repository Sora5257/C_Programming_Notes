#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
5-Homework-4
读取一行字符.
*/

int main()
{
	char ch = 0;
	int letters = 0, space = 0, digit = 0, other = 0;
	printf("请输入一行字符:");
	for (; (ch = getchar()) != '\n';)
	{
		if (ch == ' ')
			space++;
		else if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
			letters++;
		else if (ch >= '0' && ch <= '9')
			digit++;
		else
			other++;
	}
	printf("letters = %d, space = %d, digit = %d, other = %d\n", letters, space, digit, other);
	return 0;
}
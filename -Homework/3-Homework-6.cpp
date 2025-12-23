#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
3-Homework-6
译码，使后面第4位字母代替原有字母.
用赋初值的方法使c1,c2,c3,c4,c5,c6这6个变量的值分别为'C','i','a','l','l','o'.
经过计算译码.
分别用putchar函数和printf函数输出这6个字符.
*/

int main()
{
	char c1 = 'C';
	char c2 = 'i';
	char c3 = 'a';
	char c4 = 'l';
	char c5 = 'l';
	char c6 = 'o';
	printf("输入：%c%c%c%c%c%c\n", c1, c2, c3, c4, c5, c6);
	c1 = c1 + 4;
	c2 = c2 + 4;
	c3 = c3 + 4;
	c4 = c4 + 4;
	c5 = c5 + 4;
	c6 = c6 + 4;
	printf("输出putchar：");
	putchar(c1);//输出一个字符到屏幕
	putchar(c2);
	putchar(c3);
	putchar(c4);
	putchar(c5);
	putchar(c6);
	printf("\n");
	printf("输出printf：%c%c%c%c%c%c\n", c1, c2, c3, c4, c5, c6);
	return 0;
}
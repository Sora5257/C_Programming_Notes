#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
10-Homework-3
字符串小写转大写.
*/

void Strupr(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)//遍历字符串
	{
		if (islower(str[i]))//判断是否为小写字母
		{
			str[i] = toupper(str[i]);//小写转大写
		}
	}
}

int main()
{
	FILE* fw = fopen("D:\\Files\\Code\\C_Journey\\C_Journey\\-Homework\\10-Homework-3.txt", "w");
	if (fw == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return 0;
	}
	char str[4096];
	printf("Input:");
	fgets(str, 4096, stdin);
	int len = strlen(str);
	Strupr(str);
	for (int i = 0; i <4096; i++)
	{
		if (str[i] == '\0')
		{
			str[i] = '!';
			break;
		}
	}
	fwrite(&str, sizeof(char), len + 1, fw);
	fclose(fw);
	return 0;
}
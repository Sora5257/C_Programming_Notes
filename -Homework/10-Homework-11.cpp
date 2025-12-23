#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
10-Homework-11
字符串小写转大写.
*/

void Strupr(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
	}
}

int main()
{
	FILE* fw = fopen("D:\\Files\\Code\\C_Journey\\C_Journey\\-Homework\\10-Homework-11.txt", "w");
	if (fw == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return 0;
	}
	char str1[4096] = "";
	char str2[1000] = "";
	printf("Input (Press / to end):\n");
	for (int i = 0; i < 4096; i++)
	{
		fgets(str2, 1000, stdin);
		if (str2[0] == '/')
		{
			for (int j = 0; j < 1000; j++)
				str2[j] = NULL;
			break;
		}
		else
		{
			strcat(str1, str2);
			for (int j = 0; j < 1000; j++)
				str2[j] = NULL;
		}
	}
	int lenw = strlen(str1);
	fwrite(&str1, sizeof(char), lenw, fw);
	fclose(fw);
	FILE* fr = fopen("D:\\Files\\Code\\C_Journey\\C_Journey\\-Homework\\10-Homework-11.txt", "r");
	if (fr == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return 0;
	}
	char buf[4096] = "";//存放读取的数据
	int lenr = fread(buf, sizeof(char), 4096, fr);
	Strupr(buf);
	buf[lenr] = NULL;//修复BUG
	printf("\nOutput:\n");
	printf("%s\n", buf);
	fclose(fr);
	return 0;
}

//Over:2025/8/12 18:49
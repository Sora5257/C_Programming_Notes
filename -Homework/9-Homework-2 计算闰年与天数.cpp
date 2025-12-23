#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
9-Homework-2
计算闰年与天数.
*/

typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

void Day(const Date* date)
{
	int month[2][12] = { {1,2,3,4,5,6,7,8,9,10,11,12},{31,0,31,30,31,30,31,31,30,31,30,31} };
	if (date->year % 4 == 0 && date->year % 100 != 0 || date->year % 400 == 0)//判断闰年
		month[1][1] = 29;
	else
		month[1][1] = 28;
	int day = 0;
	for (int i = 0; i < 12; i++)
	{
		if (date->month == month[0][i])
		{
			for (int j = 0; j < i; j++)
				day += (month[1][j]);
			day += (date->day);
		}
	}
	printf("%d days\n", day);
}

int main()
{
	Date date = { 0,0,0 };
	printf("Input(Year,Month,Day):");
	scanf("%d,%d,%d", &date.year, &date.month, &date.day);
	Day(&date);
	return 0;
}
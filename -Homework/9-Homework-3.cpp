#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
9-Homework-3,4
打印学生成绩数组.
*/

typedef struct Stu
{
	int num;
	char name[20];
	float score[3] = { 0,0,0 };
}Stu;

void Input2(Stu* arr)
{
	printf("Input(number,name,score1,score2,score3):\n");
	for (int i = 0; i < 5; i++)
		scanf("%d %s %f %f %f", &arr[i].num, &arr[i].name, &arr[i].score[0], &arr[i].score[1], &arr[i].score[2]);
}

int main()
{
	Stu stu[5];
	Input2(stu);
	for (int i = 0; i < 5; i++)
	{
		printf("%d,%s,%.1f,%.1f,%.1f", stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
		printf("\n");
	}
	return 0;
}

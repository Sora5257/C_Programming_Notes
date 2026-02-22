#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
文件：

文件概念：
输入流：从外存到内存
输入设备：触摸板，触摸屏，鼠标，键盘（标准输入设备）
输出流：从内存到外存
输出设备：打印机，屏幕（标准输出设备）

文件分类：
文本（ASCII）文件：能直接查看的文件，都是文本（字符）数据
二进制文件：不能直接查看，都是二进制数据

文件操作：
文件类型指针：FILE * ，文件操作中的唯一凭证
fopen：打开文件，注意文件路径中\的写法，\\用于表示\字符本身
fclose：关闭文件
fwrite：向文件中写入内存数据
fread：从文件中读取数据到内存
rewind：将位置指针移动到文件开头
fseek：将位置指针移动到任意位置，即改变文件读写位置标记
e.g.
fseek(fr,0,SEEK_SET);//以当前文件开头作为参照点，相对位置为0（即开头）
fseek(fr,-len,SEEK_CUR);//以当前文件位置指针作为参照点，相对位置-len（即向左len长度）
fseek(fr,-len,SEEK_END);//以当前文件末尾作为参照点，相对位置-len（即向左len长度）

随机读写原理：
文件读写位置标记（类似光标：图形界面的说明）读写时自动移动
顺序读写
随机读写：改变文件读写位置标记
'\0'是字符串的结尾标记，但在文件中不可见或者用NUL表示（'\0'对于文件而言不重要）
*/

#if 0
int main()
{
	FILE* fw = fopen("D:\\Files\\Code\\C_Journey\\C_Journey\\10-Test-01.txt", "w");//创建一个文件，绝对路径
	const char* str = "Hello World!";
	fwrite(str, sizeof(char), strlen(str), fw);//未写入“\0”
	fclose(fw);
	return 0;
}
#endif

//从键盘输入字符，逐个向磁盘输出（直到用户输入一个"#"为止），并读取字符串、复制文件

#if 0
int main()
{
	FILE* fw1 = fopen("D:\\Files\\Code\\C_Journey\\C_Journey\\10-Test-1.txt", "w");
	if (fw1 == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return 0;
	}
	char ch1;
	while ((ch1 = getchar()) != '#')
	{
		fwrite(&ch1, sizeof(char), 1, fw1);
		//fputc(ch, fw);//只能输出字符，有局限性
	}
	FILE* fr = fopen("D:\\Files\\Code\\C_Journey\\C_Journey\\10-Test-1.txt", "r");
	if (fr == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return 0;
	}
	char buf[100] = "";//存放读取的数据
	int len = fread(buf, sizeof(char), 100, fr);
	printf("%d,%s\n", len, buf);
	FILE* fw2 = fopen("D:\\Files\\Code\\C_Journey\\C_Journey\\10-Test-2.txt", "w");
	if (fw2 == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return 0;
	}
	char ch2;
	while ((ch2 = fgetc(fr)) != EOF)//将10-Test-1.txt复制到10-Test-2.txt
	{
		fputc(ch2, fw2);
	}
	fclose(fr);
	fclose(fw1);
	fclose(fw2);
	return 0;
}
#endif

//读写二进制数据，并选择性输出奇数学号的学生信息

typedef struct Stub
{
	char name[20];
	int num;
	int age;
	char addr[100];
}Stub;

void Inputb(Stub* arr, int n)
{
	printf("请输入%d个学生信息：\n", n);
	printf("姓名 学号 年龄 地址\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d %s", &arr[i].name, &arr[i].num, &arr[i].age, &arr[i].addr);
	}
}

void Saveb(Stub* arr, int n)//b：二进制
{
	FILE* fw = fopen("10-Test-3.txt", "wb");//相对路径，10-Test-3.txt和当前源文件在同一个目录（文件夹）
	if (fw == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return;
	}
	/*for (int i = 0; i < n; i++)
		fwrite(&arr[i], sizeof(Stu10), 1, fw);*/
	fwrite(arr, sizeof(Stub), n, fw);
	fclose(fw);
}

void Showb()
{
	FILE* fr = fopen("10-Test-3.txt", "rb");
	if (fr == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return;
	}
	Stub stus;//保存从文件读取的数据
	while (fread(&stus, sizeof(Stub), 1, fr) > 0)//注意fread函数的返回值
	{
		printf("%s,%d,%d,%s\n", stus.name, stus.num, stus.age, stus.addr);
	}
	fclose(fr);
}

void Last()
{

	FILE* fr = fopen("10-Test-3.txt", "rb");
	if (fr == NULL)
	{
		printf("打开文件失败，请检查文件路径是否正确\n");
		return;//主函数中可返回-1
	}
	Stub stus;
	int len;
	for (int i = 0; i < 5; i++)
	{
		len = fread(&stus, sizeof(Stub), 1, fr);
		if (len < 1)
		{
			printf("文件结束\n");
			break;
		}
		printf("%s,%d,%d,%s\n", stus.name, stus.num, stus.age, stus.addr);
		fseek(fr, sizeof(Stub), SEEK_CUR);//跳过一个学生
	}
	fclose(fr);
}

#if 0
int main()
{
	Stub stuw[10];
	int len = sizeof(stuw) / sizeof(stuw[0]);
	Inputb(stuw, len);
	Saveb(stuw, len);
	Showb();
	return 0;
}

#endif

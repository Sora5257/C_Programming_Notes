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

fopen：打开文件。原型：FILE *fopen( const char *filename, const char *mode );
第一个参数：该参数为字符串类型，表示要打开的文件的名称
第二个参数：该参数为字符串类型，表示打开模式(只读、只写、更新、追加)
fopen( )函数会为要打开的文件创建流并返回一个指向文件对象的FILE*型指针
注意文件路径中\的写法，\\用于表示\字符本身

fclose：关闭文件。原型：int fclose( FILE *stream );

fscanf：从文件中读取数据。原型：int fscanf( FILE *stream, const char *format, ... );
与scanf( )函数比起来，fscanf( )函数多了一个输入参数即FILE *stream；
它表示从哪个文件读取数据。除此以外，它与scanf( )函数完全相同。

fprintf：向文件中写入数据。原型：int fprintf( FILE *stream, const char *format, ... );
比较与上述函数同理

fgetc：从文件中读取一个字符并将其转为int型作为函数的返回值。原型：int fgetc( FILE *stream );
fputc：向文件中写入一个字符。原型：int fputc( int ch, FILE *stream );
fgets：该函数从文件指针stream指向的文件内读取字符串并保存到指针str所指向的内存空间中，
直至已读size-1个字符或出现换行符或文件末尾时为止；当读取错误或者读到文件末尾EOF返回NULL。
原型：char *fgets( char *str, int count, FILE *stream );
该函数会读取最后的换行符’\n’。
fputs：将str指向的字符串写入stream指向的文件流，成功返回非负数；反之EOF。原型：int fputs( const char *str, FILE *stream );
该函数输入完成后不会增加额外的特殊字符(如换行符等)。

按照二进制的形式对文件进行读写操作
fwrite：向文件中写入内存数据。原型：int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
fread：从文件中读取数据到内存。原型：size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
第一个参数：指向读写数据首地址的指针。
第二个参数：要操作的单个数据的大小。例如，int型数据的大小就是sizeof(int)
第三个参数：数据个数
第四个参数：文件指针

rewind：将位置指针移动到文件开头
feof：检测文件流是否到达了文件末尾（EOF）。原型：int feof(FILE *stream);
如果文件流位于文件末尾，则该函数返回非零值。否则，返回零。

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



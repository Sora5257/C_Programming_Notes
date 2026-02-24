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
fopen( )函数会为要打开的文件创建流并返回一个指向文件对象的FILE*型指针
注意文件路径中\的写法，\\用于表示\字符本身
第一个参数：该参数为字符串类型，表示要打开的文件的名称
第二个参数：该参数为字符串类型，表示打开模式(只读、只写、更新、追加)

EOF作为文件结束的标志，但是文件必须是文本文件。EOF的值为-1。 对于文本文件，fgetc函数读入最后一个字符时，返回值是最后一个字符。
a：为在文件后面添加数据而打开文本文件。
这时，如果指定的文件不存在，系统将用在fopen调用中指定的文件名建立一个新文件；
如果指定的文件已存在，则文件中原有的内容将保存，新的数据写在原有内容之后。 
a+：功能与a相同，只是在文件尾部添加新的数据之后，可以从头开始读。
w：只能用于向该文件写数据（即输出文件），而不能用来向计算机输入。
这时，如果指定的文件不存在，系统将用在fopen调用中指定的文件名建立一个新文件；
如果指定的文件已存在，则将从文件的起始位置开始写，文件中原有的内容将全部消失。
wb：为写而打开一个二进制文件。可以在指定文件位置进行写操作，其余功能与"w"类似。
r：为读而打开文本文件。当指定这种方式时，对打开的文件只能进行"读"操作。

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

rewind：将文件内部的位置指针重新指向一个流（数据流或者文件）的起始位置。原型：void rewind(FILE *fp);
fseek：将位置指针移动到任意位置，即改变文件读写位置标记。原型：int fseek(FILE *fp,long offset,int from);
如果该函数执行成功，fp 将指向以 from 为基准，偏移 offset 个字节的位置，函数的返回值为 0；
如果该函数执行失败（比如 offset 超过文件自身大小），则不改变 fp 指向的位置，函数的返回值为 -1，并设置 errno 的值，可以用 perror 函数来输出错误信息。
调用 fseek 函数的文件指针 fp 应该指向已经打开的文件，否则将会出现错误。
fseek 函数一般用于二进制文件，当然也可以用于文本文件。
需要特别注意的是，当 fseek 函数用于文本文件操作时，一定要注意回车换行的情况。
因为在一般浏览工具（如 UltraEdit）中，回车换行被视为两个字符 0x0D 和 0x0A，但真实的文件读写和定位却按照一个字符 0x0A 进行处理。
因此，在碰到此类问题时，可以考虑将文件整个读入内存，然后在内存中手工插入 0x0D的方法，这样可以达到较好的处理效果。
fseek 函数只返回执行的结果是否成功，并不返回文件的读写位置。因此，你可以使用 ftell 函数来取得当前文件的读写位置。
对于 fseek 函数中的参数：
第一个参数 fp 为文件指针；
第二个参数 offset 为偏移量，它表示要移动的字节数，整数表示正向偏移，负数表示负向偏移；
第三个参数 from 表示设定从文件的哪里开始偏移：
SEEK_SET 0 表示从文件起始位置增加 offset 个偏移量为新的读写位置；
SEEK_CUR 1 表示从目前的读写位置增加 offset 个偏移量为新的读写位置；
SEEK_END 2 表示将读写位置指向文件尾后，再增加 offset 个偏移量为新的读写位置。
e.g.
fseek(fr,0,SEEK_SET);//以当前文件开头作为参照点，相对位置为0（即开头）
fseek(fr,-len,SEEK_CUR);//以当前文件位置指针作为参照点，相对位置-len（即向左len长度）
fseek(fr,-len,SEEK_END);//以当前文件末尾作为参照点，相对位置-len（即向左len长度）
当 from 值为 SEEK_CUR 或 SEEK_END 时，参数 offset 允许出现负值。
ftell：得到文件位置指针当前位置相对于文件首的偏移字节数。原型：long ftell(FILE *fp);
feof：检测文件流是否到达了文件末尾（EOF）。原型：int feof(FILE *stream);
如果文件流位于文件末尾，则该函数返回非零值。否则，返回零。

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





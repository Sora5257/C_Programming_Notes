#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
指针：地址
&变量名：获取该变量的地址（指针），&称为取地址符
&的作用：1.按位与（双目运算符） e.g. 4&3；2.取地址（单目运算符） e.g. &a；3.C++的引用

指针变量：保存指针的变量
定义：类型 *变量名;
在指针变量定义时，*用于说明该变量是一个指针变量
用法：*p访问p所指向的变量
一个函数A通过调用函数B，以达到修改A中变量的值：1.必须传指针；2.在B中必须解引用.
*p：解引用，间接访问符

指针的算术运算（前提：指针指向一个数组，同时程序应该保存不越界）
p+整数，p++，++p 合法
p-整数，p--，--p 合法

指针的关系运算
>,<,>=,<=,==,!=
前提：必须在同一个数组中

数组作为参数传递
一维数组arr的名字arr表示整个数组只有如下情况：
1.在定义数组的同一个函数中求sizeof（整个数组的大小（字节数））
2.在定义数组的同一个函数中，&arr+1，表示加整个数组的大小（字节数）
其他情况，arr都表示数组的起始地址（数组首元素的地址，即 &arr[0] == arr）
标准规定可以使用尾后地址（指针）

通过指针引用多维数组
int arr[4]
arr：int* x
arr+1：int* x
arr[0]：int

int brr[3][4]//行优先，此时可以将每一行想象为一个元素，将二维数组想象为一维数组
brr：int (*x)[4]
brr[0]：int* x
brr+1：int (*x)[4]
brr[0]+1：int* x
brr[0][0]：int
brr[0][0]+1：int

按位与：相同的位都为1才为1
4:100 &
3:011
0:000
*/

/*
qsort函数
qsort(base,nummber,width,compare)
base：目标数组的开头
number：元素中的数组大小
width：元素大小（字节）
compare：指向用户提供的例程的指针比较两个数组元素，并返回指定他们关系的值
难点：如何（从哪方面）比较两个数据的大小，所以要提供对数据比较的依据
*/

/*
指向函数的指针
标准规定函数名也表示函数的入口地址，即 Fun == &Fun
有函数族
*/

int Max1(int a, int b)
{
	return a >= b ? a : b;
}

int Min1(int a, int b)
{
	return a <= b ? a : b;
}

int Avg1(int a, int b)
{
	return (a + b) / 2;
}

#if 0
int main()
{
	int(*pfun)(int, int);//pfun一定是指针，该指针指向函数，函数参数为int，int，返回值为int.
	pfun = Max1;
	pfun = Min1;
	pfun = Avg1;
}
#endif

/*
int main()
{
	int a = 10;
	printf("%d,%d\n", a, &a);//a的值，a的地址
	int* p = &a;//定义
	printf("%d,%d,%d\n", *p, p, &p);//p指向的变量a的值，a的地址，p的地址
	return 0;
}
*/

//悬空指针 悬挂指针 野指针
#if 0
int main()
{
	int* p;
	*p = 10;
	return 0;
}
#endif

/*
动态内存

使用场景：
1.需要大容量内存
2.一个函数内创建的内存，在别的函数中还需要使用时
3.在vs2022中需要使用变量作为数组长度
注意：局部变量分配的内存区域在栈里（1M~10M）

创建动态内存：
malloc：创建内存，成功返回地址，失败返回NULL. e.g. void* p = malloc(1024*1024*10);//10M
calloc：创建内存 e.g. int* arr = (int*)calloc(100,sizeof(int));//申请100个int单元，arr可以看作是100长度的int数组名
realloc：修改动态内存的大小 e.g. arr = (int*)realloc(arr,2*n*sizeof(int));//指向需要修改的内存指针(arr)
free：释放内存 e.g. free(p);

如果没有释放动态申请的内存，会出现内存泄漏（C和C++最麻烦的问题）
内存泄漏：申请后忘记释放，导致别的程序无法再使用申请的内存，使得可用内存变少，速度变慢
void*：没有数据类型信息的指针，仅记录地址
进程结束或关机后，泄露的内存会释放
calloc会将每个元素初始化为0
*/

//交换两个变量的值

void Swap(int* p1, int* p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

#if 0
int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	Swap(&a, &b);
	printf("%d,%d", a, b);
	return 0;
}
#endif

//解一元二次方程（返回两个值）
//x1,x2称为输出参数（传指针，内部解引用）

int Fun(int a, int b, int c, double* x1, double* x2)
{
	int d = b * b - 4 * a * c;
	*x1 = (-b + sqrt(d)) / (2 * a);
	*x2 = (-b - sqrt(d)) / (2 * a);
	return 2;//返回两个根
}

#if 0
int main()
{
	double x1;
	double x2;
	Fun(4, 5, 1, &x1, &x2);
	printf("%lf,%lf\n", x1, x2);
	return 0;
}
#endif

//通过指针输出（访问）数组的所有元素的多种方法，加减法同理

/*
for (int i = 0; i < 10; i++, p++)
	printf("%d ", *p);

for (int i = 0; i < 10; i++)
	printf("%d ", *p++);

for (int i = 0; i < 10; i++)
	printf("%d ", *(p + i));
*/

//逆序存放数组中的整数

void Inv(int* x, int n)//x为数组的起始地址，n为元素个数
{
	int tmp;
	for (int i = 0, j = n - 1; i < j; i++, j--)
	{
		/*
		tmp = x[i];
		x[i] = x[j];
		x[j] = tmp;
		*/
		tmp = *(x + i);
		*(x + i) = *(x + j);
		*(x + j) = tmp;
	}
}

void Show(int* p, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
}

#if 0
int main()
{
	int arr[] = { 1,3,5,7,9,11,13,15,17,19 };
	Inv(arr, sizeof(arr) / sizeof(arr[0]));
	Show(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
#endif

//选择法排序

void SelectSort1(int arr[], int n)//arr为数组的起始地址，len为元素个数
{
	int k;//最小值的下标
	int tmp;
	for (int i = 0; i < n - 1; i++)//排序的趟数
	{
		k = i;
		for (int j = i + 1; j < n; j++)//找最小值的下标
		{
			if (*(arr + j) < *(arr + k))//找到最小值，需要更新数据
				k = j;
		}
		if (k != i)//把“第一个”值和最小值交换
		{
			tmp = *(arr + i);
			*(arr + i) = *(arr + k);
			*(arr + k) = tmp;
		}
	}
}

//输出二位数组中所有元素的值

void Showb(int (*brr)[4],int row)//brr = int (*brr)[4]
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d ", brr[i][j]);
	}
	printf("\n");
}

#if 0
int main()
{
	int brr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Showb(brr, 3);
	return 0;
}
#endif

//不使用库函数，实现字符串复制
//des：目的地址；src：原字符串地址

void Mystrcpy(char* des, char* src)//通过'\0'判断结尾，不需要传长度
{
	int i = 0;
	for (i = 0; src[i] != '\0'; i++)
		des[i] = src[i];
	des[i] = '\0';
}

#if 0
int main()
{
	char str1[] = "abcde";
	char str2[10];
	Mystrcpy(str2, str1);
	printf("str2=%s\n", str2);
	return 0;
}
#endif

//比较两个数组中元素的值

/*
返回值
第一个 >  第二个：返回大于0的数字
第一个 == 第二个：返回0
第一个 <  第二个：返回小于0的数字
*/

int Cmp_int(const void* vp1, const void* vp2)
{
	return *(int*)vp1 - *(int*)vp2;//还原本质
}

int Cmp_double(const void* vp1, const void* vp2)
{
	double tmp = *(double*)vp1 - *(double*)vp2;//还原本质
	if (tmp > 0)
		return 1;
	else if (tmp < 0)
		return -1;
	else
		return 0;
}

#if 0
int main()
{
	int arr[] = { 1,3,5,9,0,12,13,41,22,10,51,6,8 };
	double brr[] = { 34.5,12.3,56.7,89.2,34.3,34.2 };
	int len1 = sizeof(arr) / sizeof(arr[0]);
	int len2 = sizeof(brr) / sizeof(brr[0]);
	qsort(arr, len1, sizeof(arr[0]), Cmp_int);
	qsort(brr, len2, sizeof(brr[0]), Cmp_double);
}
#endif
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
void：没有，可以修饰返回值（不可省略）或者参数列表（可以省略）
return：返回
static：静态，修饰变量或者函数
返回值：函数计算的结果通过返回值返回给函数的调用者
(参数列表)：a,b称为形式参数（形参），注意它已经有数据，不能再通过scanf读取
主函数中的参数称为实际参数（实参）
函数定义的内部不能定义另一个函数
函数结束，该函数的栈帧（分配的内存）系统才能回收
*/

/*
                           作用域                                生命周期                默认值
全局变量：    从定义开始，到整个文件结束，都能使用      程序运行创建，程序结束销毁         0
普通局部变量： 只在本函数内部使用（防止名字污染）      从进入函数创建，函数结束销毁      无效值
静态局部变量：         在函数内部使用                第一次进入函数创建，程序结束销毁      0
*/

/*
存储类别
auto（自动的）：默认的，在C语言中不再使用，C++中常见
statis（静态的）
register（寄存器的）：过时的，在C语言中不再使用，建议编译器对这个变量进行优化，这个变量会多次使用，建议将其加载到寄存器
extern（外部的）：不建议使用，引用外部符号（全局变量）
*/

//求两数之和

float Addf(float a, float b)
{
	return a + b;
}

#if 0 //预处理命令，值为1时启用
int main()
{
	float a = Addf(12.5f, 23.5f);
	printf("%f\n", a);
}
#endif

//统计一个数字中1的个数

int Count(int n)//n：需要统计的数字；返回值：返回1的个数
{
	int sum = 0;//统计1的个数
	while (n != 0)
	{
		if (n % 10 == 1)//得个位
			sum++;
		n /= 10;//丢弃个位
	}
	return sum;
}

//函数的递归调用：直接或间接调用函数本身
//三部分：1.边界条件 2.前进段 3.返回段

//递归求年龄

int Age(int n)//求第n的人的年龄
{
	if (n == 1)
		return 10;
	else
		return Age(n - 1) + 2;
}

//递归求阶乘

long long Fac(int n)//Fac(n)：求n的阶乘
{
	if (n == 0 || n == 1)
		return 1;
	return n * Fac(n - 1);
}

#if 0
int main()
{
	for (int i = 0; i < 10; i++)
		printf("%d!=%lld\n", i, Fac(i));
	return 0;
}
#endif

//汉诺塔：一定存在上面n-1个盘子在B上

void Hanoi(int n, char a, char b, char c)//n个盘子，a,b,c三个塔
{
	if (n == 1)
		printf("%c->%c\n", a, c);
	else
	{
		Hanoi(n - 1, a, c, b);//把上面的n-1个盘子，从a通过c移动到b
		printf("%c->%c\n", a, c);//把最下面的一个从a移动到c
		Hanoi(n - 1, b, a, c);//把b上面的n-1个盘子，从b通过a移动到c
	}
}

/*
求数组最大值

一维数组作为参数传递时的常见错误：
数组作为参数传递时，只传数组的起始地址，如
int Max(int arr[10])
中,程序不报错但结果错误，10没有任何意义

一定要传数组名和数组长度
*/

int Max(int arr[], int len)//arr：数组名；len：数组长度（在主函数中求，Max函数内部不能使用sizeof，因为arr本质上是指针，不是数组）
{
	int tmp = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (tmp < arr[i])
			tmp = arr[i];
	}
	return tmp;
}

//求数组平均值

double Avg(double arr[], int len)
{
	double sum = 0;
	for (int i = 0; i < len;i++)
		sum += arr[i];
	return sum / len;
}

//选择法排序

void SelectSort(int arr[], int len)
{
	int k;//最小值的下标
	int tmp;
	for (int i = 0; i < len - 1; i++)//排序的趟数
	{
		k = i;
		for (int j = i; j < len; j++)//找最小值
		{
			if (arr[j] < arr[k])//找到最小值，需要更新数据
				k = j;
		}
		tmp = arr[i];
		arr[i] = arr[k];
		arr[k] = tmp;
	}
}

//多维数组作为参数

void Show(int arr[][4], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

//Personal

#if 0

int Inarr(int arr[])
{
	int len = 0;
	char stop = ' ';
	printf("Input (Press / to end):\n");
	for (int i = 0; stop != '/'; i++)
	{
		scanf_s("%d", &arr[i]);
		scanf("%c", &stop);
		if (stop == '/')
		{
			len = i;
			break;
		}
	}
	return len;
}

void Outarr(int arr[], int len)
{
	printf("\nOutput:");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

#endif

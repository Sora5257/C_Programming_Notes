#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
数据类型：（字节数，数据范围）1字节=8位；1位(2进制)能表示两种情况(0,1)
字符：char(1)用于保存英文字符，不能保存中文，能表示2^8(256)种不同情况，见ASCII码表
整数：short(2)-2^16=65536
	  int(4,默认)-2^32=4294967296
	  long(4)
	  long long(8,C99增加(2000))-2^64=18446744073709551616
小数：float(4)
	  double(8,默认)有效数字更多，范围更广
	  long double（预留）
指针
自定义数据类型

x86运行如下
int main()
{
	printf("char%d\n", sizeof(char));
	printf("short%d\n", sizeof(short));
	printf("int%d\n", sizeof(int));
	printf("long%d\n", sizeof(long));
	printf("long long%d\n", sizeof(long long));
	printf("float%d\n", sizeof(float));
	printf("double%d\n", sizeof(double));
	return 0;
}
*/

/*
运算符
()：函数，提升优先级
逻辑谓词
真：非0，C99 true
假：0，C99 false
!：非
表达式1&&表达式2：并且(都为真，才为真)//注意短路现象，如果表达式1为假，表达式2不计算
表达式1||表达式2：或(只要有一个为真就为真）//注意短路现象，如果表达式1为真，表达式2不计算
< <= > >= 不能使用连续比较
++i：i的值自增1
++：前置，后置，单独使用i++，++i没有区别
--：前置，后置，同理
&变量：获取变量的地址
*指针变量：间接访问符，解引用
(类型)：强制类型转换
sizeof:求字节数
* / %求余(用于判断整除或控制范围)
+ -
表达式1 ? 表达式2 : 表达式3：如果表达式1为真，则执行表达式2，否则执行表达式3
==等号：判断左右是否相等 !=：不等号
=赋值：把右边的值赋值给左边
+= -= *= /= %= 复合赋值运算符(优先使用)
,：顺序求值
*/

/*int main()
{
	int a = 1;//定义int变量a并初始化为1
	for (int i = 2; i <= 5;++i)//循环因子 ++i：i的值自增1 替换：int a = 1 * 2 * 3 * 4 * 5;
	a = a * i;
	printf("%d\n",a);
	return 0;
}
*/

/*
double a = 10 / 3 //存放小数
double b = 10.0 / 3 //破坏整除：整除问题为整数除以整数
printf("%if\n%if\n",b); //%if：输出double小数
*/

//输出2000 - 2500之间的闰年

/*
int main()
{
	for (int year = 2000; year <= 2500; ++year)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			printf("%d是闰年\n", year);
	}
	return 0;
}
*/

/*
int main()
{
	if (!1)
		printf("真\n");
	else
		printf("假\n");
	return 0;

	//if(1)//真
	//if(0.5)//真
	//if("Ciallo")//真
	//if (!1)//假
}
*/

/*
int main()
{
	int n = 50 ;//判断n是否在0到10之间
	//if(0 < n < 10)错误的写法
	if(0 < n < 10 && n < 50)
		printf("真\n");
	else
		printf("假\n");
	return 0;
}
*/

/*
int main()
{
	int a = 10;
	int b = 20;
	if (++a || ++b)//被短路
		printf("true\n");
	else
		printf("false\n");
	printf("%d,%d\n",a, b);
	return 0;
}
*/

/*
int main()
{
	int i = 10;
	//int j = ++i;//前置++,11,11，先加i,再复制给j
	int j = i++;//后置++，一会儿再加(还是会加），11，10，考试时会出现
	printf("i=%d,j=%d\n", i, j);
	return 0;
}
*/

/*
int main()
{
	int a = 10;
	int* p = &a;//获得a的地址
	*p = 100;//间接地将a赋值为100
	printf("%d\n", *p);
	return 0;
}
*/

/*
int main()
{
	//char a = (char)200;//截断常量值
	double a = (double)10 / 3;
	printf("%lf\n", a);
	return 0;
}
*/

/*
int main()
{
	for (int i = 1; i < 100; i++)
	{
		printf("%d ", i);
		if (i % 10 == 0)
			printf("\n");
	}
	return 0;
}
*/

/*
int main()
{
	int a = 10;
	a = 100;
	int b = 20;
	a += 10;//a = a + 10 将a的值加10再复制给a
	a -= b;//a = a - b
	a *= 2;//a = a * 2
	a /= 5;//a = a / 5
	a %= 10;//a = a % 10
	return 0;
}
*/

//阿里巴巴笔试题 12、设x、y、t均为int型变量，则执行语句：t = 3;x = y =2;t = x ++ || ++ y;后，求变量t和y的值.

/*
int main()
{
	int t = 3;
	int x, y;
	x = y = 2;
	t = x++ || ++y;
	printf("%d,%d\n",t,y);//t=1(真->1)，y=2(被短路）
	return 0;
}
*/

//判断素数
/*
int main()
{
	int n;
	int i = 2;
	scanf("%d", &n);
	for (int i = 2; i < n; ++i);
	{
		if (n % i == 0)//找到能整除的数字
		{
			printf("%d不是素数\n", n);
			return 0;//提前退出该函数
		}
	}
	printf("%d是素数\n", n);
	return 0;
}
*/

/*素数的优化-缩短时长
如果n不是素数，则有 n = a*b ，不妨假设a <= b (1）
又n = n^1/2 * n^1/2 (2)
由(1)(2)知 a <= n^1/2 （3）
反证: a > n^1/2 ，b >= a > n^1/2 , a*b > n^1/2 * n^1/2 = n ，则原假设不成立
*/

/*
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			printf("%d不是素数\n", n);
				return 0;
		}
	}
	printf("%d是素数\n", n);
	return 0;
}
*/

/*小数求和

*/

int main()
{
	double sum = 0;//累加和
	int sign = 1;//符号
	int deno = 1;//分母
	for (int deno = 1; deno <= 100; deno++)
	{
		sum += sign * 1.0 / deno;//破坏整除
		sign *= -1;
	}
	printf("%lf\n", sum);
	return 0;
}
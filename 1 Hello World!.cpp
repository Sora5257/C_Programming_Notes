#include <stdio.h>//引用输入输出文件 std-standard i-input o-output

/*
块注释 行注释
文件类型
.c是c源文件
.cpp p-plus 是c++源文件，能够兼容c
*/

//C的第一个程序

int main()//main 主函数，程序的入口，有且只有一个 int 返回值
{
	printf("hello C\n");//printf是别人写好的函数，printf：向屏幕输出数据，\n：换行
	return 0;//返回0（表示程序正常）
}

/*
int main()
{
	int a = 123;//定义一个int变量a并赋值为123
	int b = 456;
	int sum = a + b;
	printf("%d\n", sum);//%d：格式化符，输出整数

		return 0;
}
*/

/*
int main()
{
	int a;
	//scanf("%d", &a);//从键盘读取数据 报错不安全函数或变量：使用scanf_s
	scanf_s("%d", &a);
	printf("刚才读取的值：%d\n",a);
	return 0;
}
*/

/*
int main()
{
	int a, b, c;
	scanf_s("%d,%d", &a, &b);//读取数据容易失败，数据不对首先怀疑scanf，验证：用printf
	printf("测试刚才输入的数据：%d,%d\n",a,b);
	if (a >= b)
		c = a;
	else
		c = b;
	printf("最大值：%d\n", c);
	return 0;
}
*/

/*
int main()
{
	printf("请在下面输入两个数字，格式例为：114,514");
	int Max(int x, int y);
	int a, b;
	scanf_s("%d,%d",&a,&b);
	printf("测试输入的数据：%d,%d\n", a, b);
	int c = Max(a, b);//c保存Max函数的返回值
	printf("最大值：%d\n", c);
	return 0;
}

int Max(int x, int y)
{
	//return x >= y ? x : y;简明写法
	if (x >= y)
		return x;
	else
		return y;
}//也可以把 int Max 放在主函数前让其编译
*/
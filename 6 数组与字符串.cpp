#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/*
数组：多个同类型的数据
定义：类型 数组名[长度];
[数字]：在定义时表示数组长度（前面有类型），使用时表示下标（前面没有类型）
下标从0开始编号，下标可以使用变量
初始化：在定义的同时，赋值；只初始化一部分，剩余的值为0

vs2022中，数组长度不能为变量，但c99中可以（编译器不一定完全遵循c标准）
一维数组可以通过赋值推导长度

printf("%d\n",arr);//输出的是arr的地址
*/

/*
二维数组
定义：类型 数组名[行][列];
初始化：在定义的同时，赋值（行优先）；只初始化一部分，剩余的值为0
访问元素：通过行、列下标访问

二维数组可以通过赋值推导行度（只能省略最高维）
*/

/*
字符数组
定义：char 数组名[长度];
字符串：用""包括的字符序列，可以是0个及以上的字符.字符串末尾有一个隐藏的'\0'作为结尾标记.
字符串的两种形式：1.用""包括；2.有'\0'的字符数组.

const：不允许修改（其修饰的）内容
int a = 10;//a没有任何限制，可读可写
const int ca = 10;//ca只读，不允许修改ca的值

基本类型对于const是透明的. e.g. const int ca = 10; == int const ca = 10;
const只能修饰“直接”右边. e.g. const int* p = &a;中，p3可以修改，*p3不能修改
*/

/*
int main()
{
	char str1[10];//不是字符串，没有初始化，随机值
	char str2[10] = { 'a','b','c' };//是字符串，初始化一部分，剩余部分为0
	char str3[] = { 'a','b','c' };//不是字符串，长度为3
	char str4[10] = "abc";//是字符串
	char str5[] = "abc";//是字符串
	const char* str6 = "abc";//字符串常量，不是字符数组
	printf("%d,%d,%d,%d\n", false, 0, '\0', NULL);//0的表现形式
	return 0;
}
*/

/*
字符串处理函数
puts：输出一个字符串，并自动换行 e.g. puts(str);
gets：输入一个字符串（已经被废除，不安全）
fgets：输入一个字符串 e.g. fgets(str2, 10, stdin);//stdin：标准输入，即键盘
scanf_s：读取字符或者字符串（必须说明大小） e.g. scanf_s("%s", str, 10);
strlen：求字符串的长度 e.g. strlen(str1);//注意和sizeof区分
strlwr：字符串大写转小写（已经被废除）
strupr：字符串小写转大写（已经被废除）
strcpy：字符串拷贝 e.g. strcpy(str2, str1);//把str1的内容复制给str2
strcat：字符串连结 e.g. strcat(str1, str2);//把str2连结到str1的后面（第一个字符串的长度必须足够）
strcmp：字符串比较 e.g. int n = strcmp(str1, str2);
（str1 < str2时，n返回<0的值；str1 = str2时，n返回0；str1 > str2时，n返回>0的值）
从头到尾依次比较每个字符，直到分出大小或两个字符串结束
由于逻辑错误，不能直接使用 < = > 等运算符
*/

//更改数组中的值，要通过下标访问

/*
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	arr[2] = 10;//把arr数组2下标（第3个数据）的值赋值为10
	return 0;
}
*/

//逆序输出一数组中的元素，并求数组长度.

/*
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%lld\n", sizeof(arr) / sizeof(arr[10]));//求数组长度（注意条件，arr不能是形参）
	return 0;
}
*/

//求Fibonacci数列.

/*
int main()
{
	int arr[40] = { 1,1 };//保存Fibonacci数列前40项的值
	for (int i = 2; i < sizeof(arr) / sizeof(arr[0]); i++)
		arr[i] = arr[i - 2] + arr[i - 1];
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	return 0;
}
*/

//按从小到大的顺序排列数据.
//冒泡排序：从头到尾，两两比较，大的往后，小的往前

/*
int main()
{
	int arr[] = { 3,7,9,0,1,23,45,6,12,25,68,79,80,55 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int tmp;
	for (int i = 0; i < len - 1; ++i)//循环的趟数
	{
		for (int j = 0; j + 1 < len - i; ++j)//每一趟需要从头到“尾”（不包括一句有序的数据）遍历
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
*/

//转制矩阵（行列互换）.

/*
int main()
{
	int a[2][3] = { {1,2,3},{4,5,6} };
	int b[3][2];
	for (int i = 0; i < 2; i++)//行
	{
		for (int j = 0; j < 3; j++)//列
		{
			b[j][i] = a[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/

//输出一矩阵中最大值元素及其行列下标.

/*
int main()
{
	int a[3][4] = { 3,6,8,9,5,12,7,34,6,0,13,25 };
	int max = a[0][0];//最大值
	int row = 0;//最大值行号
	int col = 0;//最大值列号
	for (int i = 0; i < 3; i++)//遍历二维数组，左闭右开
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] > max)//更新数据
			{
				max = a[i][j];
				row = i;
				col = j;
			}
		}
	}
	printf("在%d行，%d列的值%d最大，%d\n", row, col, max, a[row][col]);
	return 0;
}
*/

//输出不是字符串的字符数组

/*
int main()
{
	char str[] = { 'a','b','c','d','e' };
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); ++i)
		putchar(str[i]);
	return 0;
}
*/

//字符数组的输入

/*
int main()
{
	char c[6];
	for (int i = 0; i < 6; ++i)
		scanf("%c", &c[i]);//可用getchar替代
	for (int i = 0; i < 6; ++i)
		printf("%c", c[i]);//可用putchar替代
	return 0;
}
*/

//字符串的输入与输出

/*
int main()
{
	char c[6];//只能放5个字符，还有的隐藏的'\0'
	scanf("%s", &c);
	printf("%s", c);
	return 0;
}
*/

//strlwr的替代函数

void Mystrlwr(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)//遍历字符串
	{
		if (isupper(str[i]))//判断是否为大写字母
		{
			str[i] = tolower(str[i]);//大写转小写
		}
	}
}

//统计单词数量

/*
int main()
{
	char str[100];
	fgets(str,100,stdin);
	int n = 0;//统计单词个数
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i])&&!isalpha(str[i+1]))
			n++;
	}
	printf("%d\n", n);
	return 0;
}
*/

//找出最大字符串

/*
int main()
{
	char str[3][20];//假定每个字符串的长度不超过19
	char max[20]=" ";//保存最大的字符串
	int i;
	for (i = 0; i < 3; i++)//从键盘获取三个字符串
		fgets(str[i], 20, stdin);

	for (i = 0; i < 3; i++)//依次比较大小
	{
		if (strcmp(max, str[i]) < 0)
		{
			strcpy(max, str[i]);
		}
	}
	printf("最大的字符串=%s\n", max);
	return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
//单分支：如果表达式1为真，执行语句块1.

if(表达式1)
{
    语句块1
}

//双分支：如果表达式1为真，则执行语句块1；否则执行语句块2.

if(表达式1)
{
    语句块1
}
else
{
    语句块2
}

//多分支：

if(表达式1)
{
    语句块1
}
else if(表达式2)
{
    语句块2
}
//……
else
{
    语句块n
}

//switch语句

switch(整型表达式)//char,bool,int,short,long,long long,枚举
{
  case 常量表达式1://标签必须唯一
    语句块1
    break;
  case 常量表达式2:
    语句块2
    break;
  ……
  case 常量表达式n:
    语句块n
    break;
  default://默认，其他，可以不写
    语句块n+1
    break;
 }
 如何进：当整型表达式和其中的一个常量表达式（标签）相同则进入，相当于if语句中的默认加等号
 如何出：当遇到break或者整个switch结束
*/

//由小到大输出两个数字

/*
int main()
{
    double a, b;
    scanf("%lf,%lf", &a, &b);
    if (a > b)
    {
        printf("%lf,%lf\n", b, a);
    }
    else
    {
        printf("%lf,%lf\n", a, b);
    }
    return 0;
}
*/

//由小到大输出三个数字

/*
int main()
{
    double a, b, c;
    scanf("%lf,%lf,%lf", &a, &b, &c);//a保存最小值，b保存第二小的值，c保存最大值
    double tmp;
    if (a > b)//交换，使a是a,b的最大值
    {
        tmp = a;//右复制给左
        a = b;
        b = tmp;
    }if (a > c)
    {
        tmp = a;
        a = c;
        c = tmp;
    }
    if (b > c)
    {
        tmp = b;
        b = c;
        c = tmp;
    }
    printf("%lf,%lf,%lf\n", a, b, c);
    return 0;
}
*/

//求方程 ax^2 + bx + c = 0 的根.a,b,c由键盘输入， b^2 - 4ac 的值需在程序中判别.

/*
int main()
{
    int a, b, c;
    scanf("%d,%d,%d", &a, &b, &c);
    int d = b * b - 4 * a * c;
    double x1, x2;
    if (a == 0)
    {
        x1 = -1.0 * c / b;
        printf("%lf\n",x1);
    }
    else if (d < 0)
    {
        printf("无实根\n");
    }
    else if (d == 0)
    {
        x1 = x2 = -b / (2.0 * a);
        printf("两个相同的根：%lf\n", x1);
    }
    else//d > 0
    {
        x1 = (-b + sqrt(d)) / 2 * a;
        x1 = (-b - sqrt(d)) / 2 * a;
    }
    return 0;
}
*/

//有一阶跃函数：x < 0 , y = -1 ; x = 0 , y = 0 ; x > 0 , y = 1 .用程序表示.

/*
int main()
{
    int x;
    scanf("%d", &x);
    int y;
    if (x < 0)
        y = 1;
    else if (x == 0)
        y = 0;
    else
        y = 1;
    printf("%d\n", y);
    return 0;
}
*/

/*
计算运费，折扣表如下

0%：s<250
2%：250<=s<500
5%：500<=s<1000
8%：1000<=s<2000
10%：2000<=s<3000
15%：s>=3000
（s为运输距离）
*/

/*
int main()
{
    int s;//运输距离
    scanf("%d", &s);
    double a = 1;//费率
    switch (s / 250)// 200/250 -> 0
    {
    case 0:
        a = 1;
        break;
    case 1:
        a = 0.98;
        break;
    case 3:
        a = 0.95;
        break;
    case 4:
    case 5:
    case 6:
    case 7://……
        a = 0.92;
        break;

    default:
        break;
    }
    return 0;
}
*/
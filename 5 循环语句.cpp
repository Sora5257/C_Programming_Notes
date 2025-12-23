#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
for（表达式1;表达式2;表达式3）
{
    语句块1
}

表达式1：初始化循环因子，最早被执行，有且执行一次
表达式2：判断，为真循环继续，为假循环结束
表达式3：步进，修改循环因子的值，在语句块1之后执行
三个表达式都可省略（要留分号;）
*/

/*
while(表达式1）;
{
   语句块1
}

表达式1为真循环继续，否则结束，不能省略
*/

/*
do
{
  语句块1
}while(表达式1）;

表达式1为真循环继续，否则结束，不能省略
*/

/*
break：跳出一层循环
continue：提前结束本次循环，直接进入下一次循环
*/

//1000人参加捐款，总数达10万元时结束，统计捐款人数与平均捐款的数目.

/*
int main()
{
    int sum = 0;//捐款数目
    int n;//每次捐款的数额
    int i;//i捐款人数
    for (i = 1; i <= 1000; ++i)
    {
        scanf("%d", &n);//模拟捐款
        sum += n;//统计捐款数目
        if (sum >= 100000)
            break;//跳出一层循环
    }
    printf("人数=%d，平均数额=%.2lf\n", i, (double)sum / i);
    return 0;
}
*/

//输出一个5*4矩阵.

/*
int main()
{
    for (int i = 1; i <= 4; ++i)//行
    {
        for (int j = 1; j <= 5; ++j)//列
        {
            printf("%-3d ", i * j);//3d：每个数字占三格，-表示左对齐
        }
        printf("\n");
    }
    return 0;
}
*/

//用公式 PI/4 ≈ 1 - 1/3 + 1/5 - 1/7 + …… 求PI的近似值，直到发现某一项的绝对值小于10^-6为止(该项不累加)

/*
int main()
{
    double sum = 0;
    int flg = 1;//符号，另：fabs求绝对值
    for (int i = 1; i < 1000000; i += 2)//i为分母，10^-6用1e-6表示.
    {
        sum += flg * 1.0 / i;
        flg *= -1;
    }
    printf("PI=%lf\n", sum * 4);
    return 0;
}
*/

//求Fibonacci数列的前40个数，即1,1,2,3,5,8,13,……

/*
int main()
{
    int f1 = 1;
    int f2 = 1;
    int f3 = 1;
    printf("1 1 ");
    for (int i = 3; i <= 40; i++)
    {
        f3 = f1 + f2;
        printf("%d ", f3);
        f1 = f2;
        f2 = f3;
    }
    return 0;
}
*/
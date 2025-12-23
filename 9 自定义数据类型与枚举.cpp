#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
用户自定义数据类型

自定义：
struct 类型名
{
    成员列表
};//结构体定义（声明）完成，该类型和基本类型一致

结构体的普通变量，通过"."访问其成员
结构体的指针变量，通过"->"访问其成员

结构体作为参数传递，总是传指针（节约空间）
*/

/*
typedef：类型定义，它的作用是把一个旧类型名起一个新名字
将复杂类型起一个简单的名字

typedef struct Student Student;//Student即struct Student

typedef struct Student
{
//...
}Student;

//等价，目的：在以后的使用中省略struct
*/

struct Date
{
    int year;
    int month;
    int day;
    //struct A* c;//在数据结构中大量应用
};

struct Student
{
    int num;//学号
    char name[20];
    char sex[10];
    int age;
    struct Date birthday;
    char addr[100];
    float score;
};

void Show1(const struct Student* ps)
{
    printf("%s,%d,%.1lf\n", ps->name, ps->age, ps->score);
}

void Show2(const struct Student* arr, int len)
{
    for (int i = 0; i < len; i++)
        //printf("%d,%s,%.1lf\n", arr[i].num, arr[i].name, arr[i].score);
        //printf("%d,%s,%.1lf\n", (arr + i)->num, (arr + i)->name, (arr + i)->score);//等价
        printf("%d,%s,%.1lf\n", arr->num, arr->name, arr->score); arr++;//等价
}

#if 0
int main()
{
    struct Student stu0, stu2;//定义一个struct Student类型的变量stu1，没有初始化
    struct Student stu1 = { 000001,"Test1","M",18,2000,1,1,"Chengdu",90};
    struct Student arr[2] = { {000002,"Test2",85},{000003,"Test3",95} };//定义结构体数组
    struct Student* p = &stu1;//定义结构体指针变量
    stu1.age = 25;//修改变量
    (*p).score = 95;
    p->score = 95;//上下等价
    scanf_s("%d,%s,%f", &stu2.num, &stu2.name, &stu2.score);
    printf("%d,%s,%s,%s\n", stu1.num, stu1.name, stu1.sex, stu1.addr);
    Show1(&stu1);
    return 0;
}
#endif

/*
枚举
如果一个变量的取值只有几种情况，可以使用枚举，用于替代C语言中的宏
枚举的大小为int(4)
定义：enum 枚举类型名 { 枚举列表 };

枚举元素默认从0开始，后面的值依次增1
枚举值是常量，只有在定义时可以修改，后面的值是,前面的值+1，以后不能修改
枚举值可以进行比较
*/

enum Weekday { mon, tue, wed, thr, fri, sat, sun };

//按成绩对学生进行排序（利用qsort函数）

int Cmp_stu_sco(const void* vp1, const void* vp2)//比较学生的分数
{
    double tmp = ((struct Student*)vp1)->score - ((struct Student*)vp2)->score;
    if (tmp > 0)
        return 1;
    else if (tmp < 0)
        return -1;
    else
        return 0;
}

void ScoreSort(struct Student* arr, int len)
{
    qsort(arr, len, sizeof(struct Student), Cmp_stu_sco);
}

//输出平均分最高的学生

struct Student1
{
    int num;
    char name[20];
    float score[3];
    float avg;
};

void Input1(struct Student1* arr, int n)
{
    printf("请输入%d个学生的信息：\n", n);
    printf("学号，姓名，科目1成绩，科目2成绩，科目3成绩\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d,%s,%f,%f,%f", &arr[i].num, &arr[i].name, &arr[i].score[0], &arr[i].score[1], &arr[i].score[2]);
        arr[i].avg = (arr[i].score[0] + arr[i].score[1] + arr[i].score[2]) / 3;
    }
}

void ShowMax(const struct Student1* arr, int n)
{
    int max = 0;//平均分最高的学生下标
    float avg = arr[0].avg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].avg > avg)
        {
            avg = arr[i].avg;
            max = i;
        }
    }
    // \称为续行符
    printf("平均分最高的学生信息为：\n \
学号%d,姓名%s,成绩1=%.1f,成绩2=%.1f,成绩3=%.1f,平均分=%.1f\n", arr[max].num, arr[max].name, arr[max].score[0], arr[max].score[1], arr[max].score[2], arr[max].avg);
}

#if 0
int main()
{
    struct Student1 arr[5]; 
    int len = sizeof(arr) / sizeof(arr[0]);
    Input1(arr, len);
    ShowMax(arr, len);
    return 0;
}
#endif

//枚举的应用

enum Status{ok,out_range,no_mem,busy,unknown};//状态类型（成功，越界，内存不足，繁忙，未知错误）


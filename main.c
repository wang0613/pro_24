#include <stdio.h>

//p:56 （1）结构体传参
struct student {
    int a;
    char c;
    double d;
};

//结构体传参 可以传地址和结构体本身
void init(struct student *stu) {
    stu->a = 10;
    stu->c = 'd';
    stu->d = 10.34;

}

//tmp是student的一份临时copy
void print(struct student tmp) { //传值

    printf("%d\n", tmp.a);
    printf("%c\n", tmp.c);
    printf("%lf\n", tmp.d);

}

void print2(const struct student *stu) { //传址

    printf("%d\n", stu->a);
    printf("%c\n", stu->c);
    printf("%lf\n", stu->d);

}

int main1() {

    struct student stu;
    init(&stu);

//    print(stu);
    print2(&stu);  //传递地址 功能更加强大(print压栈开销更大)
    return 0;
}

//（2）位段：位段的声明和结构是类似的，有两个不同
//1:位段的成员必须是 int , unsigned int ,signed int
//2:位段的成员 后面有一个冒号和一个数字
struct A {
    //位段： 二级制位
    int a: 2;
    int b: 5;
    int c: 10;
    int d: 30;  //位段是不能大于一块内存   不能>32

};
//47bit - 6个字节
//位段内存分配的规则
//每一次开辟4个字节(32bit)，如果当前位段不够存，则会丢掉空间 再开辟4个字节
struct S {
    char a: 3;
    char b: 4;
    char c: 5;
    char d: 4;
};

int main2() {
    struct A a;
    struct S s = {0};

    s.a = 10;
    s.b = 20;
    s.c = 3;
    s.d = 4;

    //位段
//    printf("%d\n", sizeof(a)); //8
    printf("%d\n", sizeof(s)); //3
}

//（3）： 枚举
enum Sex {
    //枚举的可能取值
    MALE,
    FEMALE,
    SECRET
};
enum Color {
    RED, //枚举常量 默认初始值0
    YELLOW,
    BLUE = 3 //赋予常量初始值
};
//#define RED 0
//#define GREEN 1
//#define BLUE 2

//枚举的优点？
//1：增加代码的可读性和可维护性
//2:和#define定义的标识符比较 枚举具有类型检查，更加严谨
//3: 防止了命名污染
//4: 便于调试
//5: 使用方便，一次可以定义多个变量
int main3() {
//    enum Sex s = MALE;
//    enum Color c = 1; // error int无法转换为enum
//    s = FEMALE;

//    printf("%d\n",sizeof(s)); //4 一个整形的大小
//      RED  = 2;// error
//      BLUE  = 2;// error


    printf("%d %d %d ", RED, YELLOW, BLUE);  // 0 1 3
    return 0;
}
//联合-联合体(共同体) ：也是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，特征就是这些成员公用同一块空间

union un {
    char c; //1
    int a;
};

int main4() {
    union un un;
    printf("%d\n", sizeof(un)); // 4

    // c 和 a 公用一块空间 所以：联合体空间的大小 至少是最大成员的大小
    printf("%p\n", &un); //相同 000000808bdffd4c
    printf("%p\n", &(un.c));
    printf("%p\n", &(un.a));
}

//int check_sys()
//{
//    int a = 1;
//    //返回1则为小端
//    return *(char*)&a;
//}


int check_sys()
{
    union
    {
        //因为公用一块内存，所以int的首字节和char公用一块， 拿出看c就可以
        char c;
        int i;
    }s;
    s.i = 1;

    return s.c; //返回1 就是小段 0就是大端
}

int main() {
    int a = 1;
    //低地址 ---- 高地址

    //..[][][11][22][33][44][][] 大端存储模式
    //..[][][44][33][22][11][][] 小段存储模式 (小小小)
    //讨论一个数据，存放在内存中的字节顺序
    //大小端字节序问题
    char *c = (char*) &a;
    if (*c == 1) {
        printf("小段存储");
    } else {
        printf("大端存储");
    }
}

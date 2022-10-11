#include <stdio.h>

//p:56 ��1���ṹ�崫��
struct student {
    int a;
    char c;
    double d;
};

//�ṹ�崫�� ���Դ���ַ�ͽṹ�屾��
void init(struct student *stu) {
    stu->a = 10;
    stu->c = 'd';
    stu->d = 10.34;

}

//tmp��student��һ����ʱcopy
void print(struct student tmp) { //��ֵ

    printf("%d\n", tmp.a);
    printf("%c\n", tmp.c);
    printf("%lf\n", tmp.d);

}

void print2(const struct student *stu) { //��ַ

    printf("%d\n", stu->a);
    printf("%c\n", stu->c);
    printf("%lf\n", stu->d);

}

int main1() {

    struct student stu;
    init(&stu);

//    print(stu);
    print2(&stu);  //���ݵ�ַ ���ܸ���ǿ��(printѹջ��������)
    return 0;
}

//��2��λ�Σ�λ�ε������ͽṹ�����Ƶģ���������ͬ
//1:λ�εĳ�Ա������ int , unsigned int ,signed int
//2:λ�εĳ�Ա ������һ��ð�ź�һ������
struct A {
    //λ�Σ� ������λ
    int a: 2;
    int b: 5;
    int c: 10;
    int d: 30;  //λ���ǲ��ܴ���һ���ڴ�   ����>32

};
//47bit - 6���ֽ�
//λ���ڴ����Ĺ���
//ÿһ�ο���4���ֽ�(32bit)�������ǰλ�β����棬��ᶪ���ռ� �ٿ���4���ֽ�
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

    //λ��
//    printf("%d\n", sizeof(a)); //8
    printf("%d\n", sizeof(s)); //3
}

//��3���� ö��
enum Sex {
    //ö�ٵĿ���ȡֵ
    MALE,
    FEMALE,
    SECRET
};
enum Color {
    RED, //ö�ٳ��� Ĭ�ϳ�ʼֵ0
    YELLOW,
    BLUE = 3 //���賣����ʼֵ
};
//#define RED 0
//#define GREEN 1
//#define BLUE 2

//ö�ٵ��ŵ㣿
//1�����Ӵ���Ŀɶ��ԺͿ�ά����
//2:��#define����ı�ʶ���Ƚ� ö�پ������ͼ�飬�����Ͻ�
//3: ��ֹ��������Ⱦ
//4: ���ڵ���
//5: ʹ�÷��㣬һ�ο��Զ���������
int main3() {
//    enum Sex s = MALE;
//    enum Color c = 1; // error int�޷�ת��Ϊenum
//    s = FEMALE;

//    printf("%d\n",sizeof(s)); //4 һ�����εĴ�С
//      RED  = 2;// error
//      BLUE  = 2;// error


    printf("%d %d %d ", RED, YELLOW, BLUE);  // 0 1 3
    return 0;
}
//����-������(��ͬ��) ��Ҳ��һ��������Զ������ͣ��������Ͷ���ı���Ҳ����һϵ�еĳ�Ա������������Щ��Ա����ͬһ��ռ�

union un {
    char c; //1
    int a;
};

int main4() {
    union un un;
    printf("%d\n", sizeof(un)); // 4

    // c �� a ����һ��ռ� ���ԣ�������ռ�Ĵ�С ����������Ա�Ĵ�С
    printf("%p\n", &un); //��ͬ 000000808bdffd4c
    printf("%p\n", &(un.c));
    printf("%p\n", &(un.a));
}

//int check_sys()
//{
//    int a = 1;
//    //����1��ΪС��
//    return *(char*)&a;
//}


int check_sys()
{
    union
    {
        //��Ϊ����һ���ڴ棬����int�����ֽں�char����һ�飬 �ó���c�Ϳ���
        char c;
        int i;
    }s;
    s.i = 1;

    return s.c; //����1 ����С�� 0���Ǵ��
}

int main() {
    int a = 1;
    //�͵�ַ ---- �ߵ�ַ

    //..[][][11][22][33][44][][] ��˴洢ģʽ
    //..[][][44][33][22][11][][] С�δ洢ģʽ (ССС)
    //����һ�����ݣ�������ڴ��е��ֽ�˳��
    //��С���ֽ�������
    char *c = (char*) &a;
    if (*c == 1) {
        printf("С�δ洢");
    } else {
        printf("��˴洢");
    }
}

#include <stdio.h>

int main(){
    //-------------单独指针------------//
    /* '*'的两种含义：
    1.前面有类型，定义时候：表明后面变量是指针
    2.使用时候：表示取值，取指针指向的内存空间的值
    */
    int a = 10; 
    int *p; //变量名还是p，但是p只能存放地址（int *p = &a）
    p = &a; //把a的地址赋给p
    *p = 100; //把100赋值给p地址的变量
    printf("a的地址:%p\n",&a);
    printf("%d\n",a);
    printf("p:%p\n",p);
    printf("%u\n",sizeof(int*)); //指针的字节都是8
    printf("%u\n",sizeof(char*));

    char b = 't';
    char *p1; //规则:指针的类型一定要和它指向的变量类型一致
    p1 = &b; //因为编译器靠类型决定一次读/写多少字节。
    // printf("p+1:%p\n",p+1);
    // printf("p1+1:%p\n",p1+1);//char*和int*的步长是不一样的
    printf("%c\n",b);
    printf("b的地址:%p\n",&b);
    printf("p1:%p\n",p1);

    //------------指针做函数参数------------//
    int num_1 = 1,num_2 = 2;
    return 0;
}
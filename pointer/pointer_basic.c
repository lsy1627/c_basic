#include <stdio.h>
#include <stdlib.h>

//定义一个函数，拷贝字符串
void mystrcpy(char *dest,const char *src){
    while(*src != '\0'){
        *dest++ = *src++;
    }
    *dest = '\0';
}

//定义一个函数，交换两个整数的值
void exchange(int *p1,int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


//回调函数：把函数名作为另一个函数的参数
//作用：修改函数的作用
int less(int x,int y){
    return (x>y) ? 1 : 0;
}
int greater(int x,int y){
    return (x<y) ? 1 : 0;
}
//冒泡排序
void sort(int *a,int len,int (*p)(int,int)){
    int i,j;
    for(i = 0;i < len-1;i++){
        for(j =0;j<len - i -1;j++){
            if(p(a[j] , a[j+1])){
                int num = a[j];
                a[j] = a[j+1];
                a[j+1] = num; 
            }
        }
    }
}

int main(){
    //----------------------------单独指针------------------------//
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

    
    //---------------------------指针运算--------------------------//
    int c = 3,y=0,*p2=&c;
    int x = 0,z = 0;
    y = *p2 + 1; //y=4
    printf("p2:%p\n",p2); 
    printf("y:%d\n",y);
    x = ++*p2; //++(*p2)；对 *p2（即 c）自增，p2 不动
    printf("x:%d\n",x);
    z = *p2++; //*(p2++),p2指向c的下一个地址;*对旧值解引用→读 4
    printf("p2:%p\n",p2); 
    printf("z:%d\n",z);


    //-------------------------空指针和野指针-----------------------//
    int *p3 = NULL; //空指针
    // int *p4; //野指针，未初始化
    //如何合法地使用指针：
    //1.系统分配的内存空间
        //int a;
        // int *p = &a;
    //2.用户申请的内存空间（堆内存）
        //malloc，本身返回的是void*，所以要强制类型转换
        //int *p = (int*)malloc(sizeof(int));
        //释放内存，如果不释放，会造成内存泄漏
        //free(p);
        //p = NULL; //释放后，指针置空，避免野指针


    //------------------------指针做函数参数-----------------------//
    int num_1 = 1,num_2 = 2;
    exchange(&num_1,&num_2); //交换两个字符串
    printf("num_1:%d\n",num_1);
    printf("num_2:%d\n",num_2);

    char s1[32] = "hello";
    char s2[32] = {0};
    mystrcpy(s2,s1); //把字符串拷贝
    printf("s2:%s\n",s2);

    //------------------------指针和数组---------------------------//
    /*1.数组和指针的区别
    *eg:char str[32] = "helloworld";
    *   str ++;是错误的，str一直是数组首地址不会进行改变
    * char *p = "helloworld";
    * sizeof(str) = 32;
    * sizoef(p) = 8; 存地址的8字节
    */
    //2.数组作为参数传过来后，变成指针


    //------------------------指针数组----------------------//
    char *str[] = {"hello","world"};
    printf("%s\n",str[0]);


    //-----------------------指针和函数---------------------//
    //1.函数指针：int (*p)()
    void (*p4)(int *, int *);   //定义函数指针，参数类型与 exchange 一致
    p4 = exchange;
    p4(&num_1,&num_2);  //通过函数指针调用函数 等价于 exchange()
    printf("num_1:%d\n",num_1);
    printf("num_2:%d\n",num_2);

    //指针函数：返回值是指针的函数 int *p()
    //注意：不能返回局部变量的地址


    //------------------------回调函数----------------------//
    int *str1 = (int*)malloc(10 * sizeof(int));
    printf("please put in a 10 numbers:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &str1[i]);
    }
    sort (str1,10,greater);
    for(int i = 0; i < 10; i++)
        printf("%d ", str1[i]);         
    printf("\n");
    free(str1);
    return 0;
}
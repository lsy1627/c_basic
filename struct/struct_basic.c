#include <stdio.h>

//---------结构体的嵌套(把生日嵌套进学生信息里面)---------//
typedef struct
{
    int year;
    int month;
    int day;
} Birthday;

//-----------------------结构体声明---------------------//
// 1.标准结构体
struct Student
{
    int id;            // 学号
    int age;           // 年龄
    char *name;        // 姓名
    Birthday birthday; // 嵌套生日的结构体
    //.......
};

// 2.匿名结构体
//  struct {
//      int x;
//      int y;
//  } a, b;                 // 类型名丢了，只能用 a、b 这两个变量
//  // 之后想再声明 c 就不行了，因为类型没名字

// 3.typedef起别名 ！！！！！！！
// 与标准结构体的区别:后续在调用时候不用再加上struct关键字
typedef struct Boy
{ // 此处的Boy可以省略不写
    int age;
    //......
} Boy;

int main()
{
    // 标准结构体声明
    struct Student stu2;
    // 方式一：
    stu2.id = 17;
    stu2.age = 19;
    // 方式二：
    struct Student stu1 = {.id = 1, .name = "lsy", .age = 18, 
        .birthday = {.year = 2007, .month = 11, .day = 9}};

    printf("name:%s,id:%d,old:%d,birthday:%d-%d-%d\n",stu1.name,stu1.id,stu1.age,
        stu1.birthday.year,stu1.birthday.month,stu1.birthday.day);
    
        // 嵌套的结构体中的声明
    stu1.birthday.year = 2007; // 需要进行多层的访问

    // typedef结构体声明
    Boy b1;
    b1.age = 10086;

    return 0;
}
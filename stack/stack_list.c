#include<stdio.h>
#include<stdlib.h>

//2.1栈的链式结构实现
typedef int ElemType;

typedef struct Stack{
    ElemType data;
    struct Stack* next;
}Stack;

//2.2栈的链式结构-初始化
Stack *initList()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s -> data = 0;
    s -> next = NULL;
    return s;
}

//2.3栈的链式结构-判断栈是否为空
//就是判断头节点->next 是否为 NULL

//2.4栈的链式结构-进栈/压栈
//就是头插法

//2.5栈的链式结构-出栈
//就是删掉头节点的后继

//2.6栈的链式结构-获取栈顶元素
//就是获得头节点的后继
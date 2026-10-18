#include<stdio.h>
#include<stdlib.h>

//1.1栈的顺序结构实现
#define MAXSIZE 100
typedef int ElemType;

typedef struct Stack{
    ElemType data[MAXSIZE];
    int top; //栈顶下标（栈顶指针）
}Stack;

//1.2栈的顺序结构-初始化
void initStack(Stack* s)
{
    s->top = -1; //和链表的头节点类似,不计入数据中,又因为0的下标不存在
}

//1.3栈的顺序结构-判断栈是否为空
int isEmpty(Stack* s)
{
    if(s->top == -1)
    {
        printf("is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//1.4栈的顺序结构-进栈/压栈
int push(Stack* s,ElemType a)
{
    //判断满了吗
    if(s->top >= MAXSIZE - 1)
    {
        printf("fulled\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = a;
    return 1;
}

//1.5栈的顺序结构-出栈（覆盖）
//a用来接出栈的元素
ElemType pop(Stack* s,ElemType* a)
{
    if(s->top == -1)
    {
        printf("is empty\n");
        return 0;
    }
    *a = s->data[s->top];
    s->top--;
    return 1;
}

//1.6栈的顺序结构-获取栈顶元素
int getTop(Stack* s,ElemType* a)
{
    if(s->top == -1)
    {
        printf("is empty\n");
        return 0;
    }
    *a = s->data[s->top];
    return 1;
}

//1.7栈的顺序结构-动态内存分配
//其实和顺序表很类似
typedef struct StackMem{
    ElemType* data;
    int top;
}StackMem;

Stack* initStackMem()
{
    StackMem* s = (StackMem*)malloc(sizeof(StackMem));
    s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
}

//遍历（和之前顺序表一样）
void listElem(Stack *stack)
{
    for(int i = 0; i<=stack->top;i++)
    {
        printf("%d ",stack->data[i]);
    }
    printf("\n");
}

int main()
{
    //初始化
    Stack stack;
    initStack(&stack);

    //压栈
    push(&stack,5);
    push(&stack,4);
    push(&stack,3);
    push(&stack,2);
    push(&stack,1);

    //判断栈是否为空
    int ref = isEmpty(&stack);
    if(ref == 0)
    {
        printf("the stack is right\n");
    }
    else
    {
        return 0;
    }
    listElem(&stack);

    //出栈
    ElemType out;
    pop(&stack,&out); 
    printf("the out Elem:%d\n",out);
    pop(&stack,&out); 
    printf("the out Elem:%d\n",out);
    pop(&stack,&out); 
    printf("the out Elem:%d\n",out);
    pop(&stack,&out); 
    printf("the out Elem:%d\n",out);
    pop(&stack,&out); 
    printf("the out Elem:%d\n",out);
}
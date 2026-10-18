#include<stdio.h>
#include<stdlib.h>

/*
*   [ ] [ ] [ ] [ ]
*    |   |   |   |
*  front        rear
*入队时候front保持不动，rear作为下标跟着移动；等到出队时候rear不动，front
*跟着移动
*/


//1.1队列的顺序结构实现
#define MAXSIZE 100
typedef int ElemType;

typedef struct Que{
    ElemType data[MAXSIZE];
    int front; //队头
    int rear;  //队尾
}Que;

//1.2队列的顺序结构-初始化
void initQue(Que* q)
{
    q->rear = 0;
    q->front = 0;
}

//1.3队列的顺序结构-判断队列是否为空
int isEmpty(Que* q)
{
    if(q->front == q->rear)
    {
        printf("the que is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//1.4队列的顺序结构-出队
ElemType dequeue(Que* q)
{
    if(q->front == q->rear)
    {
        printf("the que is empty\n");
        return 1;
    }
    ElemType a = q->data[q->front];
    q->front++;
    return a;
}

//1.5队列的顺序结构-入队
int enqueue(Que* q,ElemType a)
{
    if(q->rear >= MAXSIZE - 1)
    {
        printf("fulled\n");
        return 0;
    }
    q->data[q->rear] = a;
    q->rear++;
    return 1;
}

//1.5队列的顺序结构-调整队列(老办法)
//（当一个队列之前为满，从队头出队了几个数据后想要再给队列添加数据时候，
//把队列里所有元素整体前移，让队头回到数组下标 0，从而在尾部腾出空间）
//也就是所谓的假溢出

//如下图          0
//                |
/*最初:        [front] []   []        [] []   []      []  [rear]
*出队一部分后:  []      [] [front]     [] []  []      []  [rear]
*                            |
*                            2
*进行调整后：   [front] []   []        [] [] [rear]   []  []
*                 |                           |
*                 0                         rear-2
*/

int queueFull(Que* q)
{
    //判断队列是否真的满了
    if(q->front > 0)
    {
        int step = q->front;
        for(int i = q->front;i < q->rear;i++)
        {
            q->data[i-step] = q->data[i];
        }
        q->front = 0;
        q->rear = q->rear - step;
        return 1;
    }
    else
    {
        printf("the queue is full\n");
        return 0;
    }
}

//1.6队列的顺序结构-获取队头数据
int getHead(Que* q,ElemType* a)
{
    if(q->front == q->rear)
    {
        printf("the queue is empty\n");
        return 0;
    } 
    *a = q->data[q->front];
    return 1;
}

//1.7队列的顺序结构-动态内存分配
typedef struct QueMem{
    ElemType* data;
    int rear,front;
}QueMem;
QueMem* initQueMem()
{
    QueMem* q = (QueMem*)malloc(sizeof(QueMem));
    q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    q->front = -1;
    q->rear = -1;
    return q;
}

//1.8队列的顺序结构-循环队列-入队
int Circlequeue(Que* q,ElemType a)
{
    if((q->rear + 1) % MAXSIZE == q->front + 1)
    {
        printf("the queue is full\n");
        return 0;
    }
    q->data[q->rear+1] = a;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

//1.9队列的顺序结构-循环队列-出队
int Circledeque(Que* q, ElemType* a)
{
    
}

int main()
{
    Que q;
    //初始化
    initQue(&q);

    //入队
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,6);

    //获取队头的元素
    ElemType a;
    getHead(&q,&a);
    printf("the que head = %d\n");

    //出队
    ElemType b = dequeue(&q);
    printf("the out que = %d\n",b);
    b = dequeue(&q);
    printf("the out que = %d\n",b);
    b = dequeue(&q);
    printf("the out que = %d\n",b);

    //队列调整
    queueFull(&q);
    getHead(&q,&a);
    printf("the que head = %d\n");
}
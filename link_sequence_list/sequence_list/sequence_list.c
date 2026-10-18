#include<stdio.h>
#include<stdlib.h>

//1.顺序表
#define MAXSIZE 100
typedef int ElemType; //元素类型

typedef struct 
{
   ElemType data[MAXSIZE]; //存放数据的数组
   int length;  //当前元素个数
}SeqList;

//1.1初始化顺序表
void initList(SeqList *L)
{
    L -> length = 0;
}

//1.2顺序表-在尾部添加元素
int addendElem(SeqList *L,ElemType a)
{
    if(L -> length >= MAXSIZE)
    {
        printf("full\n");
        return 0;
    }
    L -> data[L->length] = a;
    L -> length++;
    return 1;
}

//1.3顺序表-遍历
void listElem(SeqList *L)
{
    for(int i = 0; i<L->length;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

//1.4插入元素
//以下为自己手写的
void interElem_my(SeqList *L,ElemType num,int pos)
{
    ElemType middle[MAXSIZE];
    for(int i = 0; i < L->length; i++)
    {
        middle[i] = L->data[i];
    }
    L->data[pos - 1] = num;
    for(int i = pos; i <= L->length; i++)         //1.46.27
    {
        L->data[i] = middle[i-1];
    }
    L->length++;
}
//以下为课程中的
void interElem(SeqList *L,ElemType num,int pos)
{
    if(pos <= L->length)
    {
        for(int i = L->length - 1 ;i >= pos-1 ;i--)
        {
            L->data[i+1] = L->data[i];
        }
        L->data[pos - 1] = num;  
        L->length++;
    }
}

//1.5删除元素
ElemType delElem(SeqList *L,int pos,ElemType *e)
{
    if(pos < L->length)
    {   
        *e = L->data[pos-1];
        for(int i = pos - 1;i < L->length - 1;i++)
        {
            L->data[i] = L->data[i+1];
        }
        L->length--;
        
    }
    return 1;
}

//1.6查找元素
//自己写的
int findElem(SeqList *L,ElemType a)
{
    int i = 0;
    if(i < L->length)
    {
        while(L->data[i] != a)
        {
            i++;
        }
    }
    return i+1;
}
//课程中的
/*
int findElem(SeqList *L, ElemType a)
{
    if (L == NULL)
        return 0;

    for (int i = 0; i < L->length; i++)
        if (L->data[i] == a)
            return i + 1;

    return 0;
}*/


//1.7动态分配内存初始化
typedef struct{
    ElemType *data; //存放数据的数组
    int length;  //当前元素个数
}MemoryList;
MemoryList* initListMem ()
{
    MemoryList* L = (MemoryList*)malloc(sizeof(SeqList));
    L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    L->length = 0;
    return L;
}
int addendElemM(MemoryList *L,ElemType a)
{
    if(L -> length >= MAXSIZE)
    {
        printf("full\n");
        return 0;
    }
    L -> data[L->length] = a;
    L -> length++;
    return 1;
}
void listElemM(MemoryList *L)
{
    for(int i = 0; i<L->length;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}



int main()
{
    //初始化顺序表
    SeqList List;
    initList(&List);
    //末尾添加元素
    ElemType infer = addendElem(&List,1);
    if(infer!=1)
    {
        printf("add failed\n");
        return 0;
    }
    addendElem(&List,2);
    addendElem(&List,3);
    addendElem(&List,99);
    //插入元素
    interElem_my(&List,55,2);
    interElem(&List,66,3);
    //遍历元素
    listElem(&List);
    //删除元素
    ElemType del;
    delElem(&List,3,&del);
    listElem(&List);
    printf("Delete Elem: %d\n",del);
    //查找元素
    ElemType nedd_find = 2;
    int find = findElem(&List,2);
    printf("we want to find the Elem:%d,the poition:%d\n",nedd_find,find);

    //初始化顺序表（动态分配内存版）
    MemoryList *Mlist = initListMem();
    int infer_1 = addendElemM(Mlist,11);
    if(infer_1 != 1)
    {
        return 0;
    }
    addendElemM(Mlist,22);
    addendElemM(Mlist,33);
    listElemM(Mlist);

    
    return 0;
}
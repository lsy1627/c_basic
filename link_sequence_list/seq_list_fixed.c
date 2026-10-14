#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

/* 顺序表：data 指向堆上申请的连续空间，length 为当前元素个数 */
typedef struct {
    ElemType *data;
    int length;
} SeqList;

/* 1.1 初始化顺序表 */
SeqList *initList(void)
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    if (L == NULL)
        return NULL;

    L->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    if (L->data == NULL)
    {
        free(L); /* 先内后外，防泄漏 */
        return NULL;
    }
    L->length = 0;
    return L;
}

/* 1.2 销毁顺序表：先内后外 */
void destroyList(SeqList *L)
{
    if (L == NULL)
        return;

    free(L->data);
    L->data = NULL; /* 释放后立刻置空，防悬垂指针 */
    free(L);
}

/* 1.3 在尾部添加元素：返回 1 成功、0 失败 */
int addendElem(SeqList *L, ElemType a)
{
    if (L == NULL || L->data == NULL)
        return 0;
    if (L->length >= MAXSIZE)
    {
        printf("full\n");
        return 0;
    }
    L->data[L->length] = a;
    L->length++;
    return 1;
}

/* 1.4 遍历：只打印有效区 data[0] ~ data[length-1] */
void listElem(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

/* 1.5-1 自己手写的插入：用中转变存，思路直观但多开一个数组 */
void interElem_my(SeqList *L, ElemType num, int pos)
{
    if (L == NULL || L->length >= MAXSIZE)
        return;
    if (pos < 1 || pos > L->length + 1)
        return;

    ElemType middle[MAXSIZE];
    for (int i = 0; i < L->length; i++)
        middle[i] = L->data[i];

    L->data[pos - 1] = num;
    /* 旧下标 j 要移到 j+1，最后一次必须写 data[length]（插入后 length+1，合法） */
    for (int i = L->length; i >= pos; i--)
        L->data[i] = middle[i - 1];

    L->length++;
}

/* 1.5-2 课程写法：从后往前逐个后移，O(n) 时间、O(1) 空间 */
void interElem(SeqList *L, ElemType num, int pos)
{
    if (L == NULL || L->length >= MAXSIZE)
        return;
    if (pos < 1 || pos > L->length + 1)
        return;

    for (int i = L->length - 1; i >= pos - 1; i--)
        L->data[i + 1] = L->data[i];
    L->data[pos - 1] = num;
    L->length++;
}

/* 1.6 删除：返回值只表示状态，被删元素通过 e 带出 */
ElemType delElem(SeqList *L, int pos, ElemType *e)
{
    if (L == NULL || e == NULL)
        return 0;
    if (pos < 1 || pos > L->length) /* 两端都要查 */
        return 0;

    *e = L->data[pos - 1]; /* 先存档，再挪动 */
    for (int i = pos - 1; i < L->length - 1; i++)
        L->data[i] = L->data[i + 1];
    L->length--;

    return 1;
}

/* 1.7 按值查找：返回序号(从1起)，0 表示未找到 */
int findElem(SeqList *L, ElemType a)
{
    if (L == NULL)
        return 0;

    for (int i = 0; i < L->length; i++)
        if (L->data[i] == a)
            return i + 1;

    return 0;
}

int main(void)
{
    SeqList *List = initList();
    if (List == NULL)
    {
        printf("init failed\n");
        return 0;
    }

    if (addendElem(List, 1) == 1) /* 1 才是成功 */
    {
        addendElem(List, 2);
        addendElem(List, 3);
        addendElem(List, 99);
    }
    else
    {
        printf("add failed\n");
        destroyList(List);
        return 0;
    }

    interElem_my(List, 55, 2);
    interElem(List, 66, 3);
    listElem(List); /* 1 55 66 2 3 99 */

    ElemType del;
    if (delElem(List, 3, &del) == 1)
    {
        listElem(List); /* 1 55 2 3 99 */
        printf("Delete Elem: %d\n", del); /* 66 */
    }
    else
    {
        printf("delete failed\n");
    }

    int find = findElem(List, 2);
    if (find == 0)
        printf("not found\n");
    else
        printf("find the Elem position:%d\n", find);

    destroyList(List);
    return 0;
}
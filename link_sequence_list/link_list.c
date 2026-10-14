#include<stdio.h>
#include<stdlib.h>

//2单链表
typedef int ElemType;

typedef struct{
    ElemType data;
    struct Node* next;
}Node;

//2.1初始化(头节点)
Node *initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> data = 0;
    head -> next = NULL;
    return head;
}

int main()
{
    Node *list = initList();
    return 1;
}
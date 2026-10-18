#include<stdio.h>
#include<stdlib.h>

//3.双向链表
typedef int ElemType; 

typedef struct Node{
    ElemType data;
    struct Node* next,* prev;
}Node;

//3.1双向链表-初始化链表
Node* initList()
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->prev = NULL;
    p->next = NULL;
    p->data = 0;
}

//3.2双向链表-头插法
void insertHead(Node* node,ElemType a)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->prev = node;
    new->next = node->next;
    if(node->next != NULL)
    {
        node->next->prev = new;
    }
    node->next = new;
    new->data = a;
}

//3.3双向链表-遍历（其实与之前的是一样的）
void listElem(Node* node)
{
    if(node != NULL){
        Node* p = node->next; 
        while(p != NULL)
        {   
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
}

//3.4双向链表-尾插法
Node* get_tail(Node* node)
{
    Node* p = node;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
Node* insertTail(Node* tail,ElemType a)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->prev = tail;
    new->data = a;
    new->next = tail->next;
    tail->next = new;
    return new;
}

//3.5双向链表-在指定位置插入节点
int insertNode(Node* node,int pos,ElemType a)
{
    Node* new = node;
    int i = 0;
    while(i < pos-1)
    {
        new = new->next;
        i++;
        if(new == NULL)
        {
            return 0;
        }
    }

    Node* p = (Node*)malloc(sizeof(Node));
    p->data = a;
    p->next = new->next;
    p->prev = new;
    new->next->prev = p;
    new->next = p;
    return 1;
}

//3.6双向链表-删除节点
ElemType delNode(Node* node,int pos)
{
    Node* new = node;
    int i = 0;
    while(i < pos-1)
    {
        new = new->next;
        i++;
        if(new == NULL)
        {
            return 0;
        }
    }

    Node* p = new->next;
    ElemType del = p->data;
    new->next = p->next;
    p->next->prev = new;
    p->prev = NULL;
    p->next = NULL;
    free(p);
    return del;
}


int main()
{
    Node* list = initList();
    //头插法
    insertHead(list,1);
    insertHead(list,2);
    insertHead(list,3);
    insertHead(list,4);
    //遍历链表
    listElem(list);

    //尾插法
    Node* tail = get_tail(list);
    tail = insertTail(tail,5);
    tail = insertTail(tail,6);
    tail = insertTail(tail,7);
    tail = insertTail(tail,8);
    listElem(list);

    //在指定位置插入节点
    insertNode(list,5,0);
    listElem(list);

    //删除指定节点
    int delpos = 3;
    ElemType del = delNode(list,delpos);
    printf("del the %d node:%d\n",delpos,del);
}
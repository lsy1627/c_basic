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

//2.2头插法(将新添加的数据放到头节点后面)
void insertHead(Node* node,ElemType a)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = a;
    p->next = node->next;
    node->next = p;
}

//2.3遍历链表
//从头节点的后驱开始遍历
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

//2.4尾插法（从最末端往前面加；因此需要获取尾端节点）
Node* get_tail(Node* node)
{
    Node* p = node;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
//返回值为目前的尾节点，方便后续再使用尾插法
Node* inserTail(Node* tail,ElemType a)
{
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = a;
    tail->next = q;
    q->next = NULL;
    return q;
}

//2.5在指定位置插入元素
//返回值可以进行判断是否插入成功
int inserPos(Node* node, int pos, ElemType a)
{
    Node* p = node;
    int i = 0;
    //先获取到需要插入位置的前一个节点
    while(i < pos-1)
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }
    Node* q = (Node*)malloc(sizeof(Node));
    q->next = p->next;
    q->data = a;
    p->next = q;
    return 1;
}

//2.6删除节点
ElemType delElm(Node* node,int pos)
{
    Node* p = node;
    int i = 0;
    //遍历先获取到需要删除节点的前驱
    while(i < pos-1)
    {
        p = p->next;
        i++;
        if(p == NULL)
        {
            return 0;
        }
    }
    Node* q = p->next;
    ElemType del = q->data;
    p->next = q->next;
    free(q);   //删除的节点需要释放内存
    return del;
}

//2.7获取链表的长度
int listLength(Node* node)
{
    Node* p = node;
    int len = 0;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//2.8释放链表(除头节点外的其他节点需要释放)
/*
*定义一个节点（p）将头节点后的第一个节点赋值给他
*判断该节点是否指向空节点(!p->next)
*否：定义一个节点（q）= p->next;释放节点p（free(p)）
*是：则释放完毕
*/
void releList(Node* node)
{
    Node* q;
    Node* p = node->next;
    while(p != NULL)
    {   
        q = p->next;
        free(p);
        p = q;
    }
    node->next = NULL;
}


int main()
{
    //初始化链表
    Node *list = initList();
    //头插法插入元素
    insertHead(list,1);
    insertHead(list,2);
    insertHead(list,3);
    insertHead(list,4);
    //遍历链表
    listElem(list);
    //获取尾节点，为后续使用尾插法做准备
    Node* tail = get_tail(list);
    tail = inserTail(tail,5);
    tail = inserTail(tail,4);
    tail = inserTail(tail,3);
    tail = inserTail(tail,2);
    listElem(list);
    //指定位置进行插入
    inserPos(list,1,5);
    listElem(list);
    //删除节点
    ElemType del = delElm(list,3);
    printf("delete elem:%d\n",del);
    listElem(list);
    //获取链表长度
    int len = listLength(list);
    printf("link_list length:%d\n",len);
    return 1;
}
#include<stdio.h>
#include<stdlib.h>

/*
设线性表L=(a1, a2, a3, ... , an-2, an-1, an)采用带头节点的单链表保存
请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，
重新排列L中的各节点，
得到线性表L’=(a1, an, a2, an-1, a3, an-2, ...)。
要求：
出算法的基本设计思想。
2)根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
3)说明你所设计算法的时间复杂度。
*/

//回答：就是实现把第一个和最后一个放一起，第二个和倒数第二个.....
//思路:先获取到中间位置，再将后半部分直接反转；一个指针指向开始的节点，
//一个指针指向中间位置，也就是后半部分反转后的头节点的后驱

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;
Node* initList()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node-> data = 0;
    node-> next = NULL;
    return node;
}
//---------------下面是为了初始化链表从前面拿过来的代码------------//
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
//--------------------------------------------------------------//
//我思路的实现：
void changeList(Node*node)
{
    Node* fast = node->next; //定义一个快指针，用来后续后半部分的反转
    Node* slow = node->next; //慢指针
    int len = 0;
    for(fast ;fast != NULL;fast = fast->next)
    {
        len++;
    }
    Node* mid = node->next; //获得中间节点（前部分）
    for(int i = 0;i < len/2;i++)
    {
        mid = mid->next;
    }
    //反转后半部分的链表
    Node* first = NULL;
    Node* second = mid->next;
    Node* third;
    mid->next = NULL; //将链表分为两个链表；这个为前部分链表的尾节点
    while(second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    //交叉填写成新的链表
    while(slow != NULL && first != NULL)
    {
        Node* p = slow->next;
        Node* q = first->next;
        slow->next = first;
        first->next = p;
        slow = p;
        first = q;
    }
}
//---------------------------------------------------------------//

//课程：(wo qu课程里面也是这样！！！！)
void reOrderList(Node* head)
{
    Node* fast = head->next;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL) 
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* first = NULL;
    Node* second = slow->next;
    slow->next = NULL; //**************************//
    Node* third = NULL;

    while(second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node* p1 = head->next;
    Node* q1 = first;
    Node* p2 , *q2;
    while(p1 != NULL && q1 != NULL)
    {
        p2 = p1->next;
        q2 = q1->next;
        p1->next = q1;
        q1->next = p2;
        p1 = p2;
        q1 = q2;
    }
}



int main()
{
    Node* node = initList();
    ElemType k = 0;
    insertHead(node,50);
    insertHead(node,40);
    insertHead(node,30);
    insertHead(node,20);
    insertHead(node,10);
    printf("before:");
    listElem(node);
    changeList(node);
    printf("my method after:");
    listElem(node);
}
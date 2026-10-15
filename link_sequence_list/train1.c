#include<stdio.h>
#include<stdlib.h>

/*
已知一个带有表头节点的单链表，节点结构为
data link
假设该链表只给出了头指针 list。在不改变链表的前提下，
请设计一个尽可能高效的算法，
查找链表中倒数第k个位置上的结点(k为正整数)。若查找成功，
算法输出该节点的data域的值，并返回1；否则，只返回0。
要求：
1)描述算法的基本思想；
2)描述算法的详细实现步骤；
3)根据设计思想和实现步骤，采用程序设计语言描述算法（使用C、C++、或Java
语言实现），关键之处请给出简要注释
*/

/*
回答：
1)获取链表长度，再用链表长度 - k 就获得正数位置；将该节点打印出来即可
*/
typedef  int ElemType;

typedef struct{
    ElemType data;
    struct Node* link;
}Node;

Node* initList()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node-> data = 0;
    node-> link = NULL;
    return node;
}
//---------------下面是为了初始化链表从前面拿过来的代码------------//
//2.2头插法(将新添加的数据放到头节点后面)
void insertHead(Node* node,ElemType a)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = a;
    p->link = node->link;
    node->link = p;
}

//2.3遍历链表
//从头节点的后驱开始遍历
void listElem(Node* node)
{
    if(node != NULL){
        Node* p = node->link; 
        while(p != NULL)
        {   
            printf("%d ",p->data);
            p = p->link;
        }
        printf("\n");
    }
}
//--------------------------------------------------------------//

int get_node(Node* node,int pos,ElemType *a)
{
    Node* p = node->link; //存储尾节点
    Node* q = node->link; //存储开始的链表
    /*
    我一开始写的是Node* q = node;
    导致后续打印出来倒数第二个实际是倒数第三个，我们需要知道
    头节点不算入数据
    */
    int len = 0; //用来存节点位置
    while(p != NULL)
    {
        len++; //获取到链表的长度
        p = p->link; //获取到尾节点
    }
    printf("len = %d\n",len);
    if(pos > len)
    {
        return 0;
    }
    len = len - pos; //获取到该节点的位置
    int i = 0;
    for(int i = 0;i<len;i++)
    {
        q = q->link;
    }
    *a = q->data;
    return 1;
}


//--------------------------以下为课程中的实现-------------------//
//双指针（快慢指针）
//思路:快指针先走三步，走完后快慢指针同步走，直到快指针指向为空，返回慢指针
int findNodeFS(Node* node, int k)
{
    Node* fast = node->link;
    Node* slow = node->link;
    for(int i = 0;i < k;i++)
    {
        fast = fast->link;
    }
    while(fast != NULL)
    {
        slow = slow->link;
        fast = fast->link;
    }
    printf("the final %d = %d \n",k,slow->data);
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
    listElem(node);
    int get = get_node(node,2,&k);
    printf("return:%d,k = %d\n",get,k);
    findNodeFS(node,2);
}
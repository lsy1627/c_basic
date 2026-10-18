#include<stdio.h>
#include<stdlib.h>

//2单链表
typedef int ElemType;

typedef struct Node{
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

//2.9单链表的应用-反转链表（train1.2.3后的内容）
//其实就是将箭头方向转换
Node* reverseList(Node* node)
{
    /*
    设置三个指针：first,second,third
    first初始化为NULL作为反转后的尾节点
    second主要操作转换方向
    third作为移动的主要指针

    等到second指向NULL时候，first指向反转后的第一个节点，需要补充头节点
    */
    Node* first = NULL;  
    //之前所写:Node* first = node;
    //会导致头节点也参与进反转：会变成如下
    /* (原链表为：H -> 1 -> 2 -> 3 -> 4)
    * 1 <- H <- 1 <- 2 <- 3 <- 4 (H->next 仍是 1，1->next 又是 H，成环)
    */
    Node* second = node->next;
    Node* third;

    while(second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node* head = initList();
    head->next = first;
    return head;
}

//2.10单链表应用-删除链表中间的节点
//(若链表为偶数个则取偏后的节点为中间节点)
//我自己的想法和上面的删除指定位置节点一样
//课程中：快慢指针
/*思路：慢指针=node；快指针=node->next
*快指针每次走两步，慢指针每次走一步，直到fast->next=NULL || fast=NULL
*此时slow就是中间节点的前驱
*/
void remMidNode(Node* node)
{
    Node* fast = node->next;
    Node* slow = node;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* p = slow->next;
    slow->next = p->next;
    free(p);
}

//2.11单向循环链表（判断是否有环）
//依旧快慢指针
int isCycle(Node* node)
{
    Node* fast = node;
    Node* slow = node;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            return 1;
        }
    }
    return 0;
}

//2.12链表有环入口的查找
Node* cycleStart(Node* head)
{
    Node *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(fast == NULL || fast->next == NULL) return NULL;

    // 相遇后，一个从头出发、一个从相遇点出发，同速前进，再次相遇即入口
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
/*
（设头到入口距离 a，入口到相遇点 b，环长 L）：
fast 走了 a + b + L，slow 走了 a + b，且 fast = 2 * slow
→ a + b + L = 2(a + b) → a = L - b
即"头到入口"等于"相遇点绕回入口"，所以两个指针同速再走必在入口相遇
*/

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
    printf("next_list length:%d\n",len);

    //反转链表
    printf("reverse the list:\n");
    Node* rever = reverseList(list);
    listElem(rever);

    //删除链表中间的节点
    remMidNode(rever);
    printf("remMid the list:\n");
    listElem(rever);

    //判断链表是否有环
    //先初始化一个环
    Node* circle = initList();
    Node* tail1 = get_tail(circle);
    tail1 = inserTail(tail1,1);
    tail1 = inserTail(tail1,2);
    tail1 = inserTail(tail1,3);
    tail1 = inserTail(tail1,4);
    tail1 = inserTail(tail1,5);
    Node* five = tail1;
    tail1 = inserTail(tail1,6);
    tail1 = inserTail(tail1,7);
    tail1 = inserTail(tail1,8);
    tail1->next = five;

    if(isCycle(circle))
    {
        printf("have circle");
    }
    else
    {
        printf("no have circle");
    }

    //查找环的入口
    Node* intoCircle = cycleStart(circle);
    printf("the circle start: %d\n",intoCircle->data);
    return 0;
}
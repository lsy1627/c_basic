#include<stdio.h>
#include<stdlib.h>

/*
假定采用带头节点的单链表保存单词，
当两个单词有相同的后缀时，则可共享相同的后缀存储空间，
例如，“loading”和“being”的存储映像如下图所示。
str1 | | |  | |l|  | |o|  | |a|  | |d| 
                                        [ |i]  [ |n]  [ |g]
str2 | | |  | |b|  | |e|  
(注意：这里存在问题字母应该放在前面)
设str1 和str2 分别指向两个单词所在单链表的头节点，链表结点结构为
data next
请设计一个时间上尽可能高效的算法，找出由str1 和 str2所指向
两个链表共同后缀的起始位置（如图字符i所在结点的位置p)。要求：
1)描述算法的基本设计思想；
2)根据设计思想，采用C或C++或Java 语言描述，关键之处给出注释
*/


typedef char ElemType;

typedef struct Node{
    ElemType data;
    struct Node* link;
}Node;

Node* initList()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node-> data = ' ';
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
Node* get_tail(Node* node)
{
    Node* p = node;
    while(p->link != NULL)
    {
        p = p->link;
    }
    return p;
}
//返回值为目前的尾节点，方便后续再使用尾插法
Node* inserTail(Node* tail,ElemType a)
{
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = a;
    tail->link = q;
    q->link = NULL;
    return q;
}
//--------------------------------------------------------------//

Node* findPub(Node* str1,Node* str2)
{
    int len1 = 0,len2 = 0;
    int past,pos = 0;
    Node* m;
    Node* n;
    Node* p = str1->link;
    Node* q = str2->link;
    for(Node* t = p;t != NULL;t = t->link) len1++;
    for(Node* t = q;t != NULL;t = t->link) len2++;
    if(len1 > len2)
    {
        past = len1 - len2;
        m = p;
        n = q;
    }
    else
    {
        past = len2 - len1;
        m = q;
    }
    for(int i = 0;i < past;i++)
    {
        m = m->link;
    }
    while(m != n)
    {
        m = m->link;
        n = n->link;
        pos++;
    }
    return m;
}

int main()
{
    Node* str2 = initList();
    insertHead(str2,'g'); insertHead(str2,'n'); insertHead(str2,'i');
    insertHead(str2,'e'); insertHead(str2,'b');        // str2 = b e i n g

    // str1 只建前缀 "load"，再把 str2 的 "ing" 接过来共享
    Node* str1 = initList();
    Node* tail = str1;
    const char *pre = "load";
    for(int i = 0; pre[i]; i++) 
    {
        tail = inserTail(tail, pre[i]);
    }
    tail->link = str2->link->link->link;   // 跳过 b、e，指向共享的 i
    // str1 = l o a d i n g
    Node* q = findPub(str1,str2);
    char p = q->data;
    printf("p:%c\n",p);
}


//问题总结：一开始的题目并未理解清楚，当成查找相同的尾字符；实则是
//        两个字符串的后缀为同一片地址
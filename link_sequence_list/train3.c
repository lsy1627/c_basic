#include<stdio.h>
#include<stdlib.h>

/*
用单链表保存n个整数，结点的结构为[datal | link]，且|data|<=n(n为正整数)。
现要求设计一个时间复杂度尽可能高效的算法，
对于链表中 data 的绝对值相等的节点，
仅保留第一次出现的节点而删除其余绝对值相等的结点。
例如，若给定单链表head 如下：
head [ | ]  [21| ]  [-15| ]  [-15| ]  [-7| ]  [15| ]
则删除节点后的 head为
head [ | ]  [21| ]  [-15| ]  [-7| ]
2
要求：
1)给出算法的基本设计思想。
2)使用C或C++语言，给出单链表节点的数据类型定义。
3)根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
4)说明你所设计算法的时间复杂度和空间复杂度。
*/

//回答：目前能想到的只有循环嵌套（2026.10.17 14:51） 


//课程：空间换时间；

typedef  int ElemType;

typedef struct Node{
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

//删除绝对值相同的节点
void removeNode(Node* node,int n) //n为我们设置的数组的长度，链表data中的绝对值最大数
{
    Node* p = node;
    int index; //数组下标
    int* tem = (int*)malloc(sizeof(int)*(n+1));
    for(int i = 0;i < n + 1;i++)
    {
        *(tem + i) = 0; 
    }
    while(p->link != NULL)
    {
        index = abs(p->link->data);
        if(*(tem+index) == 0)
        {
            *(tem + index) = 1;
            p = p->link;
        }
        else{
            Node* q = p->link;
            p->link = q->link;
            free(q);
        }
    }
    free(tem);
}


int main()
{
    Node* node = initList();
    ElemType k = 0;
    insertHead(node,10);
    insertHead(node,-10);
    insertHead(node,22);
    insertHead(node,44);
    insertHead(node,32);
    insertHead(node,10);
    insertHead(node,-22);
    listElem(node);

    removeNode(node,44);
    listElem(node);
}
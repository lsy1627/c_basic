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

typedef struct{
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

int findPub(Node* str1,Node* str2)
{
    int len1,len2;
    Node* str_1 = str1->link;
    Node* str_2 = str2->link;
    while(str_1 != NULL || str_2 != NULL)
    {
        if(str_1 != NULL)
        {
            len1++;
        }
        if(str_2 != NULL)
        {
            len2++;
        }
    }
    int past = (len1 > len2) ? (len1 - len2):(len2 - len1);
    for(int i = 0;i <((len1 > len2)? len2 : len1);i++)
    {
        if(str_1 == str_2)
        {
            
        }
    }
}
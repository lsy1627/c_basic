#include <stdio.h>
#include <stdlib.h>

//查找两个字符串最长相同的字符
char *Find_Max_Pub(char* src,char* des,int *out_len){
    char *Max_Pub = NULL;
    int max_len = 0; //记录最长相同量
    //通过双循环进行遍历
    for(char *p = src; *p != '\0';p++){
        for(char *q = des; *q != '\0';q++){
            if(*p == *q){
                char *a = p, *b = q;
                int len = 0;
                //这里进行判断相同字符
                while(*a != '\0' && *b != '\0' && *a == *b){
                    a++;
                    b++;
                    len++;
                }
                if(len > max_len){
                    max_len = len;
                    Max_Pub = p;
                }
            }
        }
    }
    *out_len = max_len;
    return Max_Pub;
}

int main(){
    char *str1 = (char*)malloc(128);
    char *str2 = (char*)malloc(128);
    int max_len = 0; //记录相同字符的数量
    printf("please put in a string1:\n");
    scanf("%[^\n]", str1); //遇到换行符停止输入，遇到空格不会停止输入
    getchar();
    printf("please put in a string2:\n");    
    scanf("%[^\n]", str2);
    char* max = Find_Max_Pub(str1,str2,&max_len);
    if(max != NULL){
        for(int i = 0;i < max_len; i++){
            printf("%c",max[i]);
        }
        printf("\n");
    }
    free(str1); //释放动态分配的内存
    free(str2); 
    return 0;
}
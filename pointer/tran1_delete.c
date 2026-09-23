#include <stdio.h>
#include <stdlib.h>

//定义一个函数，删除字符串中的空格
char *delete(char *p){
    char *q = p; //记录原始字符串的起始地址
    char *r = p; //记录新字符串的起始地址
    while(*p != '\0'){
        if(*p != ' '){
            *r++ = *p;//如果不是空格，就把当前字符赋值给新字符串，并移动新字符串的指针
        }
        p++;//移动原始字符串的指针
    }
    *r = '\0';
    return q;
}



int main(){
    char *str = (char*)malloc(128);
    printf("please put in a string:\n");
    scanf("%[^\n]", str); //遇到换行符停止输入，遇到空格不会停止输入
    char *s2 = delete(str);
    printf("%s\n", s2);
    free(str); //释放动态分配的内存
    return 0;
}
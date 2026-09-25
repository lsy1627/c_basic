#include <stdio.h>
#include <stdlib.h>

//查找字符串中没有重复出现过的字符
char *only (char *src){
    char *buf = (char*)malloc(128);
    char *end = buf;
    for (char *p = src;*p != '\0';p++){
        int count = 0;
        for(char *q = src;*q != '\0';q++){
            if(*p == *q){
                count ++;
            }
        }
        if(count == 1){
            *end = *p;
            end ++;
        }
    }
    *end = '\0';
    return buf;
}

int main(){
    char *str = (char*)malloc(128);
    printf("please put in a string:\n");
    scanf("%[^\n]", str); //遇到换行符停止输入，遇到空格不会停止输入
    char *s2 = only(str);
    printf("%s\n", s2);
    free(str); //释放动态分配的内存
    free(s2);
    return 0;
}
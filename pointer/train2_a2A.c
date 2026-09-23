#include <stdio.h>
#include <stdlib.h>

//定义一个函数，将字符串中的小写字母转换为大写字母
char *Toupper(char *p){
    char *q = p; //记录原始字符串的起始地址
    while(*p != '\0'){
        if(*p >= 'a' && *p <= 'z'){ //判断当前字符是否为小写字母
            *p = *p - 32; //将小写字母转换为大写字母
        }
        p++;
    }
    return q;
}

int main(){
    char *str = (char*)malloc(128);
    printf("please put in a string:\n");
    scanf("%[^\n]", str); //遇到换行符停止输入，遇到空格不会停止输入
    char *s2 = Toupper(str);
    printf("%s\n", s2);
    free(str); //释放动态分配的内存
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

//对字符串添加帧头帧尾
char *add_h_t(char *src){
    const char *h = "head";
    const char *t = "tail";
    char *out = (char*)malloc(128); //作为返回的数组
    char *p = out;
    char *q = h;
    while(*q != '\0') *p++ = *q++; //将帧头添加过去
    q = src;
    while(*q != '\0') *p++ = *q++; //将内容写入out
    q = t;
    while(*q != '\0') *p++ = *q++; //将帧尾添加上

    *p = '\0';
    return out;
}

int main(){
    char *str = (char*)malloc(128);
    printf("please put in a string:\n");
    scanf("%[^\n]", str); //遇到换行符停止输入，遇到空格不会停止输入
    char *s2 = add_h_t(str);
    printf("%s\n", s2);
    free(str); //释放动态分配的内存
    return 0;
}
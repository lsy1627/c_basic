#include <stdio.h>
#include <stdlib.h>

/*
*将句子倒置，不改变单词内部结构
*eg:输入：I am from shanghai
*   输出：shanghai from am I
*/

char *Inver_Str(char *src){
    char *start = src;
    char *end = src; 
    while(*end != '\0'){
        end ++;
    }
    end --; //字符串末尾

    //步骤一：先给字符串整体倒置，不去理会单词内部结构
    while(start < end){
        char temp = *start;
        *start = *end;
        *end = temp;
        start ++;
        end --;
    }//此时字符串变为: I ma morf iahgnahs

    //步骤二：反转每一个单词
    char *p = src;
    while(*p != '\0'){
        char *word_start = p;
        while(*p != '\0' && *p != ' ') p++;
        char *word_end = p - 1;
        while(word_start < word_end){
            char t = *word_start;
            *word_start = *word_end;
            *word_end = t;
            word_start++; word_end--;
        }
        while(*p == ' ')p++;
    }
    return src;
} 

int main(){
    char *str = (char*)malloc(128);
    printf("please put in a string:\n");
    scanf("%[^\n]", str); //遇到换行符停止输入，遇到空格不会停止输入
    char *s2 = Inver_Str(str);
    printf("%s\n", s2);
    free(str); //释放动态分配的内存
    return 0;
}
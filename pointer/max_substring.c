#include <stdio.h>
#include <string.h>

void Find_Max_Pub(char *s1, char *s2){
    char *max_start = NULL;  // 记录最长子串在s1中的起始位置
    int max_len = 0;

    // s1 中每个位置作为起点
    for(char *p = s1; *p != '\0'; p++){
        // s2 中每个位置作为起点
        for(char *q = s2; *q != '\0'; q++){
            if(*p == *q){
                char *a = p, *b = q;
                int len = 0;
                // 两个指针一起往后走，直到遇到不同字符
                while(*a != '\0' && *b != '\0' && *a == *b){
                    a++;
                    b++;
                    len++;
                }
                if(len > max_len){
                    max_len = len;
                    max_start = p;
                }
            }
        }
    }

    if(max_len > 0){
        printf("最长公共子串: %.*s\n", max_len, max_start);
    } else {
        printf("无公共子串\n");
    }
}

int main(){
    char s1[] = "abcdeffgh";
    char s2[] = "xzbcdy";
    Find_Max_Pub(s1, s2);
    return 0;
}
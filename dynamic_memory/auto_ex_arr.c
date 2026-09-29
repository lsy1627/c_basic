#include <stdio.h>
#include <stdlib.h>

//实现一个能自动扩容的动态数组（就是 `realloc` 那套翻倍扩容）
//但是要实现c++的vector还是有点困难
int main(){
    int now_len = 0; //实际所用字节
    int capacity = 10; //容量
    int *p = (int *)malloc(capacity*sizeof(int));//先手动分配10个字节
    if(p == NULL){
        return -1;
    }
    for(int i = 0;i < 20;i ++){ //给分配的内存进行赋值，占用内存
        if(now_len == capacity){ //判断是否将所分配的内存占满
            capacity *= 2; //给内存进行翻倍扩充
            int *tmp = (int*)realloc(p,capacity*sizeof(int));
            if(tmp == NULL){
                free(p);
                return -1;
            }
            p = tmp;
        }
        p[now_len++] = i; //赋值
    }
    for(int i = 0;i < now_len;i ++){
        printf("%d ",p[i]);
    }
    printf("\n");
    printf("capacity:%d,now_len:%d\n",capacity,now_len);

    free(p);
    p = NULL;
    return 0;
}
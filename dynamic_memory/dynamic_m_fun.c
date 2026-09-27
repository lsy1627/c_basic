#include <stdio.h>
#include <stdlib.h>


int main(){
    //使用malloc()分配内存
    int *num = (int*)malloc(10*sizeof(int));
    if(num == NULL){
        printf("gain failed!");
        return -1;
    }
    int i = 0;
    for(i;i<10;i++){
        printf("%d ",*(num + i));
    }
    printf("\n");


    //使用calloc分配内存
    int *num1 = (int*)calloc(10,sizeof(int));
    if(num1 == NULL){
        printf("gain failed!");
        free(num);
        return -1;
    }
    for(i = 0; i < 10; i++){
        printf("%d ", num1[i]);   //calloc分配的内容默认全为0
    }
    printf("\n");

    free(num);
    num = NULL;
    free(num1);
    num1 = NULL;
    return 0;
}
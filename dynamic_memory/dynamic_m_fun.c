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
    for(i = 0; i < 10; i++){
        *(num + i) = i + 1;     //malloc分配的内容是垃圾值，必须先初始化
    }
    for(i = 0; i < 10; i++){
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
        printf("%d ", *(num1+i));   //calloc分配的内容默认全为0
    }
    printf("\n");


    //使用realloc调整分配的内存
    //1、在原来mallloc和calloc分配的基础上进行调整
    int *tmp = (int*)realloc(num1, 20 * sizeof(int));
    if(tmp == NULL){
        printf("realloc failed!\n");
        free(num);          
        return -1;
    }
    num1 = tmp;             // 成功才换指针

    //realloc新扩出来的10个是未初始化垃圾值，必须先赋值
    for(i = 10; i < 20; i++){
        num1[i] = i + 1;
    }
    for(i = 0; i < 20; i++){
        printf("%d ", *(num1+i));   //前10个是calloc清过的0，后10个是新赋的值
    }
    printf("\n");

    free(num);
    num = NULL;
    free(num1);
    num1 = NULL;
    return 0;
}
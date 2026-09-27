#include <stdio.h>

typedef struct{
    char *name ;
    int age;
    int score;
}Student;

//返回学生的平均分
double average(Student *stu,int n){
    int add = 0;
    float average;
    for(int i = 0;i < n;i++){
        add += stu[i].score;
    }
    average = add/(n*1.0);
    return average;
}

//回调函数：把函数当参数传给别人，由别人决定什么时候调用它。
int by_score(Student *a,Student *b){ //传入两个结构体，返回内部的score
    return a->score > b->score;
}
int by_age(Student *a,Student *b){ //传入两个结构体，返回内部的age
    return a->age > b->age;
}

//参数1：结构体数组；参数2：结构体数量；回调函数
void sort(Student *s,int n,int (*p)(Student*,Student*)){
    int i,j;
    for(i = 0;i<n;i++){
        for(j = 0;j<n - i -1;j++){
            if(p(&s[j],&s[j+1])){
                Student num = s[j];
                s[j] = s[j+1];
                s[j+1] = num; 
            }
        }
    }
}



int main(){
    Student stu1 = {.name = "lsy", .age = 16,.score = 100};
    Student stu2 = {.name = "ls", .age = 14,.score = 90};
    Student arr[2] = {stu1,stu2};
    float a = average(arr,2);

    sort(arr,2,by_age);
    for(int i = 0;i<2;i++){
        printf("%d ",arr[i].age);
    }
    printf("%f\n",a);
}
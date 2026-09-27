#include <stdio.h>

typedef struct{
    int year;
    int month;
    int day;
}Data;

typedef struct{
    char *name;
    int score;
    Data birth;
}Student;

int is_valid_birthday(Student *s){
    if(s->birth.month >=1 && s->birth.month <= 12 && s->birth.day >=1 &&s->birth.day <=31){
        return 1;
    }
    return 0;
}

int sort(Student *a,Student *b){
    if(a->birth.year == b->birth.year){
        if(a->birth.month == b->birth.month){
            return a->birth.day > b->birth.day;
        }
        else{
            return a->birth.month > b->birth.month;
        }
    }
    else{
        return a->birth.year > b->birth.year;
    }
}

void print_sorted(Student *s,int n,int (*p)(Student*,Student*)){
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j < n -i-1;j++){
            if(p(&s[j],&s[j+1])){
                Student num = s[j];
                s[j] = s[j+1];
                s[j+1] = num;
            }
        }
    }
    for(i = 0;i<n;i++){
        printf("name:%s, score:%d, birthday:%d-%d-%d\n",s[i].name,s[i].score,
            s[i].birth.year,s[i].birth.month,s[i].birth.day);
    }
}


int main(){
    Student stu1 ={.name = "lsy",.score = 100,
            .birth = {.year = 2007,.month = 11,.day = 27}};
    Student stu2 ={.name = "ls",.score = 90,
            .birth = {.year = 2007,.month = 9,.day = 16}};
    Student arr[2] = {stu1,stu2};
    print_sorted(arr,2,sort);
    return 0;
}
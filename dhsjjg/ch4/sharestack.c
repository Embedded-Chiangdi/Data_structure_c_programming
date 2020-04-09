#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1
#define MAXSIZE 20

typedef int Status;
typedef int ElementType;

typedef struct shareStack{
    ElementType data[MAXSIZE];
    int top1;
    int top2;
}ShareStack,*pShareStack;

Status PushShareStack(pShareStack sst,int select){
    if(sst == NULL)
        return ERROR;
    if((sst->top2-sst->top1) <= 1 ){
        printf("Stack is full");
        return ERROR;
    }
    if(select == 1){
        sst->data[sst->top1]=rand()%100+1;
        sst->top1++;
        return OK;
    }
    else if(select ==2){
        sst->top2--;
        sst->data[sst->top2]=rand()%100+1;
        return OK;
    }
    else
        printf("select arguments error\n");
        return ERROR;
}
Status PopShareStack(pShareStack sst,int select){
    if(sst == NULL)
        return ERROR;
    if(select == 1){
        if(sst->top1>0){
            sst->top1--;
            printf("data is %d",sst->data[sst->top1]);
            return OK;
        }
        printf("Stack1 is Null\n");
        return ERROR;
    }
    else if (select == 2){
        if(sst->top2<20){
            printf("data is %d \n",sst->data[sst->top2]);
            sst->top2++;
        }
        printf("Stack2 is Null\n");
        return ERROR;
    }
    else
    {
        printf("select is error\n");
        return ERROR;
    }
    
}

Status main(int argc , char **argv){
    
    return OK;
}
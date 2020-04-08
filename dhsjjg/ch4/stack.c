#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1

typedef int Status;
typedef int ElementType;

typedef struct stack{
    ElementType data[MAXSIZE];
    int top;
}Stack, *pStack;

Status InitStack(pStack *st);
Status DestoryStack(Stack *st);

int main(int argc,char **argv){
    pStack MyStack;
    int iRet=-1;
    iRet=InitStack(&MyStack);
    if(iRet){
        printf("allocate memory failed\n");
        return ERROR;
    }
    else
        printf("allocate memory succed\n");
    MyStack->top=10;
    free(MyStack);
    printf("=%d",MyStack->top);
    return OK;
}

Status InitStack(pStack *st){
    *st=malloc(sizeof(Stack));
    if(*st==NULL){
            return ERROR;
        } 
    (*st)->top=0;
    return OK;
}

Status DestoryStack(pStack st){
    if(!st){
        printf("Ptr is Null\n");
        return ERROR;
    }
    printf("In Subfunction :%d\n",st->top);
    printf("Destory Stack\n");
    free(st);
    return OK;
}
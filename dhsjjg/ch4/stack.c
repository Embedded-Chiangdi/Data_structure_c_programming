#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1
#define NullStack -1

typedef int Status;
typedef int ElementType;

typedef struct stack{
    ElementType data[MAXSIZE];
    int top;
}Stack, *pStack;

Status InitStack(pStack *st);
Status DestoryStack(pStack st);
Status LengthStack(pStack st);
Status PushStack(pStack st);
Status PopStack(pStack st);
Status ClearStack(pStack st);
Status CheckTopStack(pStack st);

int main(int argc,char **argv){
    pStack MyStack=NULL;
    int iRet=-1;
    iRet=InitStack(&MyStack);
    if(iRet){
        printf("allocate memory failed\n");
        return ERROR;
    }
    printf("allocate memory succed\n");



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
Status LengthStack(pStack st){
    if(st == NULL){
        printf("Ptr is NULL\n");
        return NullStack;
    }

    printf("The length is %d\n",st->top);
    return st->top;
}
Status PushStack(pStack st){
    
    if(st ==NULL){
        printf("Ptr is Null\n");
        return ERROR;
    }
    if(st->top >= MAXSIZE){
        printf("Stack is Full\n");
        return ERROR;
    }
    st->data[st->top]=rand()%+1;
    st->top++;

    printf("Push \n");
    return OK;
}
Status PopStack(pStack st){
    if(st ==NULL){
        printf("Ptr is Null\n");
        return ERROR;
    }
    if(st->top <= 0){
        printf("Stack is Null\n");
        return ERROR;
    }
    st->top--;
    st->data[st->top]=0;
    printf("Pop\n");
    return OK;
}
Status ClearStack(pStack st){
    if(st == NULL){
        printf("Ptr is Null\n");
    }
    st->top--;
    while(st->top>=0)
        st->data[st->top]=0;
        return OK;
}
Status CheckTopStack(pStack st){
    if(st == NULL){
        printf("Ptr is Null\n");
        return ERROR;
    }
    if(st->top > 0 )
        printf("Top is %d",st->data[st->top --]);
    else
    {
        printf("Stack is Null\n");
        return ERROR;
    }
    return OK;
}
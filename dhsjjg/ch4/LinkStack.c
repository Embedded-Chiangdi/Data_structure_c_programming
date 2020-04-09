#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1
#define MAXSIZE 20

typedef int Status;
typedef int ElementType;

typedef struct stacknode{
    ElementType data;
    struct stacknode *next;
}StackNode,*LinkStackPtr;

typedef struct linkstack{
    LinkStackPtr top;
    int count;
}LinkStack;

Status PushLinkStack(LinkStack * lst){
    if(lst == NULL)
        return ERROR;
    LinkStackPtr newNode;
    
    newNode = malloc(sizeof(StackNode));
    newNode->data=rand()%100+1;
    newNode->next=lst->top;
    lst->top=newNode;
    lst->count++;
    return OK;
}

Status PopLinkStack(LinkStack *lst){
    LinkStackPtr temp;
    if(lst == NULL)
        return ERROR;
    if(lst->count <= 0 ){
        printf("Stack is Null\n");
        return ERROR;
    }
    temp = lst->top;
    lst->top=temp->next;
    free(temp);
    return ERROR;
}
Status main(int argc , char **argv){
    
    return OK;
}
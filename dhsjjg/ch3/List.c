#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 20
#define RANDNUM 20
#define OK 0
#define ERROR 1

typedef int Status;
typedef int ElementType;
typedef struct {
    ElementType data[MAXSIZE];
    int length;
}List,*pList;

enum OP{
    Empty=1,
    Clear,
    GetListLength,
    InsertElement,
    DeleElement,
    LocateElement,
    FindLocateValue,
    ShowList
};


Status InitList(pList *L);
Status ListEmpty(pList L);
Status ListShow(pList L);
Status ClearList(pList L);
Status GetLength(pList L);
Status InsertElem(pList L, int N, int value);
Status DeleElem(pList L, int N);
Status LocateElem(pList L, int N,int *value);
Status FindLocate(pList L, int value,int *N);

Status help();

int main(int *argc, char ** argv){
    pList SqList;
    Status iRet;
    int N=-1,value =0;
    int op;

    if(InitList(&SqList)!=0){
        printf("Init List failed!\n");
        return ERROR;
    }
    printf("Init List Succed!\n");
    

    ListEmpty(SqList);

    if(iRet!=0){
        printf("Error %d\n",iRet);
        return ERROR;
    }

    ListShow(SqList);
    while(1){
        help();
        scanf("%d",&op);
        if(op>0 && op <9)
        switch(op){
            case Empty :
                ListEmpty(SqList);
                break;
            case Clear:
                ClearList(SqList);
                break;
            case GetListLength:
                GetLength(SqList);
                break;
            case InsertElement:
                printf("What position will you insert \n");
                scanf("%d",&N);
                printf("Start Insert\n");
                value = rand();
                iRet=InsertElem(SqList,N,value);
                if(iRet == OK)
                    printf("Insert succed\n");
                else 
                    printf("Insert failed\n");
                break;
            case DeleElement:
                printf("What position will you Delet \n");
                scanf("%d",&N);
                printf("Start Delet\n");
                iRet=DeleElem(SqList,N);
                if(iRet == OK)
                    printf("delet succed\n");
                else 
                    printf("delet failed\n");
                break;
            case LocateElement:
                printf("Which index's result will you Get?\n");
                scanf("%d",&N);
                printf("Start Find\n");
                iRet=LocateElem(SqList,N,&value);
                if(iRet == OK)
                    printf("Return result Value is %d\n",value);
                else 
                    printf("Find error\n");
                break;
            case FindLocateValue:
                printf("What value will you find \n");
                scanf("%d",&value);
                printf("Start Find\n");
                iRet=FindLocate(SqList, value,&N);
                if(iRet == OK)
                    printf("Find succed\n");
                else
                    printf("Find failed\n");
                break;
            case ShowList:
                ListShow(SqList);
                break;
            default :
                printf("No OPs\n");
                break;
        }
        else
        {
            break;
        }
        
    }
    free(SqList);
    return OK;
}
Status InitList(pList *L){
    int i=0;
    *L=malloc(sizeof(List));
    if(*L== NULL)
        return ERROR;
    (*L)->length=0;
    for(;i<RANDNUM;i++)
        (*L)->data[i]=i+1;
    (*L)->length=RANDNUM;  
  
    return OK;
}
Status ListEmpty(pList L){
    if(L == NULL){
        printf("The Pointer is Null\n");
        return ERROR;
    }
    if(L->length == 0)
        printf("The List is Empty\n");
    else 
        printf("The List is not Empty\n");
    return OK;
}
Status ClearList(pList L){
    int i=0;
    if(L== NULL){
        printf("The Pointer is Null\n");
        return ERROR;       
    }
    if(L->length == 0)
        return OK;
    
    for(;i<L->length;i++)
        L->data[i]=0;
    L->length = 0;
    printf("Clear List\n");
    return OK;
}
Status GetLength(pList L){
    if(L== NULL){
        printf("The Pointer is Null\n");
        return ERROR;       
    }
    printf("The List length is %d \n",L->length);
    return OK;
}
Status InsertElem(pList L, int N, int value){
    int j;
    if(L== NULL){
        printf("The Pointer is Null\n");
        return ERROR;       
    }
    if(L->length == 0)
    {
        printf("The List is Null\n");
        return ERROR;
    }
    if( N> MAXSIZE||N > L->length || N <= 0)
    {
        printf("The inset index is error \n");
        return ERROR;
    }
    for(j=L->length;j>=N;j--)
            L->data[j]=L->data[j-1];
    L->data[j]=value;
    L->length++;
    return OK;
}
Status DeleElem(pList L, int N){
    int j;
    if(L== NULL){
        printf("The Pointer is Null\n");
        return ERROR;       
    }
    if( N> MAXSIZE||N > L->length || N <= 0)
    {
        printf("The inset index is error \n");
        return ERROR;
    }
    printf("The deleted value is %d\n",L->data[N-1]);
    for(j=N-1;j<L->length-1;j++)
        L->data[j]=L->data[j+1];
    L->data[j]=0;
    L->length--;
    return ERROR;
}
Status LocateElem(pList L, int N,int *value){
    if(L== NULL){
        printf("The Pointer is Null\n");
        return ERROR;       
    }
    if( N> MAXSIZE||N > L->length || N <= 0)
    {
        printf("The inset index is error \n");
        return ERROR;
    }
    *value=L->data[N-1];
    return OK;
}
Status FindLocate(pList L, int value,int *N){
    int j=0;
    if(L== NULL){
        printf("The Pointer is Null\n");
        return ERROR;       
    }
    for(;j<L->length;j++)
        if(L->data[j] == value){
            printf("Value Matched\n");
            *N=j+1;
            return OK;
        }
    
    printf("Value Not Matched\n");
    return ERROR;
}

Status ListShow(pList L){
    int j=0;
    if(L== NULL){
        printf("The Pointer is Null\n");
        return ERROR;       
    }
    if(L->length==0){
        printf("The List is NUll\n");
        return ERROR;
    }
    printf("The List Length is %d\n",L->length);
    for(;j<L->length;j++){
        printf("%d ",L->data[j]);
    }
    printf("\n");
    return OK;
}



Status help(){
    
    printf("\nWhat will you do next for our List\n"
    "********************************************\n"
    "-1-------------------------------------Empty\n"
    "-2-------------------------------------Clear\n"
    "-3-------------------------------------GetListLength\n"
    "-4-------------------------------------InsertElement\n"
    "-5-------------------------------------DeleElement\n"
    "-6-------------------------------------LocateElement\n"
    "-7-------------------------------------FindLocateValue\n" 
    "-8-------------------------------------ShowList\n"
    "-default-------------------------------Quit\n"
    "please input a opreate number here:"
    );
    return OK;
}
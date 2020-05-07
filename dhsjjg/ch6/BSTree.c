#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OK 0
#define ERROR 1
typedef int ElementType;
typedef int Status;
typedef struct bitree{
    ElementType data;
    struct bitree *lchild;
    struct bitree *rchild;
}Bitree,*pBitree;

Status SearchBST(pBitree T,ElementType n);
Status InsertBst(pBitree *T,ElementType n);
Status DeleteBst(pBitree *T,ElementType value);
Status CreateBST(pBitree *T,int number);
Status PreOrderTraverse(pBitree T);
Status InOrderTraverse(pBitree T);
Status PostOrderTraverse(pBitree T);
Status DeleteNode(pBitree *T);
int main(int argc, char **argv){
    pBitree PbsTree;
    CreateBST(&PbsTree,10);
    InOrderTraverse(PbsTree);
    printf("\n");
    return 0;
}
Status CreateBST(pBitree *T,int number){
    int value=0;
 
    for(;0<number;number--){
        value=rand()%36+number;
        InsertBst(&(*T),value);
    }
    return OK;
}
Status SearchBST(pBitree T,ElementType n){
    if(!T){
        printf("failed search\n");
        return ERROR;
    }
    else if(T->data == n){
        printf("find it \n");
        return OK;
    }
    else if(n < T->data){
       return SearchBST(T->lchild,n);
    }
    else{
        return SearchBST(T->rchild,n);
    }
}
Status InsertBst(pBitree *T,ElementType n){

    if(!(*T)){
            printf("Insert succed\n");
            (*T)=malloc(sizeof(Bitree));
            (*T)->data=n;
            (*T)->lchild=NULL;
            (*T)->rchild=NULL;
            return OK;
    }
    else if ( (*T)->data < n ){
        return InsertBst(&(*T)->rchild,n);
    }
    else if( (*T)->data > n ){
        return InsertBst(&(*T)->lchild,n);
    }
    else
    {
        printf("dup value cann't insert\n");
        return ERROR;
    }
    
}
Status DeleteBst(pBitree *T,ElementType value){
    if(!(*T)){
        printf("No such Node to delete\n");
        return ERROR;
    }
    if((*T)->data == value){
       return DeleteNode(&(*T));
    }
    else if(value < (*T)->data){
        return DeleteBst(&(*T)->lchild,value);
    }
    else {
        return DeleteBst(&(*T)->rchild,value);
    }
}
Status DeleteNode(pBitree *T){
    pBitree temp,par;
    if((*T)->lchild ==  NULL){
        temp=*T;
        *T=(*T)->rchild;
        free(temp);
    }
    else if((*T)->rchild == NULL){
        temp=*T;
        *T=(*T)->lchild;
        free(temp);
    }
    else{
        par=(*T);
        temp=(*T)->lchild;
        while(temp->rchild){
            par = temp;
            temp=temp->rchild;
        }
        (*T)->data=temp->data;
        if(par != (*T))
        {
            par->rchild=temp->lchild;
        }
        else{
            par->lchild=temp->lchild;
        }
        free(temp);
    }
    return OK;
}
Status PreOrderTraverse(pBitree T){
    if(T!=NULL){
        printf("%d\t",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
        return OK;
    }
    return ERROR;
}
Status InOrderTraverse(pBitree T){
    if(T!=NULL){
        InOrderTraverse(T->lchild);
        printf("%d\t",T->data);
        InOrderTraverse(T->rchild);
        return OK;
    }
    return ERROR;
}
Status PostOrderTraverse(pBitree T){
    if(T!=NULL){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d\t",T->data);
    }
}
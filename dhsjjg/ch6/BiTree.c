#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OK 0
#define ERROR 1
typedef char ElementType;
typedef int Status;

typedef struct bitree{
    ElementType data;
    struct bitree *lchild;
    struct bitree *rchild;
}Bitree,*pBitree;

Status CreateBiTree(pBitree *T);
Status PreOrderTraverse(pBitree T);
Status InOrderTraverse(pBitree T);
Status PostOrderTraverse(pBitree T);

Status main(int argc, char ** argv){
    pBitree pTRoot;
    CreateBiTree(&pTRoot);
    printf("PreOderTraverse BiTree\n");
    PreOrderTraverse(pTRoot);
    return OK;
}
Status CreateBiTree(pBitree *T){
    ElementType ch;

    scanf("%c",&ch);

    if(ch == '#'){
        *T=NULL;
        return OK;
    }
    else{
        (*T)=malloc(sizeof(Bitree));
        (*T)->data=ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
        return OK;
    }
}
Status PreOrderTraverse(pBitree T){
    if(T!=NULL){
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
        return OK;
    }
    return ERROR;
}
Status InOrderTraverse(pBitree T){
    if(T!=NULL){
        InOrderTraverse(T->lchild);
        printf("%c",T->data);
        InOrderTraverse(T->rchild);
        return OK;
    }
    return ERROR;
}
Status PostOrderTraverse(pBitree T){
    if(T!=NULL){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c",T->data);
    }
}
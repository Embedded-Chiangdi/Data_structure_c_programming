#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1

typedef int ElemType;
typedef int Status;

typedef struct node{
ElemType data;
struct node *next;
}Node,*LinkList;

//typedef struct Node *LinkList;

enum OP{
    op_isEmpty=1,
    op_clearLink,
    op_showLink,
    op_insertNode,
    op_deletNode,
    op_getLength,
    op_revert,
    op_max
};

Status LinkCreate(LinkList *L,int n);
Status LinkCreate1(LinkList *L,int n);
Status LinkIsEmpty(LinkList L);
Status LinkLength(LinkList L);
Status LinkClear(LinkList L);
Status LinkShow(LinkList L);
Status LinkNodeInsert(LinkList L, int index,int value);
Status LinkNodeDele(LinkList L, int index);
Status help();
Status LinkRevert(LinkList L);

int main(int argc , char **argv[]){
    LinkList pLinkHead;
    Status iRet=-1;
    int N=-1;
    int op=-1;

    printf("How many nodes(No more than 10) will you addNode to LinkList:  ");
    scanf("%d",&N);
    iRet=LinkCreate(&pLinkHead,N);
    if(iRet){
        printf("Init Failed\n");
        return ERROR;
    }
        printf("Init Succed;\n");
    LinkShow(pLinkHead);
    while(1)
    {
        help();
        scanf("%d",&op);
        if(op > 0 && op < op_max){
            switch(op)
            {
            case op_isEmpty:
                LinkIsEmpty(pLinkHead);
                break;
            case op_clearLink:
                LinkClear(pLinkHead);
                break;
            case op_showLink:
                LinkShow(pLinkHead);
                break;
            case op_insertNode:
                printf("which index will u insert");
                scanf("%d",&N);
                LinkNodeInsert(pLinkHead,N,rand()%100+1);
                break;
            case op_deletNode:
                printf("which index will u dele");
                scanf("%d",&N);
                LinkNodeDele(pLinkHead,N);
                break;
            case op_getLength:
                LinkLength(pLinkHead);
                break;
            case op_revert:
                LinkRevert(pLinkHead);
            default:
                break;
            }
            printf("*********************************\n");
        }
        else{
            printf("Quit\n");
            break;
        }
        
    }
    
    LinkClear(pLinkHead);
    free(pLinkHead);
    return OK;
}
//头插法
Status LinkCreate(LinkList *L,int n){
    int i=0;
    LinkList temp;
    *L = malloc(sizeof(Node));
    if(*L == NULL){
        printf("allocate memory failed\n");
        return ERROR;
    }
    (*L)->next=NULL;
    for(;i<n;i++){
        temp = malloc(sizeof(Node));
        if(temp == NULL){
            printf("allocate memory failed\n");
            return ERROR;
        }
        temp->data=rand()%100+1;
        temp->next=(*L)->next;
        (*L)->next=temp;  
    }
    return OK;
}   
Status LinkCreate1(LinkList *L,int n){
    int i=0;
    LinkList temp1,temp2;
    
    *L = malloc(sizeof(Node));
    if(*L == NULL){
        printf("allocate memory failed\n");
        return ERROR;
    }
    (*L)->next=NULL;
    temp2=(*L);
    for(;i<n;i++){
        temp1 = malloc(sizeof(Node));
        if(temp1 == NULL){
            printf("allocate memory failed\n");
            return ERROR;
        }
        temp1->data=rand()%100+1;
        //temp1->next=NULL;
        temp2->next=temp1;
        temp2=temp1;  
    }
    temp2->next=NULL;
    return OK;
}

Status LinkIsEmpty(LinkList L){
    int i=0;
    LinkList temp;
    if(L == NULL){
        printf("Ptr is Null\n");
        return ERROR;
    }
    temp= L->next;
    while(temp)
    {
        temp=temp->next;
        i++;
    }
    if(i == 0){
        printf("The LinkList is Null\n");
        return OK;
    }
    printf("The LinkList is not Null\n");
    return i;
}
Status LinkLength(LinkList L){
    int i=0;
    LinkList temp;
    if(L == NULL){
        printf("Ptr is Null\n");
        return ERROR;
    }
    temp= L->next;
    while(temp)
    {
        temp=temp->next;
        i++;
    }
    printf("The length of this Link is %d\n",i);
    return i;
}
Status LinkClear(LinkList L){
    LinkList temp1,temp2;
    
    if(L==NULL){
        printf("ptr is NULL\n");
        return ERROR;
    }
    temp1=L->next;
    L->next=NULL;
    while (temp1)
    {
        temp2=temp1->next;
        free(temp1);
        temp1=temp2;
    }
    printf("Link Clear\n");
    return OK;

}
Status LinkShow(LinkList L){
    LinkList temp;
    if(L == NULL)
    {
        printf("Ptr is Null\n");
        return ERROR;
    }
    temp=L->next;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return OK;
}
Status LinkNodeInsert(LinkList L, int index,int value){
    LinkList temp;
    LinkList addNode;
    int i=-1;
    if(L == NULL)
    {
        printf("Ptr is Null\n");
        return ERROR;
    }
    if(index <= 0 || index > LinkLength(L)){
        printf("The index is not propertly!\n");
        return ERROR;
    }
    temp=L;
    for(i=1;i<index;i++)
        temp=temp->next;
    addNode = malloc(sizeof(Node));
    addNode->data=value;
    addNode->next=temp->next;
    temp->next=addNode;
    return OK;
}
Status LinkNodeDele(LinkList L, int index){
    LinkList temp1,temp2;
    int i=-1;
    if(L == NULL)
    {
        printf("Ptr is Null\n");
        return ERROR;
    }
    if(index <= 0 || index > LinkLength(L)){
        printf("The index is not propertly!\n");
        return ERROR;
    }

    temp1=L;
    for(i=1;i<index;i++)
        temp1=temp1->next;
    temp2=temp1->next;
    temp1->next=temp1->next->next;
    free(temp2);
}
Status help(){
 printf(
"-----------Operation Table-------\n"
"-1---------isEmpty---------------\n"
"-2---------clearLink-------------\n"
"-3---------showLink--------------\n"
"-4---------insertNode------------\n"
"-5---------deletNode-------------\n"
"-6---------getLength-------------\n"
"-7---------revert----------------\n"
"Which will you choose："
 );
}
Status LinkRevert(LinkList L){
    LinkList pre=NULL;
    LinkList current=L->next;
    LinkList temp=NULL;
    while(current){
        temp=current->next;
        current->next=pre;
        pre=current;
        current=temp;
    }
    L->next=pre;
    return OK;
}
// typedef int ItemType;
// typedef struct node{
//     ItemType data;
//     struct node *next;
// }Node,*pList;

// pList init_link();
// int insert_node_to_link(pList List_head);
// int dele_node_of_link(pList List_head);
// pList addNode_multi_node_to_link(pList List_head);
// int show_link(pList List_head);
// int clear_link(pList List_head);
// int length_link(pList List_head);


// int main(int argc,char *argv[])
// {
//     pList head;
//     pList end;
//     head=init_link();
//     end=addNode_multi_node_to_link(head);
//     length_link(head);
//     show_link(head);
//     insert_node_to_link(head);
//     length_link(head);
//     show_link(head);
//     dele_node_of_link(head);
//     length_link(head);
//     show_link(head);
//     clear_link(head);
//     return 0;
// }
// int dele_node_of_link(pList List_head){
//     pList t=List_head;
//     pList dele_node;
//     int length=length_link(List_head);
//     int p_to_dele;
//     int i;

//     printf("Please input the positon of link you wanna dele\n");
//     scanf("%d",&p_to_dele);
//     if(p_to_dele>length)
//     {
//         printf("dele failed \n");
//         printf("what you wanna to dele is far than our list\n");
//         return 1;
//     }
//     else
//     {
//         for(i=1;i<p_to_dele;i++)
//             t=t->next;
//         dele_node=t->next;
//         t->next=dele_node->next;
//         free(dele_node);
//         printf("dele successed \n");
//         return 0;
//     }

// }
// int length_link(pList List_head){
//     int len=0;
//     pList t=List_head->next;
//     while(NULL != t){
//         len++;
//         t=t->next;
//     }
//     printf("The length of list is %d\n",len);
//     return len;
// }
// int clear_link(pList List_head){
//     pList t;
//     if(List_head!=NULL)
//     {
//         t=List_head;
//         List_head=t->next;
//         free(t);
//     }  
//     printf("clear\n");
//     return 0;
// }
// int show_link(pList List_head){
//     pList t=List_head->next;
//     if(t == NULL)
//     {
//         perror("link list is empty\n");
//         return 1;
//     }
//     for(;t!=NULL;t=t->next)
//         printf("%d\t",t->data);
//         printf("\n");
    
//     return 0;
// }
// pList addNode_multi_node_to_link(pList List_head){
//     int numbers_of_node;
//     pList t=List_head;
//     pList addNode_node;
//     printf("How many numbers do u want to store in this link\n");
//     scanf("%d",&numbers_of_node);
//     for(;t->next !=NULL;t=t->next);
//     for(;numbers_of_node>0;numbers_of_node--)
//     {
//         addNode_node=malloc(sizeof(Node));
//         if(addNode_node == NULL)
//         {
//             perror("addNode node to list failed\n");
//             exit(1);
//         }
//        printf("Please type your data to Link List\n");
//        scanf("%d",&addNode_node->data);

//        addNode_node->next= t->next;
//        t->next=addNode_node;
//        t=addNode_node;
//     }
//     t->next=NULL;
//     return t;
// }
// int  insert_node_to_link(pList List_head){
    
//     pList t=List_head;
//     pList addNode_node;
//     int i,p_to_insert,length;
//     length=length_link(List_head);
//     printf("Please input which positon do u wanna to insert this number\n");
//     scanf("%d",&p_to_insert);

//     addNode_node=malloc(sizeof(Node));
//     if(addNode_node ==NULL)
//         {
//             perror("addNode node to link failed");
//             exit(1);
//         }
//     printf("Please type your data to Link List\n");
//     scanf("%d",&addNode_node->data);
//     if(p_to_insert > length)
//     {
//         printf("you position number is longer than out link , so we put it on the last\n");
//         for(;t->next!=NULL;t=t->next);
//         addNode_node->next=t->next;
//         t->next=addNode_node;
//         return 0;
//     }
//     else
//     {
//         for(i=1;i<p_to_insert;i++)
//             t=t->next;
//         addNode_node->next=t->next;
//         t->next=addNode_node;
//         return 0;
//     }
    
// }
// pList init_link(){
//     pList head;
//     head = malloc(sizeof(Node));
    
//     if (head == NULL ){
//         perror("Init Like lisk failed");
//         exit(1);
//     }
//     head->next=NULL;
//     head->data=0;
//     printf("Init link list successd\n");
//     return head;
// }
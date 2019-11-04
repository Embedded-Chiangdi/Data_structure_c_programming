#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ItemType;

typedef struct node{
    ItemType data;
    struct node *next;
    struct node *perv;
}Node,*pList;

int check_memory_allocate(pList allocate_mem);


pList init_DbLink_list();
int add_node_to_Dblink_list(pList pHead);

int show_DbLink_list(pList pHead);
int clear_DbLink_list(pList pHead);
int length_DbLink_list(pList pHead);

int insert_node_to_Dblink_list(pList pHead);
int dele_node_from_Dblink_list(pList pHead);



int main(int argc, char *argv[]){
    pList Head_Db;
    printf("01. Init Doubly link list \n");
    Head_Db=init_DbLink_list();
    printf("02. Add node to doubly link list\n");
    if(add_node_to_Dblink_list(Head_Db)){
        perror("add node to doubly link list failed \n");
        exit(1);
    }
    length_DbLink_list(Head_Db);
    show_DbLink_list(Head_Db);

    insert_node_to_Dblink_list(Head_Db);
    length_DbLink_list(Head_Db);
    show_DbLink_list(Head_Db);

    dele_node_from_Dblink_list(Head_Db);
    length_DbLink_list(Head_Db);
    show_DbLink_list(Head_Db);
    clear_DbLink_list(Head_Db);
    
    return 0;
}
int check_memory_allocate(pList allocate_mem){
    if(allocate_mem == NULL){
         perror("failed to init Dblink list\n");
         return 1;
    }
    return 0;
}
pList init_DbLink_list(){
    pList pnew;
    pnew=malloc(sizeof(Node));
    if(check_memory_allocate(pnew) == 1)
        exit(1);

    pnew->next=NULL;
    pnew->perv=NULL;
    pnew->data=0;
    return pnew;

}
int add_node_to_Dblink_list(pList pHead){
    int length;
    int i,num;
    pList pprev=pHead,pnew;
    printf("pleast type how many numbers do u wanna input\n");
    scanf("%d",&length);

    for(i=0;i<length;i++){
        pnew = malloc(sizeof(Node));
        if(check_memory_allocate(pnew) == 1)
            exit(1);
        
        printf("please input data:");
        scanf("%d",&num);
        pnew->data=num;
        pnew->next=pprev->next;
        pprev->next=pnew;
        pnew->perv=pprev;
        pprev=pnew;
        //printf("\n");
        
    }
    return 0;
}
int show_DbLink_list(pList pHead){
    pList t=pHead->next;
    printf("Now Start print The Double link list\n");
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    
    }
    printf("\n");
    return 0;
}
int length_DbLink_list(pList pHead){
    pList t=pHead->next;
    int length=0;
    
    while(t != NULL)
    {
        length++;
        t=t->next;
    }
    printf("The length of this list is %d\n",length);
    return length;
}

int clear_DbLink_list(pList pHead){
    pList t=pHead;
    pList dele_node;
    while(t!=NULL)
    {
        dele_node=t;
        t=t->next;
        free(dele_node);
    }
    printf("Link clear \n");
    return 0;
}

int insert_node_to_Dblink_list(pList pHead){
    int p_to_insert;
    int i;
    int lengthoflist;
    pList t=pHead,ins_node;
    lengthoflist=length_DbLink_list(t);
    printf("where do u wanna to insert a number \n");
    scanf("%d",&p_to_insert);
    if(p_to_insert>lengthoflist){
        printf("you printed a failed number much longer than our list\n");
        return 1;
    }
    for(i=1;i<p_to_insert;i++)
        t=t->next;
    ins_node=malloc(sizeof(Node));
    printf("please type the data you wanna insert:");
    scanf("%d",&ins_node->data);
    ins_node->next=t->next;
     t->next->perv=ins_node;
    ins_node->perv=t;
    t->next=ins_node;
    return 0;
}
int dele_node_from_Dblink_list(pList pHead){
    int p_to_dele;
    int i;
    int lengthoflist;
    pList t=pHead,dele_node;
    lengthoflist=length_DbLink_list(t);
    printf("where do u wanna to delete a number \n");
    scanf("%d",&p_to_dele);
    if(p_to_dele>lengthoflist){
        printf("you printed a failed number much longer than our list\n");
        return 1;
    }
    for(i=1;i<p_to_dele;i++)
        t=t->next;
    
    dele_node=t->next;
    t->next=dele_node->next;
    dele_node->next->perv=t;
    free(dele_node);
    return 0;
}
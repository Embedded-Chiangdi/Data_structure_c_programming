#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ItemType;

typedef struct node{
    ItemType data;
    struct node *next;
}Node,*pList;

pList init_link();
int insert_node_to_link(pList List_head);
int dele_node_of_link(pList List_head);
pList add_multi_node_to_link(pList List_head);
int show_link(pList List_head);
int clear_link(pList List_head);
int length_link(pList List_head);


int main(int argc,char *argv[])
{
    pList head;
    pList end;
    head=init_link();
    end=add_multi_node_to_link(head);
    length_link(head);
    show_link(head);
    insert_node_to_link(head);
    length_link(head);
    show_link(head);
    dele_node_of_link(head);
    length_link(head);
    show_link(head);
    clear_link(head);
    return 0;
}
int dele_node_of_link(pList List_head){
    pList t=List_head;
    pList dele_node;
    int length=length_link(List_head);
    int p_to_dele;
    int i;

    printf("Please input the positon of link you wanna dele\n");
    scanf("%d",&p_to_dele);
    if(p_to_dele>length)
    {
        printf("dele failed \n");
        printf("what you wanna to dele is far than our list\n");
        return 1;
    }
    else
    {
        for(i=1;i<p_to_dele;i++)
            t=t->next;
        dele_node=t->next;
        t->next=dele_node->next;
        free(dele_node);
        printf("dele successed \n");
        return 0;
    }

}
int length_link(pList List_head){
    int len=0;
    pList t=List_head->next;
    while(NULL != t){
        len++;
        t=t->next;
    }
    printf("The length of list is %d\n",len);
    return len;
}
int clear_link(pList List_head){
    pList t;
    if(List_head!=NULL)
    {
        t=List_head;
        List_head=t->next;
        free(t);
    }  
    printf("clear\n");
    return 0;
}
int show_link(pList List_head){
    pList t=List_head->next;
    if(t == NULL)
    {
        perror("link list is empty\n");
        return 1;
    }
    for(;t!=NULL;t=t->next)
        printf("%d\t",t->data);
        printf("\n");
    
    return 0;
}
pList add_multi_node_to_link(pList List_head){
    int numbers_of_node;
    pList t=List_head;
    pList add_node;
    printf("How many numbers do u want to store in this link\n");
    scanf("%d",&numbers_of_node);
    for(;t->next !=NULL;t=t->next);
    for(;numbers_of_node>0;numbers_of_node--)
    {
        add_node=malloc(sizeof(Node));
        if(add_node == NULL)
        {
            perror("add node to list failed\n");
            exit(1);
        }
       printf("Please type your data to Link List\n");
       scanf("%d",&add_node->data);

       add_node->next= t->next;
       t->next=add_node;
       t=add_node;
    }
    t->next=NULL;
    return t;
}
int  insert_node_to_link(pList List_head){
    
    pList t=List_head;
    pList add_node;
    int i,p_to_insert,length;
    length=length_link(List_head);
    printf("Please input which positon do u wanna to insert this number\n");
    scanf("%d",&p_to_insert);

    add_node=malloc(sizeof(Node));
    if(add_node ==NULL)
        {
            perror("add node to link failed");
            exit(1);
        }
    printf("Please type your data to Link List\n");
    scanf("%d",&add_node->data);
    if(p_to_insert > length)
    {
        printf("you position number is longer than out link , so we put it on the last\n");
        for(;t->next!=NULL;t=t->next);
        add_node->next=t->next;
        t->next=add_node;
        return 0;
    }
    else
    {
        for(i=1;i<p_to_insert;i++)
            t=t->next;
        add_node->next=t->next;
        t->next=add_node;
        return 0;
    }
    
}
pList init_link(){
    pList head;
    head = malloc(sizeof(Node));
    
    if (head == NULL ){
        perror("Init Like lisk failed");
        exit(1);
    }
    head->next=NULL;
    head->data=0;
    printf("Init link list successd\n");
    return head;
}
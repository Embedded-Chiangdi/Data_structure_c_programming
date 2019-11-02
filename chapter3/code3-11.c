#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct node *plink;
typedef struct node link;
struct node {
    int item;
    plink next;
};

int main(int argc, char *argv[]){
    link list1;
    plink temp_node1,head1,head2;
    head1=&list1;
    int i;
    head1->item=rand()%100;
    for(i=0,temp_node1=head1;i<N;i++)
    {
        temp_node1->next=malloc(sizeof(link));
        temp_node1=temp_node1->next; temp_node1->next=NULL;
        temp_node1->item=rand()%100;
    }
    //printf("%d\n",head1->item);
    //printf("%d\n",temp_node1->item);

    
    
    
    return 1;
}
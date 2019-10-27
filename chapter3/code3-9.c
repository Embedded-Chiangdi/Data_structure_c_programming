#include <stdio.h>
#include <stdlib.h>

typedef struct node *plink;
typedef struct node link;
struct node {
    int item;
    plink next;
};
int main(int argc, char *argv[]){
    int i,N,M;
    plink h,x;
    if(3 != argc)
        {
            printf("Usage : Josephus Function N M\n");
            printf("N means N persons , M means who you want to out when he was counted\n");
            return 1;
        }
    N = atoi(argv[1]);
    M = atoi(argv[2]);

    h=malloc(sizeof(link));
    x=h;
    h->item=1;
    h->next=h;

    for(i=2;i<=N;i++)
    {
        x=(x->next=malloc(sizeof(link)));
        x->item=i;
        x->next=h;
    }
    while(x!=x->next){
        for(i=1;i<M;i++)
        x=x->next;
        x->next=x->next->next;
        N--;
    }
    printf("The choses number is %d",x->item);
    return 0;
}
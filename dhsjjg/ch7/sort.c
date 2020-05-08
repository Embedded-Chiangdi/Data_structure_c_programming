#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OK 0
#define ERROR 1
#define MAXSIZE 10

typedef int ElementType;
typedef int Status;
typedef struct _SortList{
    ElementType array[MAXSIZE+1];
    int length;
}SortList,*PSortList;

Status InitList(PSortList* L);
Status ShowList(PSortList L);

Status BubleSort1(PSortList L);
Status BubleSort2(PSortList L);
Status BubleSort3(PSortList L);
void swap(PSortList L,int i,int j);

Status SelectSort(PSortList L);
Status InsertSort(PSortList L);

Status ShellSort(PSortList L);
Status ShellSort1(PSortList L);

int main(int argc,char** argv){
    PSortList List;
    InitList(&List);
    printf("Before Sort:\t");
    ShowList(List);
    printf("After Sort:\t");
   
    ShellSort1(List);
    // InsertSort(List);

    // SelectSort(List);

    // BubleSort1(List);
    // BubleSort2(List);
    // BubleSort3(List);

    ShowList(List);

    return OK;
}
Status InitList(PSortList* L){
    int i=MAXSIZE;
    *L=malloc(sizeof(SortList));
    (*L)->length=0;
    for(;i>0;i--){
        (*L)->array[i]=rand()%200-i;
        (*L)->length++;
    }
    
    return OK;
}
Status ShowList(PSortList L){
    int i=1;
    for(;i <= L->length;i++)
        printf("%d\t",L->array[i]);
    printf("\n");
    return OK;
}
Status BubleSort1(PSortList L){
    int i,j;

    for(i=1;i<L->length;i++){
        for(j=i;j<L->length;j++){
            if(L->array[i] > L->array[j+1]){
                swap(L,i,j+1);
            }
        }

    }
    return OK;
}
Status BubleSort2(PSortList L){
    int i,j;
    for(i=L->length;i>0;i--){
        for(j=1;j<i;j++){
            if(L->array[j]>L->array[j+1]){
                swap(L,j,j+1);
            }
        }
    }
    return OK;
}
Status BubleSort3(PSortList L){
    int i,j;
    Status flag=1;
    for(i=L->length;i>0 && flag;i--){
        flag=0;
        for(j=1;j<i;j++){
            if(L->array[j]>L->array[j+1]){
                swap(L,j,j+1);
                flag=1;
            }
        }
    }
    return OK;
}

Status SelectSort(PSortList L){
    int i,j;
    int min;
    for(i=1;i<L->length;i++){
        min = i;
        for(j=i+1;j<=L->length;j++){
            if(L->array[min] > L->array[j]){
               min = j;
            }
        }
        if(min != i)
        {
            swap(L,min,i);
        }
    }
    return OK;
}
void swap(PSortList L,int i,int j){
    L->array[0]=L->array[i];
    L->array[i]=L->array[j];
    L->array[j]=L->array[0];
}
Status InsertSort(PSortList L){
    int i,j;
    for(i=1;i < L->length; i++)
        if(L->array[i] > L->array[i+1]){
            L->array[0]=L->array[i+1];
            
            for(j=i;j>0 && L->array[j] > L->array[0]; j--){
                L->array[j+1]=L->array[j];
            }
            L->array[j+1]=L->array[0];
        }
        
    return OK;
}
Status ShellSort(PSortList L){
    int i,j,gap;
    gap=L->length;
    do{
        gap/=2;
        for(i=1;i+gap <= L->length;i++)
            if(L->array[i] > L->array[i+gap]){
                L->array[0]=L->array[i+gap];
                for(j=i;j>0 && L->array[j] > L->array[0];j-=gap){
                    L->array[j+gap]=L->array[j];
                }
                L->array[j+gap]=L->array[0];
            }
    }while(gap>1);
    return OK;
}

Status ShellSort1(PSortList L){
    int i, j, gap;
    gap=L->length;
    do{
        gap=gap/2;
        for(i=gap+1;i<=L->length;i++)
            if(L->array[i] < L->array[i-gap]){
                L->array[0]=L->array[i];
                for(j=i-gap;j>0 && L->array[j] > L->array[0];j-=gap)
                    L->array[j+gap]=L->array[j];
                 L->array[j+gap]=L->array[0];    
            }
    }while(gap>1);
}
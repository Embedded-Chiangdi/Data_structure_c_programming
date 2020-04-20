#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define OK 0
#define Error 1

typedef int Status;
Status StringReverse(char *s);

int main(int argc, char **argv){
    char StringTest1[]="Jiangs";
    puts("before Reverse:\n");
    puts(StringTest1);
    StringReverse(StringTest1);
    puts("After Reverse:\n");
    puts(StringTest1);
    return OK;
}
Status StringReverse(char *s){
    char *s1,*s2;
    char temp;
    s1=s;
    s2=s+strlen(s)-1;
    while(s1<s2){
        temp=*s1;
        *s1++=*s2;
        *s2--=temp;
    }
    return 0;
}
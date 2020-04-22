#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define OK 0
#define Error 1

typedef int Status;

Status StringReverse(char *s);
Status LongestPalindrome(char * s);
Status expandSearch(char *s,int left,int right,int *start,int* maxlen,int length);
int main(int argc, char **argv){
    char StringTest1[]="Jiangs";
    char StringTest2[]="aba";
    
    LongestPalindrome(StringTest2);
    return OK;
    
    
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
Status LongestPalindrome(char * s){
    int i=0;
    int maxLength=0;
    int length=0;
    int start=0;
    length=strlen(s);
    for(;i<length-1;i++){
        printf("i=%d,maxlength=%d\n",i,maxLength);
        expandSearch(s,i,i,&start,&maxLength,length);
        expandSearch(s,i,i+1,&start,&maxLength,length);

    }
    
    if(maxLength > 0){
        printf("find the longest\n");
        printf("The Longest Palindrome is %d\n",maxLength);   
        for(i=start;i<maxLength;i++)
            putchar(s[i]);
        putchar('\n');
        return OK;
    }
    printf("There is no Palindrome\n");
    return Error;
}
Status expandSearch(char *s,int left,int right,int *start,int* maxlen,int length){

    while(left >= 0 && right < length  && s[left] == s[right]){
        // putchar(s[left]);
        // putchar('\t');
        // putchar(s[right]);
        // putchar('\t');
        left--;
        right++;
    }
    putchar('\n');
    if(right - left - 1 > (*maxlen)){
        *start=left+1;
        *maxlen=right-left - 1;
        //printf("left =%d right =%d\nmaxlength is %d",left,right,*maxlen);
    }
    return OK;
}
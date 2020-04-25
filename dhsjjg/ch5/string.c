#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define OK 0
#define Error 1

typedef int Status;

Status StringReverse(char *s);
Status LongestPalindrome(char * s);
Status expandSearch(char *s,int left,int right,int *start,int* maxlen,int length);

Status longestOfLengthSubstring(char *s);
Status isExistCharacter(int index,char *start,char *temp);

Status longestCommonSubsequence(char * text1, char * text2);
Status reverseLeftWords(char* s, int n);

int main(int argc, char **argv){
    char StringTest1[]="Jiangs";
    char StringTest2[]="abcabcd";
    char StringTest3[]="abcedf";
    char StringTest4[]="adf";

    reverseLeftWords(StringTest1, 2);
    return OK;
    longestCommonSubsequence(StringTest3,StringTest4);
    return OK;
    longestOfLengthSubstring(StringTest2);
    return OK;
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

Status longestOfLengthSubstring(char *s){
    int i=0,j=0,maxLength=0;
    char *start;
    char *tstart;
    if(strlen(s) < 2 ){
        printf("The length of string is short\n");
        return Error;
    }
    start=s;
    for(i=0;i<strlen(s);i++){
        tstart=s+i;
        for(j=i+1;j<strlen(s);j++){
                if(isExistCharacter(j-i,tstart,s+j)){
                    
                    if(i==0 && maxLength < j-i){
                        maxLength=j-i;
                        start=s+i;
                        i=j-1;
                        
                        break;}
                }
                else if(maxLength < j-i +1){
                    maxLength=j-i+1;
                    start=s+i;
                    i=j-1;
                    break;
                }

        }
    }
    if(maxLength == 0)
        return Error;
    printf("The maxLength is %d\nThe LongestSubString is : ",maxLength);
    for(i=0;i<maxLength;i++){
        putchar(start[i]);
    }
    putchar('\n');
    return OK;
}

Status isExistCharacter(int index,char *start,char *temp){
    int i=0;
    for(;i<index;i++){
        if(start[i]==*temp){
            return Error;
        }
    }
    return OK;
}
Status longestCommonSubsequence(char * text1, char * text2){
    int i;
    int maxLength=0;
    char *s1 = text1;
    char *s2 =text2;

    while(*s1 && *s2){
        if(*s2 == *s1){
            s2++;
            maxLength++;
        }
        s1++;
    }
    if(maxLength == 0){
        printf("failed\n");
        return Error;
    }
    printf("maxLength is %d\n longest common sub string is : ",maxLength);
    for(i=0;i<maxLength;i++)
        putchar(text2[i]);
        
        putchar('\n');
    return OK;
}
Status reverseLeftWords(char* s, int n){
    char *temp;
    char *pStr=s;
    int i=0;
    temp = malloc(n+1);
    strncpy(temp,s,n);
    for(;i<strlen(s)-n;i++)
        *pStr++=*(pStr+n);
    strncpy(pStr+1,temp,n);
    printf("%s",s);
}
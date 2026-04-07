#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define size 256
int table[size];
void shifttable(char p[10]){
    int i,m=strlen(p);
    for(i=0;i<size;i++){
        table[i]=m;
    }
    for(i=0;i<m-1;i++){
        table[p[i]]=m-1-i;
    }

}
int harspool(char T[50],char p[10]){
    int i,k,m=strlen(p),n=strlen(T);
    shifttable(p);
    i=m-1;
    while(i<n){
        k=0;
        while(k<m && p[m-1-k]==T[i-k]){
            k++;
        }
        if(k==m){
            return i-m+1;
        }
        else{
            i=i+table[T[i]];
        }
    }
    return -1;
}
int main()
{
    int i,r;
    char p[10],T[50];
    printf("Enter Pattern:");
    scanf("%s",p);
    printf("Enter Text:");
    scanf("%s",T);
    r=harspool(T,p);
    if(r==-1){
        printf("Pattern not found");
    }
    else{
        printf("Pattern found at position %d",r);
    }
    return 0;
}

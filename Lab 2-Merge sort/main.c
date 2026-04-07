#include <stdio.h>
#include <stdlib.h>
int count;
void merge(int a[10],int l,int m,int r){
    int i=l,j=m+1,k=l,b[10];
    while(i<m+1 && j<=r){
        count++;
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=m){
        b[k++]=a[i++];
    }
    while(j<=r){
        b[k++]=a[j++];
    }
    for(i=l;i<=r;i++){
        a[i]=b[i];
    }
}
void mergesort(int a[10],int l,int r){
    int m;
    if(l<r){
        m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int n,a[10],i;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("Sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nTotal comparisions=%d",count);
    return 0;
}

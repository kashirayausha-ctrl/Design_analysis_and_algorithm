#include <stdio.h>
#include <stdlib.h>
int count;
int partition(int a[10],int l,int r){
    int pivot=a[l],i=l+1,j=r,t;
    while (1){
        while(pivot>=a[i] && i<=r){
            i++;
            count++;
        }
        while(pivot<a[j]){
            j--;
            count++;
        }
        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        else{
            t=a[l];
            a[l]=a[j];
            a[j]=t;
            return j;
        }
    }
}
void quicksort(int a[10],int l,int r){
    int s;
    if(l<r){
        s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
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
    quicksort(a,0,n-1);
    printf("Sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nTotal comparisions=%d",count);
    return 0;
}

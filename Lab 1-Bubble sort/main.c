#include <stdio.h>
#include <stdlib.h>
int count;
void bubble(int a[10],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
                count++;
            if(a[j]>a[j+1]){
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
}
int main(){
    int i,a[10],n;
    printf("Enter size of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element %d:",i+1);
    scanf("%d",&a[i]);
    }
    bubble(a,n);
    printf("Sorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    printf("Number of times comparison executed:%d",count);
    return 0;
}

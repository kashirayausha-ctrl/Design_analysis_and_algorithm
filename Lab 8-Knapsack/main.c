#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    int x[10]={0},i,j,n,W,w[10],p[10],v[10][10];
    printf("Enter number of objects:");
    scanf("%d",&n);
    printf("Enter knapsack capacity:");
    scanf("%d",&W);
    printf("Enter weights of object\n");
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter profits of object\n");
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0){
                v[i][j]=0;
            }
            else if(j-w[i]<0){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);

            }
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    i=n;
    j=W;
    while(i!=0 && j!=0){
        if(v[i][j]!=v[i-1][j]){
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    printf("Max profit is:%d",v[n][W]);
    printf("\nObjects\tWeight\tProfit\n");
    for(i=1;i<=n;i++){
        if(x[i]==1){
            printf("%d\t%d\t%d\n",i,w[i],p[i]);
        }
    }
    return 0;
}

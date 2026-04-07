#include <stdio.h>
#include <stdlib.h>
void BFS(int a[10][10],int n,int visited[10],int source){
    int q[10],f=0,r=-1,i,del;
    q[++r]=source;
    visited[source]=1;
    while(f<=r){
        del=q[f++];
        for(i=0;i<n;i++){
            if(a[del][i]==1 && visited[i]==0){
                q[++r]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int n,a[10][10],i,j,count=0,visited[10];
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter element a[(%d)][%d]:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0;i<n;i++){
        if(visited[i]==0){
            BFS(a,n,visited,i);
            count++;
        }
    }
    if(count==1){
        printf("Graph is connected and has %d components",count);
    }
    else{
        printf("Graph is not connected and has %d components",count);
    }
}

// BFS code
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void BFS(int adj[MAX][MAX],int V,int s){
    int q[MAX];
    int front=0;
    int rear=0;
    
    bool visited[MAX]={false};
    q[rear++]=s;
    visited[s]=true;
    
    while(front<rear){
        int curr=q[front++];
        printf("%d ",curr);
        
        for(int i=0;i<V;i++){
            if(adj[curr][i]==1 && !visited[i]){
                q[rear++]=i;
                visited[i]=true;
            }
        }
    }
    
    
}

void addEdge(int adj[MAX][MAX],int u,int v){
    adj[u][v]=1;
    adj[v][u]=1;
}

int main(void){
    int V=5;
    int adj[MAX][MAX]={0};
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    
    printf("BFS TRAVERSAL IS:\n");
    BFS(adj, V, 0);
}


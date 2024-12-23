// DFS TRAVERSAL PROGRAM:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
void DFS(int adj[MAX][MAX],int V,int s, bool visited[MAX]){
   
    visited[s]=true;
    printf("%d ",s);
    for(int i=0;i<V;i++){
        if(adj[s][i]==1 && !visited[i]){
            DFS(adj,V,i,visited);
        }
    }
}

void addEdge(int adj[MAX][MAX],int u,int v){
    adj[u][v]=1;
    adj[v][u]=1;
}

int main(void){
    int adj[MAX][MAX]={0};
    bool visited[MAX]={false};
    int V=7;
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 3, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 1, 6);
    addEdge(adj, 4, 6);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 5);
    
    printf("DFS TRAVERSAL:\n");
    DFS(adj, V, 0,  visited);
    
}

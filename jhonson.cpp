/* Caso de prueba:
6
7
0 1 -5
1 2 -7
1 4 2
2 5 -3
3 0 -6
4 3 50
5 4 1
*/

#include <bits/stdc++.h>
using namespace std;
#define inf 9999
#define MAX 1000

struct Edge{
    int u,v,w;
};

void bellman_ford(int n, int m, int *d, Edge *edges){
    for(int i=0;i<n;i++)
        d[i]=0;
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(d[edges[j].u]+edges[j].w<d[edges[j].v])
                d[edges[j].v]=d[edges[j].u]+edges[j].w;
        }
    }
}

void dijkstra(int G[MAX][MAX],int n,int startnode){
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cost[i][j]=G[i][j];
    
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1)
    {
        mindistance=inf;
        for(i=0;i<n;i++){
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i]){
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }

 for(i=0;i<n;i++)
        if(i!=startnode)
        {
            cout<<endl<<"Distancia al nodo "<<i<<" : "<<distance[i]<<endl;
            cout<<"Path : "<<i;
            j=i;
            do
            {
                j=pred[j];
                printf(" <- %d",j);
            }while(j!=startnode);
    }
}

void jhonson(int k,int n,int m, int *d, Edge *edges){
    bellman_ford(n,m,d,edges);
    for(int i=0;i<k;i++){
        edges[i].w=edges[i].w+d[edges[i].u]-d[edges[i].v];
    }
    int aux=-99999;
    int src;
    for(int i=0;i<m;i++){
        if(d[edges[i].u]>d[edges[i].v]&&aux<d[edges[i].u]){
            aux=d[edges[i].u];
            src=edges[i].u;
        }
        if(d[edges[i].u]>d[edges[i].v]&&aux<d[edges[i].v]){
            aux=d[edges[i].v];
            src=edges[i].v;
        }
    }
    
    int G[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=inf;
        }
    }
    for(int i=0;i<m;i++){
        G[edges[i].u][edges[i].v]=edges[i].w;
    }
    
    cout<<"Inicio Dijkstra: "<<src<<endl;
    dijkstra(G,n,src);
}

int main(){
    freopen("in.txt","r",stdin);
    int n, m;
    int u,v,w;
    int i;
    cin>>n>>m;
    Edge edges[m];
    int d[n];
    
    for(i=0;i<m;i++){
        cin>>u>>v>>w;
        edges[i].u=u;
        edges[i].v=v;
        edges[i].w=w;
    }
    
    jhonson(i,n,m,d,edges);
    return 0;
}

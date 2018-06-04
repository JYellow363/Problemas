/* Caso de prueba
5
0 6 0 7 0
0 0 5 8 -4
0 -2 0 0 0
0 0 -3 0 9
2 0 7 0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define inf 99999

struct Edge{
    int u,v,w;
};

void bellman_ford(int s, int n, int *d, Edge *edges){
    for(int i=0;i<n;i++)
        d[i]=inf;
    d[s]=0;
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(d[edges[j].u]+edges[j].w<d[edges[j].v])
                d[edges[j].v]=d[edges[j].u]+edges[j].w;
        }
    }
    
    for(int i=0;i<n;i++){
        if(d[i]!=inf)
            cout<<"De "<<s<<" a "<<i<<": "<<d[i]<<endl;
    }
}

int main(){
    int n,w;
    int k=0;
    freopen("in.txt","r",stdin);
    cin>>n;
    Edge edges[n]; //largo de las aristas;
    int d[n]; //mínima distancia entre s y los vértices
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w;
            if(w!=0){
            edges[k].u=i;
            edges[k].v=j;
            edges[k].w=w;
            k++;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
    int source=0;
    bellman_ford(source, n, d, edges);
}

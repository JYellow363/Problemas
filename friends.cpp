#include <bits/stdc++.h>
using namespace std;

class UFDS{
    private:
        int n;
        int *rank;
        int *parent;
        int *elemento;
        
    public:
        UFDS(int n){
            this->n=n;
            rank=new int[n];
            parent=new int[n];
            elemento=new int[n];
            for(int i=0;i<n;i++){
                rank[i]=0;
                parent[i]=i;
                elemento[i]=1;
            }
        }
        
        int find(int a){
            if(parent[a]==a) return a;
            else find(parent[a]);
        }
        
        void union_find(int a, int b){
            int x=parent[a];
            int y=parent[b];
            if(x!=y){
                if(rank[x]>rank[y]){
                    parent[y]=x;
                    rank[x]++;
                    elemento[x]+=elemento[y];
                }
                else{
                     parent[x]=y;
                     rank[y]++;
                     elemento[y]+=elemento[x];
                }
            }
        }
        
        int max_elementos(){
            int max=0;
            for(int i=0;i<n;i++)
                if(elemento[i]>max) max=elemento[i];
            return max;
        }
        
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    int n,m,a,b;
    cin>>cases;
    for(int i=0;i<cases;i++){
        cin>>n>>m;
        UFDS g(n+1);
        for(int j=0;j<m;j++){
            cin>>a>>b;
            g.union_find(a,b);
        }
        cout<<g.max_elementos()<<endl;
    }
    return 0;
}

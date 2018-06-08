/*Caso de prueba
4 10
2 3
5 4
9 8
4 6
*/

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b)? a : b;
}

struct Objeto{
    int w;
    int v;
};

void ordenar(vector<Objeto> obj){
    for(int i=0;i<obj.size();i++){
        for(int j=i;j<obj.size();j++){
            if(obj[i].w>obj[j].w){
            int aux=obj[i].w; obj[i].w=obj[j].w; obj[j].w=aux;
            aux=obj[i].v; obj[i].v=obj[j].v; obj[j].v=aux;
            }
        }
    }
}

void knapsack(vector<Objeto> obj, int n, int wmax){
    ordenar(obj);
    int K[n + 1][wmax + 1];
    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= wmax; w++){
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else{
                if (obj[i - 1].w <= w)
                    K[i][w] = max(obj[i - 1].v + K[i - 1][w - obj[i - 1].w], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
            }
        }
    }
    //Imprimir K
    cout<<"\t\t|\t";
    for(int i=0;i<=wmax;i++)
        cout<<i<<"\t";
    cout<<endl<<"---------------------";
    for(int i=0;i<=wmax;i++)
        cout<<"--------";
    cout<<endl;
    for (int i = 0; i <= n; i++){
        if(i==0) cout<<"(w = 0, v = 0)\t|\t";
        else cout<<"(w = "<<obj[i-1].w<<", v = "<<obj[i-1].v<<")\t|\t";
        for (int w = 0; w <= wmax; w++){
            cout<<K[i][w]<<"\t";
        }
        cout<<endl;
      }
   cout<<endl<<"Valor máximo en mochila: "<<K[n][wmax];
}

int main(){
    int n, wmax, _w, _v;
    freopen("in.txt","r",stdin);
    cin>>n>>wmax;cout<<endl;
    vector<Objeto> obj(n);
    for(int i=0;i<n;i++){
        cin>>_w>>_v;
        obj[i].w=_w;
        obj[i].v=_v;
    }
    knapsack(obj, n, wmax);
    return 0;
}

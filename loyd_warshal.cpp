#include <bits/stdc++.h>

using namespace std;
#define INF 99999

void dibujar(vector<vector<int>> v) {
    cout<<"    |"<<"\t";
    for(int i=0;i<v.size();i++)
        cout<<i<<"\t";
        cout<<endl;
    cout<<"------------------------------------"<<endl;
	for (int i = 0;i<v.size();i++) {
		cout << i << "   |"<<"\t";
		for (int j = 0;j<v.size();j++) {
		    if(i==j) cout<<"-\t";
			else{
			if (v[i][j] == INF)  cout << "inf\t";
			if (v[i][j] != INF) cout << v[i][j] << "\t";
			}
		}
		cout << endl;
	}
}

void floyd_warshal(vector<vector<int>> v, int n){
    vector<vector<int>> dist;
    vector<vector<int>> recor;
    
    //iniciar vector de vector
    vector<int> aux;
    for (int i = 0;i < n;i++)
	    aux.push_back(INF);

	for (int i = 0;i < n;i++){
		dist.push_back(aux);
		recor.push_back(aux);
	}
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        recor[i][j]=j;
	    }
	}
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=v[i][j];
            
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    recor[i][j]=k;
                }
            }
        }
    }
    cout<<"Tabla de Distancia: "<<endl<<endl;
    dibujar(dist);
    cout<<endl;
     cout<<"Tabla de Recorrido: "<<endl<<endl;
    dibujar(recor);
}

/*
Caso de prueba
4
5
0 1 3
0 2 4
1 3 5
2 3 3
3 0 8
*/

int main() {
	int a, b, w, m, n;
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	
	//iniciar vector de vector
	vector<vector<int>> v;
	vector<int> aux;
	
	for (int i = 0;i < n;i++)
		aux.push_back(INF);
	
	for (int i = 0;i < n;i++)
		v.push_back(aux);
		
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(i==j) v[i][j]=0;
    }
	
	//insertar aristas
	for (int i = 0;i<m;i++) {
		cin >> a >> b >> w;
		v[a][b]=w;
		//v[b][a]=w;
	}
	floyd_warshal(v,n);
	return 0;
}

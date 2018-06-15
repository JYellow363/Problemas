/*
Caso de prueba: 
6 9
0 1 1
0 3 1
1 2 1
1 3 1
2 4 1
2 5 1
3 4 1
3 5 1
4 5 1
*/

#include <bits/stdc++.h>
using namespace std;

int aux[1000][1000];
int matriz[1000][1000];

int encontrar_pos(vector<vector<int>> v, int num) {
	for (int i = 0; i < v.size(); i++)
		if (find(v[i].begin(), v[i].end(), num) != v[i].end())
			return i;
	return -1;
}

int unir(vector<vector<int>> v) {
	int n = v.size();
	int a, b;
	while (v.size() > 2) {
		a = rand()%n;
		b = rand()%n;
		int posa = encontrar_pos(v, a);
		int posb = encontrar_pos(v, b);
		if (aux[a][b] != 0 && a != b&&posa!=posb) {
			aux[a][b] = 0;
			aux[b][a] = 0;
			for (int w = 0; w < v[posb].size(); w++)
				v[posa].push_back(v[posb][w]);
			v.erase(v.begin() + posb);
		}
	}
	for (int i = 0; i<v.size(); i++) {
		cout << "Set " << i + 1 << " : ";
		for (int j = 0; j<v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	int f = 0;
	for (int i = 0; i < n; i++) {
			for (int k = 0; k < v[0].size(); k++) {
				if(find(v[0].begin(),v[0].end(),i)==v[0].end())
				f+=matriz[v[0][k]][i];
			}
	}
	cout << "k = "<<f << endl << endl;
	return f;
}


int main() {
	int n, m, a, b, c;
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			matriz[i][j] = 0;

	for (int i = 0; i<m; i++) {
		cin >> a >> b >> c;
		matriz[a][b] = c;
		matriz[b][a] = c;
	}
	int kmin = 99999;
	for (int j = 0; j < 500; j++) {
		vector<vector<int>> v(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				aux[i][j] = matriz[i][j];
		}
		for (int i = 0; i < n; i++)
			v[i].push_back(i);
		int kaux = unir(v);
		if (kaux < kmin) kmin = kaux;
	}
	cout << "K min: " << kmin;
	return 0;
}

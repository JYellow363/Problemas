/*
Caso de prueba:
15
5
3
6
2
1
4
*/

#include <bits/stdc++.h>
using namespace std;

int encontrar_pos(vector<vector<int>> v, int num) {
	for (int i = 0; i < v.size(); i++)
		if (find(v[i].begin(), v[i].end(), num) != v[i].end())
			return i;
	return -1;
}

bool man_orden(int i, int j) { return i > j; }


int unir(vector<int> numeros, vector<vector<int>> v, int dist) {
	int distaux = dist;
	int n = v.size();
	int precio[1000];
	int a, b;
	while (v.size() > 2) {
		a = numeros[rand() % numeros.size()];
		b = numeros[rand() % numeros.size()];
		int posa = encontrar_pos(v, a);
		int posb = encontrar_pos(v, b);
		if (a != b&&posa != posb) {
			for (int w = 0; w < v[posb].size(); w++)
				v[posa].push_back(v[posb][w]);
			v.erase(v.begin() + posb);
		}
	}

	for (int i = 0; i<v.size(); i++) {
		sort(v[i].begin(), v[i].end(),man_orden);
		precio[v[i][0]] = distaux;
		distaux -= v[i][0];
	}
	int comprobante = 0;
	for (int i = 0; i < v.size(); i++) {
		comprobante += v[i][0];
		for (int j = 1; j < v[i].size(); j++) {
			precio[v[i][j]] = precio[v[i][j-1]]-v[i][j-1];
		}
	}
	if (comprobante <= dist) {

		for (int i = 0; i < v.size(); i++) {
			cout << "Set " << i + 1 << " : ";
			for (int j = 0; j < v[i].size(); j++)
				cout << v[i][j] << " ";
			cout << endl;
		}
		int preciototal = 0;
		cout << endl;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << "Precio de " << v[i][j] << " : " << precio[v[i][j]] << endl;
				preciototal += precio[v[i][j]];
			}
		}
		cout << endl << "Precio total: " << preciototal << endl << endl;
		return preciototal;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	int m, n;
	cin >> m >> n;
	vector<vector<int>> v(n);
	vector<vector<int>> aux(n);
	vector<int> numeros;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i].push_back(a);
		numeros.push_back(a);
	}

	int mincost=9999;
	for (int k = 0; k < 500; k++) {
		aux = vector<vector<int>>(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < v[i].size(); j++)
				aux[i].push_back(v[i][j]);
		if(mincost>unir(numeros, aux, m))
			mincost=unir(numeros, aux, m);
		aux.clear();
	}
	cout << "Precio min: " << mincost;
	return 0;
}

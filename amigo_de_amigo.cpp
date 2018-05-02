#include <bits/stdc++.h>

using namespace std;

class Grafo {
private:
	list<int> *listAd;
	int n = 10;
	int cont = 0;
	void DFS_util(int s, bool visited[]) {
		visited[s] = true;
		cont++;
		list<int>::iterator it;
		for (it = listAd[s].begin();it != listAd[s].end();it++) {
			if (visited[*it] == false)
				DFS_util(*it, visited);
		}
	}

public:
	Grafo(int n) {
		this->n = n;
		listAd = new list<int>[n];
	}
	void add_edge(int a, int b) {
			listAd[a].push_back(b);
			listAd[b].push_back(a);
	}

	void DFS(int s) {
		bool *visited = new bool[n];
		for (int i = 0;i<n;i++)
			visited[i] = false;
		DFS_util(s, visited);
	}

	void amigos() {
		int max = 0;
		for (int i = 0;i<n;i++) {
			DFS(i);
			if (max<cont) max = cont;
			cont = 0;
		}
		cout << max << endl;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casos;
	int n, m;
	int a, b;
	cin >> casos;
	for (int i = 0;i<casos;i++) {
		cin >> n >> m; //número de personas y número de líneas
		Grafo g(n+1);
		for (int j = 0;j<m;j++) {
			cin >> a >> b;
			g.add_edge(a, b);
		}
		g.amigos();
	}

	return 0;
}

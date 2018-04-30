//Código para Visual Studio
//Crear archivos int62.txt y out62.txt

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace System;
using namespace std;

vector<vector<int>> G;

int main()
{
	
	freopen("in62.txt", "r", stdin);
	freopen("out62.txt", "w", stdout);
	int casos;
	cin >> casos;
	vector<int> v;
	string s;
	for (int i = 0; i < casos; i++) {
		getline(cin, s);
		getline(cin, s);
		getline(cin, s);
		getline(cin, s);
		for (int j = 0; j < s.size(); j++)
			if (s[j] != ' ') v.push_back(s[j]-65);
	}

	int *incoming = new int[20];
	for (int i = 0; i < 20; i++) {
		incoming[i] = 0;
	}

	for (int i = 0; i < 20; i++) {
		vector<int> v;
		G.push_back(v);
	}

	getline(cin, s);
	G[s[0] - 65].push_back(s[2] - 65); incoming[s[2] - 65]++;
	G[s[4] - 65].push_back(s[6] - 65); incoming[s[6] - 65]++;

	queue<int> q;
	for (int i = 0; i < v.size(); i++) {
		if (incoming[v[i]] == 0) {
			q.push(v[i]);
			break;
		}
	}

	vector<int> rpta;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		rpta.push_back(u);
		for (int i = 0; i<G[u].size(); i++) {
			int v = G[u][i];
			incoming[v]--;
			if (incoming[v] == 0) {
				q.push(v);
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (find(rpta.begin(), rpta.end(), v[i]) == rpta.end()) {
			for (int j = 0; j < v.size(); j++) {
				vector<int> aux = rpta;
				aux.insert(aux.end()-j,v[i]);
				for (int k = 0; k < aux.size(); k++) {
					cout << char(aux[k]+65) << "  ";
				}
				cout << endl;
			}
		}
	}

    return 0;
}

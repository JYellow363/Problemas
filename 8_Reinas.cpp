// 8reinas.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include<vector>
#include <conio.h>

using namespace System;
using namespace std;

bool j = true;
bool fin = false;
int n = 8;
int u, w;

void imprimir(int **mapa) {
	cout << "   0  1  2  3  4  5  6  7" << endl << endl;
	for (int i = 0; i<n; i++) {
		cout << i << "  ";
		for (int j = 0; j<n; j++) {
			if (mapa[i][j] == 0) cout << char(176) << "  ";
			if (mapa[i][j] == 1) cout << "X" << "  ";
		}
		cout << endl << endl;
	}
	cout << endl;
}

bool es_posible(int **m, int ii, int jj) {
	for (int i = 0; i < n; i++) {
		if (m[i][jj] == 1) return false;
	}
	for (int j = 0; j < n; j++) {
		if (m[ii][j] == 1) return false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != ii || j != jj) {
				if (m[i][j] == 1) return false;
			}
		}
	}
	return true;
}

void _encontrar_espacio(int ii, int jj, vector<pair<int, int>> v,int **m) {
	if (v[v.size() - 1].first == n - 1 && v[v.size() - 1].second == n - 1) fin = true;
	if (fin == false) {
		for (int i = ii; i<n-1; i++) {
			for (int j = jj; j<n-1; j++) {
				vector<pair<int, int>> aux = v;
				int **a = new int*[n];
				for (int i = 0; i < n; i++)
					a[i] = new int[n];
				a = m;
				bool b = false;
				if (es_posible(a, i, j + 1) == true && b == false && j + 1 < n) {
					aux.push_back(make_pair(i, j + 1));
					_encontrar_espacio(i, j + 1, aux,a);
					u = i;
					w = j + 1;
					b = true;
				}
				if (es_posible(a, i+1, j) == true && b == false && i + 1<n) {
					aux.push_back(make_pair(i + 1, j));
					_encontrar_espacio(i + 1, j, aux,a);
					u = i+1;
					w = j;
					b = true;
				}
			}
		}
	}
}

void encontrar_espacio(int **mapa) {
	vector<pair<int, int>> v;
	v.push_back(make_pair(0, 0));
	_encontrar_espacio(0, 0, v,mapa);
}

int main() {
	int **mapa = new int*[n];
	for (int i = 0; i < n; i++)
		mapa[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mapa[i][j] = 0;
		}
	}
	imprimir(mapa);
	int a, b;
	char turno;
	while (j == true) {
		while (true) {
			cout << "Turno jugador (fila - columna)" << endl;
			cin >> a >> b;
			if (mapa[a][b] == 0&&es_posible(mapa,b,a)) break;
		}
		mapa[a][b] = 1;
		cout << endl;
		imprimir(mapa);
		encontrar_espacio(mapa);
		fin = false;
		b = false;
		if (mapa[u][w] != 0) break;
		cout << u << " " << w << endl << endl;
		mapa[u][w] = 1;
		cout << endl << "Turno de la computadora (fila - columna)" << endl << endl;
		imprimir(mapa);
	}
	cout << "Fin del juego" << endl;
	getch();
	return 0;
}

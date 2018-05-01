// 5_de_23.cpp: archivo de proyecto principal.
//Código para Visual Studio
//Crear "in.txt" y "out.txt"

//Caso de prueba
/*
Entrada:
1 1 1 1 1
1 2 3 4 5
2 3 5 7 11
0 0 0 0 0

Salida:
Imposible
(((1+3)*4)+2)+5=23
(((2+7)-5)*3)+11=23
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace System;

void imprimir(vector<string> s) {
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	cout << "=23";
	cout << endl;
}

int signo(int num1, int num2, string s) {
	if (s == "+") return num1 + num2;
	if (s == "*") return num1 * num2;
	if (s == "-") return num1 - num2;
}

int comprobar(vector<string> s) {
	return signo(signo(signo(signo(stoi(s[1]), stoi(s[3]),
		s[2]), stoi(s[6]), s[5]), stoi(s[9]), s[8]), stoi(s[12]), s[11]);
}

bool b = true;

void cinco_de_23(vector<int> v, vector<int> v1, vector<int> v2, vector<string> s,int num) {

	if (v1.size() <= v.size()&&b==true) {
		for (int i = 0; i < v2.size(); i++) {

			vector<int> aux1=v1;
			vector<int> aux2=v2;
			vector<string> auxs=s;

			aux1.push_back(aux2[i]);
			aux2.erase(aux2.begin() + i);

			if (num == 1) auxs.push_back("+");
			if (num == 2) auxs.push_back("*");
			if (num == 3) auxs.push_back("-");
			
			auxs.push_back(to_string(aux1.back()));
			if (v1.size()==0||v1.size()==v.size()-1) {}
			else auxs.push_back(")");

			if ((aux1.size() == v.size())&&comprobar(auxs)==23) {
				imprimir(auxs);
				b = false;
			}

			cinco_de_23(v, aux1, aux2, auxs, 1); //suma
			cinco_de_23(v, aux1, aux2, auxs, 2); //producto
			cinco_de_23(v, aux1, aux2, auxs, 3); //resta
		}
	}
}


void operacion(vector<int> v) {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < v.size(); i++)
		if (find(v1.begin(), v1.end(), v[i]) == v1.end()) v2.push_back(v[i]);
	vector<string> s;
	s.push_back("(((");
	cinco_de_23(v, v1, v2, s, 0);
	if (b == true) cout << "Imposible" << endl;
	b = true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (true) {
		vector<int> v(5);
		for (int i = 0; i < 5; i++)
			cin >> v[i];
		if (v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0 && v[4] == 0) break;
		operacion(v);
	}
	return 0;
}

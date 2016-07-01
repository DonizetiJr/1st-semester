/*
É mais uma tarde ensolarada e sangrenta em Midgard. Após mais uma longa batalha, as valquírias 
estão descendo de Asgard novamente para levar os valentes guerreiros para Valhalla. O problema 
é que nem todos estão realmente mortos, e os não mortos começaram a se pendurar nos guerreiros mortos, 
desejando também ir para Valhalla. Tudo começou a ficar mais complicado ainda quando os não mortos 
começaram a se pendurar em não-mortos, e, pra piorar, em mais de um ao mesmo tempo.

As Valquírias, comandadas por Randgris, têm poder infinito. Entretanto, elas desejam saber 
quanto peso cada uma delas irá carregar no caminho para Valhalla, dado o peso de cada guerreiro e onde eles se penduram.

Input
A entrada começa com dois números, V (1 ≤ V ≤ 103), o número de valquírias, G (1 ≤ G ≤ 104), 
o número de guerreiros. Os guerreiros e valquírias são identificados pro números. Os índices de 0 a V - 1 
são valquírias, e os G seguintes índices são guerreiros. Seguem então G linhas. Cada linha começca com um 
inteiro E (1 ≤ E ≤ 100), o número de guerreiros/valquírias no qual o g-ésimo guerreiro está pendurado. 
Seguem E índices, cada um representando um índice ao qual o g-ésimo guerreiro está pendurado. 
Um guerreiro pendurado em uma valquíria não se pendura em outros guerreiros (ele está morto), 
e um guerreiro pendurado em outros guerreiros não se pendura em uma valquíria.

Finalmente, seguem G linhas, cada uma com inteiro P (1 ≤ P ≤ 100), o peso do g-ésimo guerreiro.

Output
Imprima uma linha para cada valquíria, em ordem de índices, contendo o peso total que ela carrega.


*/
//Basta fazer uma DFS

#include <bits/stdc++.h>

using namespace std;

const int G = 10000;
const int V = 1000;
vector<int> g[G+V];
int vis[G + V];
int peso[G];
int v, n, r;

void dfs (int x) {
	vis[x] = 1;
	if (x >= v) {
		r += peso[x-v];
	}
	for (int i = 0; i < g[x].size(); ++i) 
		if (!vis[g[x][i]]) dfs(g[x][i]);
}

int main (void) {
	cin >> v >> n;
	for (int i = 0; i < n; ++i) {
		int b, e; cin >> e;
		for (int j = 0; j < e; ++j) {
			cin >> b; 
			g[b].push_back(v + i);
		}
	}
	for (int i = 0; i < n; ++i) cin >> peso[i];
	for (int i = 0; i < v; ++i) {
		r = 0;
		dfs(i);
		cout << r << endl;
	}
	return 0;
}

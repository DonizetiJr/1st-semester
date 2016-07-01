/*
Nifflhein está um caos. Algum herói mitológico largou bombas relógio em todos os portões do inferno, 
e agora está esperando, à sombra de Yggdrasil, que elas comecem a detonar para atravessar o inferno.

Kina, nosso herói, tem um mapa de Nifflhein. Ele quer chegar da posição 0 do mapa (Yggdrasil) ao último 
portão (n - 1). Cada portão é representado como uma aresta. Kina também sabe o tempo em que cada portão irá explodir. 
Kina só irá sair da sombra de Yggdrasil quando o caminho inteiro estiver aberto!

Em qual tempo Kina irá sair?

Input
A entrada começa com dois inteiros, n e m (1 ≤ n ≤ 103), (). Os vértices do mapa de Kina estão numerados 
de 0 a n - 1. Seguem m linhas, cada uma com 3 inteiros: i, j e t (0 ≤ i, j < n), (1 ≤ t ≤ 109), 
os índices de dois vértices que um portão conecta, e t, o tempo que ele irá explodir.

Output
Imprima o tempo que Kina irá sair da sombra de Yggdrasil.

Para resolver esse problema, bastava notar que se é possível chegar do início ao fim no tempo T, 
é possível chegar em todos os tempos menores que T. Isso nos permite utilizar uma BUSCA BINÁRIA — e, 
em cada tempo, usar somente os portões já abertos até esse tempo. 
Para ver se há caminho basta usar uma DFS.
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
vector<int> g[N], o[N];
int vis[N];

int reach (int x, int T) {
	vis[x] = 1;	
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (!vis[y] and o[x][i] <= T) reach(y, T);
	}
}

int main (void) {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		g[a].push_back(b);//lista "g" guarda as arestas
		g[b].push_back(a);
		o[a].push_back(t);//lista "o" guarda os tempos que as adjacencias abrem
		o[b].push_back(t);
	}

	int lo = 0, hi = 1e9;
	while (lo < hi) {
		int mi = (lo + hi)/2;
		memset(vis, 0, sizeof vis);
		reach (0, mi);
		if (vis[n-1]) hi = mi;
		else lo = mi + 1;
	}
	cout << lo << endl;

	return 0;
}

/*
UNION FIND
==========

const int N = 1001;
int g[N];

int find (int x) {
    if (x == g[x]) return x;
    return g[x] = find ( g[x] );
}

void junta (int a, int b) {
    int aa = find (a);
    int bb = find (b);
    if (aa != b) g[aa] = bb;
}

int main (void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) g[i] = i;
    // ordena as arestas
    // vai juntando ate 0 e o n-1 estarem conectados
    // a resposta vai ser o peso da aresta qye conectou por ultimo
}
*/
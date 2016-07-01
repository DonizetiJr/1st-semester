/*
Yggdrasil é a árvore que suporta os mundos. Originalmente, haviam 9 mundos: Asgard, Vanaheim, 
Alfheim, Midgard, Jotunheim, Svartalfheim, Nidavellir, Niflheim e Muspelheim. Entretanto, depois 
dos eventos de Ragnarok, a árvore começou a crescer descontroladamento, dando origem a novos mundos. 
Nesse novo cenário, cada uma das pontas de Yggdrasil deu origem a um novo mundo. Cada um desse mundo 
pode ser classificado entre um mundo de vivos e de mortos. Para um ramo de Yggdrasil não deteriorar, 
a diferença da quantidade de mundos de vivos e mortos suportados por ele deve ser no máximo 2. 
Dado o estado de Yggdrasil, diga se árvore irá deteriorar ou não.

Input
A entrada começa com um número N, (1 ≤ N ≤ 10⁵), indicando o número de vértices da árvore (um vértice 
pode ser um mundo ou uma bifurcação nos ramos). Seguem N - 1 linhas, cada qual com dois inteiros i, j (0 ≤ i, j ≤ N), 
indicando que há um ramo entre os vértices i e j. Para um dado mundo, considere que ele é um mundo dos mortos se 
seu índice for ímpar, e um número dos vivos se seu índice for par. Considere que o centro da árvore é o vértice 0.

Output
Imprima S se a árvore irá deteriorar e N caso contrário.
*/

//Basta fazer um DFS

#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
vector <int> g[N];

bool good = true;

int solve (int x, int p) {
	if (g[x].size() == 2) {
		if (x) return 1;
		else return -1;
	}	
	int bal = 0;
	for (int i = 0; i < g[x].size(); ++i) {
		int v = g[x][i];
		if (v != p) bal += solve (v, x);//evitar voltar para adjacencia anterior
	}	
	if (abs(bal) > 2) good = false;
	return bal;
}

int main (void) {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}	
	solve(0, -1);
	if (good) cout << "N\n";
	else cout << "S\n";
}

/*
		OUTRA OPÇÃO
		===========
#include <bits/stdc++.h>

using namespace std;

const int N = 100001; 
vector<int> g[N];
bool good;

pair<int, int> dfs (int x, int p) {
    pair<int,int> res = { 0, 0 };
    if (g[x].size() == 1) {
        if (x%2) return { 1, 0 } ; // make_pair (1, 0);
        return { 0, 1 } ; // make_pair (0, 1); 
    }
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (y == p) continue;
        pair<int,int> r = dfs (y, x);
        res.first += r.first;
        res.second += r.second;
    }
    if (abs(res.first - res.second) > 2) good = false; 
    return res;
} 


int main (void) {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back (b);
        g[b].push_back (a);
    }
    good = true;
    dfs (0);    
    if (good) cout << "S" << endl;
    else cout << "N" << endl;
}
*/
/*
Considere uma matriz n por n, com os caracteres '#' e '.'. O caractere '#' representa mar, e o 
caractere '.' representa terra. Descubra quantas ilhas há numa matriz. Duas regiões são adjacentes 
se elas compartilham um lado na matriz.

Input
O input começa com um número n 1 ≤ n ≤ 103, o número de linhas e colunas da matriz. 
Seguem n linhas, cada uma com n caracteres.

Output
Imprima a quantidade de ilhas encontradas.

Para resolver esse problema, bastava utilizar várias DFS. Cada DFS marcaria todas as posições 
de uma mesma ilha. Se passarmos pela matriz procurando as ilhas ainda não marcadas, basta 
contar quantas vezes isso ocorre.

Para resolver esse problema, bastava utilizar várias DFS. Cada DFS marcaria todas as posições 
de uma mesma ilha. Se passarmos pela matriz procurando as ilhas ainda não marcadas, basta 
contar quantas vezes isso ocorre.
*/

#include <iostream>
#include <cstring>

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

using namespace std;

const int N = 1001;
char in[N][N];
int vis[N][N];
int n;

bool inside (int i, int j) {
	return i >= 0 and j >= 0 and i < n and j < n;
}

int dfs (int i, int j) {
	vis[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		int ni = i + dir[k][0];
		int nj = j + dir[k][1];
		if (inside(ni, nj) and !vis[ni][nj] and in[ni][nj] == '.') {
			dfs(ni, nj);
		}
	}
}

int main (void) {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> in[i];
	memset (vis, 0, sizeof vis);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!vis[i][j] and in[i][j] == '.') {
				res++; 
				dfs(i, j);
			}
		}
	}
	cout << res << endl;

	return 0;
}
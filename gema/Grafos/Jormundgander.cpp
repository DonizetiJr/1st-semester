/*MAIS FACIL

Na mitologia nórdica, Jörmundgander ou Jormungand é o segundo filho de Loki com a gigante Angrboda, 
e tem forma de serpente. Ela foi jogada ao mar por Odin durante um episódio descrito na Edda em Prosa.

Jörmundgander é chamada de serpente de Midgard, pois é tão grande que diz-se que poderia envolver a terra.

Ragnar, um herói nórdico explorador de oceanos encontrou um mapa antigo que dividia o oceano em quadrantes. 
Alguns quadrantes, marcados com 'X', significavam que havia um pedaço da Jörmundgander passando por aquele quadrado. 
Ragnar gostaria de evitar passar por posições do mar que possuem pedaços de Jörmundgander, pois a serpente é muito perigosa.

Ragnar pode se mover nas direções horizontais e verticais com seu barco, e não pode explorar terras além das estipuladas 
pela região do mapa.

Dado o mapa, descubra se é possível cruzar o mar, saindo da posição (1, 1) - o topo superior esquerdo do mapa e chegando 
na posição final, (N, N).

Repare que não necessariamente os pedaços de Jörmundgander marcados no mapa são contínuos - em alguns trechos do oceano 
a serpente simplesmente não é notada.

Input
O input começa com um número N, o tamanho do mapa (1 ≤ N ≤ 103). Seguem N linhas descrevendo cada uma das linhas do mapa. 
Cada elemento de cada uma das linhas é 'x' se há um pedaço de cauda nessa posição do mapa e '.' caso contrário.

Output
Imprima 'Ragnarok' se for impossível cruzar o mar sem passar por Jörmundgander e 'Odin' caso contrário.

*/
//A solução era uma DFS à partir da posição inicial — 0,0.


#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
string in[N];

bool vis[N][N];

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //para cima, baixo, esquerda, direita
int n;

void dfs (int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = true;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if (nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
        if (in[nx][ny] == 'x') continue;
        dfs (nx, ny);
    }
}

int main (void) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> in[i];
    if (in[0][0] != 'x') dfs (0, 0);
    if (vis[n-1][n-1]) cout << "Odin";
    else cout << "Ragnarok" << endl;
    return 0;
}

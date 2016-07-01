/*Problema A — Rackoon Mario
Por fim, o problema mais difícil da prova. Se você chegou até aqui (alguém chegou? :P), vamos lá que tá acabando.
Nesse problema, temos o mesmo impasse do problema anterior: em uma determinada etapa, precisamos fazer uma decisão.
 A decisão aqui é pegar ou não pegar uma moeda. Porém, dessa vez, estamos interessados no melhor resultado, e não no 
 número de formas de fazer algo. Portanto, podemos escolher apenas o melhor entre duas coisas: pegar ou não pegar a moeda.
Se colocarmos apenas a moeda atual como estado, não sabemos dizer quando iremos começar a voar. Uma coisa que você deve 
reparar para resolver o problema é que, uma vez que começamos a voar, devemos continuar voando até voltar para o chão, 
pegando todas as moedas no caminho. Não há necessidade de fazer decisões durante o o vôo, uma vez que o Mário pega as 
moedas tanto do chão quanto da terra durante esse tempo.
Você pode estar se perguntando por quê podemos decidir deixar uma moeda passar. Basta olhar os casos de exemplo para descobrir — 
podemos tentar atrasar o início do vôo, para aproveitá-lo melhor.
Para saber se começamos a voar, devemos saber quantas moedas já estão no contador. Isso nos remete a dois estados: A moeda em 
que estamos atualmente, e qual o valor do contador de moedas. Vamos novamente chamar nossa solução de F(P, C), uma função do 
valor do contador e da moeda atual.
Aqui, fica fácil dizer o que acontece quando resolvemos não pegar a moeda atual. F(P, C) = F(P + 1, C), ou seja, se não pegamos 
moeda, apenas avançamos para a próxima moeda. Note que se a moeda está voando, essa é a única opção possível!
A parte complicada acontece quando resolvemos pegar a moeda. Se o valor no contador ainda não é o valor do vôo, temos uma chamada s
imples. F(P, C) = max(F(P + 1, C), F(P + 1, C + 1) + 1). O lado esquerdo corresponde à opção de não pegar a moeda — o lado direito 
corresponde à opção de pegar a moeda. Note que somamos um ao resultado do lado direito, pois estamos aumentando nossa resposta em 1 pegando uma moeda.
Se ignorarmos o problema do vôo, ainda temos que tratar os casos base, que são simples nesse problema. Se chegamos na última moeda, 
não podemos fazer mais pontos, então retornamos 0. Ou seja, F(N, C) = 0 , onde N é o número de moedas e C é qualquer valor no contador.
Vamos agora resolver o problema do vôo. Para isso, note que se tentarmos pegar uma moeda e começamos a voar, pegamos todas as moedas 
em uma distância x[P] + D (onde x[P] é a posição da P-ésima moeda). Podemos então fazer um loop para descobrir qual a posição da moeda 
imediatamente posterior ao final do vôo — todas as moedas no caminho serão coletadas. Então, quando começamos a voar, 
temos F(P, C) = max(F(P + 1, C), F(Pvoo, 0) + Mvoo) , onde o lado esquerdo novamente é a escolha de não pegar a moeda que nos 
faria começar a voar. Note que Pvoo pode ser achado com um loop simples à partir da posição atual, e Mvoo é o número de moedas 
coletada durante o vôo.
Para encontrar Pvoo e Mvoo, é possível utilizar uma busca binária. Suponha que você está na i-ésima posição. Vamos chutar que é 
possível chegar até a posição que fica na metade entre o final do vetor e a posição do início do vôo. Se a distância do início 
até a moeda nessa posição for menor que D, sabemos que podemos pegar todas as moedas que estão à esquerda com certeza; se for maior, 
sabemos que não podemos pegar nenhuma à direita.
Essa observação nos permite deixar nossa solução mais rápida.
Segue o código
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4000;
ll in[N][2];
int dp[N][N];
int n, x;
ll d;

int next (int i) {
	int lo = i, hi = n-1;
	while (hi != lo) {
		int mi = (hi + lo + 1)/2;
		ll dist = in[mi][0] - in[i][0];
		if (dist <= d) lo = mi;
		else hi = mi - 1;
	}
	return lo;
}

int solve (int i, int j) {
	if (i == n) {
		return 0;
	}
	int& res = dp[i][j];
	if (res != -1) return res;
	res = solve (i +1, j);
	if (in[i][1]) {
		if (j != x-1) {
			res = max(res, 1 + solve(i + 1, j + 1));
		} else {
			int k = next(i);
			res = (k - i + 1) + solve(k + 1, 0);
		}
	}
	return res;
}

int main (void) {
	memset (dp, -1, sizeof dp);
	cin >> n >> x >> d;
	for (int i = 0; i < n; ++i) {
		cin >> in[i][0] >> in[i][1];
	}
	cout << solve (0, 0) << endl;	
}

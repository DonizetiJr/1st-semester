/*Problema B
Nesse problema, possuímos um conjunto de moedas (das quais temos uma quantidade infinita de cada uma), 
e gostaríamos de saber de quantas formas podemos dar um troco de X.
Por exemplo, se o conjunto de moedas for {2, 3, 6}, e queremos dar um troco de 8, podemos fazer das seguintes maneiras:
2, 2, 2, 2
2, 3, 3
2, 6
Repare que temos que tomar cuidado para não contar várias vezes a mesma combinação. {2, 3, 3} é a mesma maneira de dar troco que {3, 2, 3}, 
uma vez que a ordem não importa.
Como resolvemos esse problema? Uma boa maneira de pensar é tentar todas as combinações possíveis de moedas. Nesse caso, temos que tomar
 cuidado para não gerar combinações que já foram geradas antes. Para fazer isso, vamos utilizar a seguinte invariante: ao utilizar a i-ésima moeda, 
 não iremos utilizar nenhuma moeda que aparece antes no nosso array.
Como isso resolve o problema das repetições? Vamos supor que a sequência seja: {2, 3, 6} novamente. Vamos supor que já utilizamos duas vezes a 
primeira moeda e uma vez a segunda moeda. Como estamos observando a segunda moeda, não iremos mais utilizar moedas que apareceram para trás. 
Isso nos impede de gerar a sequência {2, 2, 3, 2}. Logo, se formos dar um troco utilizando um subconjunto S das moedas, nós iremos gerar apenas
 uma ordem desse subconjunto, que é a ordem em que as moedas aparecem na entrada.
Com essa idéia em mente, ainda temos um problema. Como fazemos para gerar tais conjuntos? Sabemos que precisamos conhecer a moeda que estamos 
olhando atualmente, pois sem essa informação não conseguimos evitar a geração de conjuntos repetidos (leia acima mais uma vez se você não entendeu 
o motivo disso).
O que mais é necessário saber para ser capaz de dar o troco? A quantidade que falta para completar. Vamos pensar então em uma função dessas 
duas variáveis: T (quanto falta para dar de troco) e M (a moeda que estamos olhando atualmente — só podemos utilizar as moedas à partir dessa).
Queremos então calcular F(T, M), que é o número de formas de retornar T de troco podendo utilizar todas as moedas à partir da M-ésima moeda.
Nesse tipo de problema, é comum pensar em quais são as possibilidades dado que estamos em um determinado estado. Aqui, temos duas opções: 
utilizar a M-ésima moeda ou não utilizar.
Vamos supor que resolvemos utilizar a M-ésima moeda. Suponha que o troco atual é 5 e a M-ésima moeda vale 2. Se utilizarmos essa moeda, 
nosso valor de troco cairá para 3, mas ainda podemos utilizar essa moeda mais uma vez. Faz sentido então dizer que, se resolvermos utilizar 
a M-ésima moeda, todas as maneiras de gerar T - v[M] de troco, podendo utilizar todas as moedas à partir da i-ésima também são formas 
de dar T de troco. (aqui, v[M] é o valor da M-ésima moeda).
Uma maneira alternativa de entender esse pensamento é o seguinte. Imagine o conjunto S de todas os conjuntos de de moedas que nos permitem 
devolver T - v[M] de troco. Se as moedas forem {2, 3, 6} e T = 5 e v[M] = 3 (logo, M = 2, temos que S = {} — que é o conjunto de todos 
os conjuntos de moedas que permitem devolver 2 de troco usando todas as moedas que aparecem depois da segunda ou ela mesma. O fato de S
 ser vazio nos indica que é impossível devolver 5 de troco utilizando essas moedas (isso não é difícil de ver). Se, ao invés de T = 5, 
 T valesse 6, teríamos S = {{3}} ou seja, é possível devolver 3 de troco, e só há uma maneira: utilizando a terceira moeda. Logo, para 
 devolver 6 de troco podemos contar todas as formas de devolver 3 de troco. Nesse caso, nosso S para T = 6 seria S = {{3, 3}} 
 (basta adicionar a moeda atual a cada um dos conjuntos que resolvia o problema para o troco restante)!
Quando decidimos não utilizar a moeda atual, o raciocínio é semelhante, porém agora nosso troco não muda, mas M avança no array. 
Logo, temos a fórmula recursiva
F(T, M) = F(T - v[M], M) + F(T, M + 1)
Temos que tomar cuidado com os casos base. Quando o T = 0, dizemos que há 1 maneira de devolver esse troco — que é não devolver nada.
 Quando T < 0 ou M ultrapassa a posição da última moeda, não há nada mais que possamos fazer — então retornamos 0.
Por fim, a última coisa que queremos fazer é calcular o resultado dessa conta — que pode ser muito grande — módulo 109. Para isso,
 utilizamos a operação de mod a cada soma que fazemos — pois assim evitamos que o resultado dê overflow durante as contas. O código 
 pode ser visto abaixo
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2000;
const int M = 1000000000;
int n, m;
int moedas[N];
int dp[N][N];

int solve (int i, int v) {
	if (v > m) return 0;
	if (v == m) return 1;
	if (i == n) return 0;
	int &res = dp[i][v];
	if (res != -1) return res;
	res = solve (i, v + moedas[i]);
	res = (res + solve(i + 1, v))%M;
	return res;
}

int main (void) {
	memset (dp, -1, sizeof dp);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> moedas[i];
	cout << solve(0, 0) << endl;
	return 0;
}
/*
Como em alguns outros problemas, guardamos os resultados parciais em uma matriz 
(pois temos duas variáveis como estados) para evitar calcular coisas que já calculamos.
Fiz um gráfico com todas as chamadas recursivas utilizadas para calcular o resultado para T = 12 
de troco e as moedas {2, 3, 5}. */
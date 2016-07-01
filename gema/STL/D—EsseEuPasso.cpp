/*Problema D — Esse eu Passo
Esse problema pedia para que você descobrisse quantas strings únicas existiam na entrada. 
Diferentemente dos problemas recentes, não é dado o número de strings que você deve ler. 
Quando isso ocorre, você deve ler da entrada padrão enquanto não há mais nada para ser lido.
Usando cin, podemos fazer while (cin >> x). Quando o final do arquivo é atingido, o cin retorna false.
 Usando scanf, você pode fazer while (scanf("%s", s) != EOF) — ou seja — o scanf retorna o valor EOF 
 quando encontra o final de arquivo. Para emular a entrada, você pode executar seu programa com um 
 arquivo no lugar da entrada padrão (./exec < entrada.in — veja mais no post das aulas passadas) ou 
 enviar ctr+D no terminal para simular final de arquivo.
Vamos então para o problema. Queremos contar quantas strings diferentes há no conjunto. 
Inicialmente, você pode pensar em fazer isso:

Le as strings 

int res = 0;
for (int i = 0; i < n; ++i) {
   bool unique = true;
   for (int j = 0; unique and j < i; ++j) {
      if (v[i] == v[j]) unique = false;
   }
}

Aqui, basicamente, estamos comparando cada string com todas que apareceram antes e vendo se há alguma outra ocorrência. 
Dessa forma, toda primeira ocorrência de uma string somamos +1 na resposta. O problema dessa abordagem é que ela é 
muito lenta. Se tivermos n = 105 strings, fazendo esse procedimento temos que percorrer, no caso em que todas as 
strings são únicas, 1 + 2 + ... + n strings, que é n2 (soma da P.A.!) — o que nos dá algo em torno de 1010 operações — 
isso se ignorarmos as operações para comparar que duas strings são iguais.
Espero ter te convencido que essa abordagem é lenta. Se você não está convencido, implemente e teste você mesmo.
A abordagem esperada era armazenar as strings em um set. 

Um set é uma estrutura de dados existente na biblioteca padrão do C++ que nos permite encontrar se um elemento 
está presente nela de forma muito mais rápido do que comparando um a um, utilizando árvores binárias de busca. 
Para referência, para encontrar uma string num set, o set faz no máximo logN comparações — onde N é o número de 
elementos do conjunto.
As operações de inserção, busca e remoção nessa estrutura de dados levam todas tempo proporcional a logN. Além disso, 
ao inserir duas vezes o mesmo valor no set, a segunda inserção será ignorada. Portanto, se inserirmos todas as strings 
em um set e no final pegarmos o número de elementos, temos a resposta!
O código está abaixo:*/

#include <string>
#include <iostream>
#include <set>

using namespace std;

int main (void) {
	string a;
	set<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;

	return 0;
}

/*Um detalhe importante é que não podemos criar um set<char*>. Apesar de possível declarar algo assim, quando são feitas as 
comparaçṍes para encontrar um elemento, um set<char*> irá comparar o valor dos ponteiros — que é um endereço.
É importante lembrar que set e map mantém seus elementos ordenados, utilizando a relação de ordem definida pelo operador <..
 Em C++, esse operador já é definido por padrão para strings, e nada mais é que a comparação alfabética entre as duas strings.
O número de operações realizado no final por essa solução é proporcional a NlogN, pois cada inserção no set leva tempo proporcional 
log N — e são feitas N inserções.

Outra possível solução seria algo parecido com o seguinte:
sort (strings.begin(), strings.end());
res = 1;
for (int i = 1; i < n; ++i) {
   if (strings[i] != strings[i-1]) res++;
}

Nessa solução, primeiramente ordenamos um vector que contém todas as strings. O custo da ordenação padrão do C++ é o mesmo da 
nossa outra solução — nlogn, mas é até mais rápido. Com o vetor já ordenado, achamos a primeira ocorrência única de cada string 
comparando cada elemento do vetor com o anterior — quando esses valores são diferentes, estamos em uma string única.
Daqui alguns meses todos vocês que estão se empenhando vão com certeza olhar para trás e rir ao perceber quão simples era esse 
problema — quando isso acontecer venham me contar! :) Apesar disso, é um problema bom para praticar.
*/
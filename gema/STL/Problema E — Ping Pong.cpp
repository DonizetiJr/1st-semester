/*Problema E — Ping Pong
Nesse problema, temos 106 palavras, de até 20 caracteres cada, que compõe um dicionário. 
Queremos saber, para cada palavra, se ela é a junção de duas outras palavras do dicionário.
Vamos pensar inicialmente numa solução "burra", mas que resolveria o problema para casos pequenos. 
O problema envolve quebrar strings em duas partes não vazias — e verificar se as duas partes estão no dicionário. 
Vamos utilizar a função substr da string do C++. Porém, é importante ter uma idéia de como fazer essas coisas. 
Por exemplo, se quisessemos gerar todas as possíveis formas de dividir uma string, mas não sabemos que existe a 
função 'substr', podemos fazer assim:

void gera_divisoes (string s) {
    string esq = "";
    string dir = s;
    for (int i = 0; i < s.size()-1; ++i) {
       esq += s[i];
       dir.erase(1);
       cout << esq << " " << dir << endl;
    }
} 

Aqui, passamos pela string, atualizando as strings da esquerda e da direita a cada passo. 
Repare, entretanto, que utilizamos o método erase da string — esse método pode executar um número 
de operações proporcional ao tamanho da string. Ou seja, se nossa string fosse muito grande, poderíamos 
ter um problema. Não é o caso nesse problema, já que os tamanhos vão até 20 apenas.
A função substr da string nos retorna uma string, e recebe dois argumentos: a posição inicial onde desejamos 
extrair a substring, e o tamanho.
Com isso, iremos utilizar a mesma abordagem da solução do primeiro problema: iremos manter um set com todas as 
strings, e, para cada string, checar para todas as possíveis divisões se o lado direito e o lado esquerdo estão no set.
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	set <string> s;
	vector <string> v;
	string in;

	while (cin >> in){
		s.insert (in);
		v.push_back (in);
	}

	int ans = 0;
	for (int i=0; i<v.size(); i++){
		for (int t = 1; t <= v[i].size()-1; t++){
			string esq = v[i].substr (0, t);
			string dir = v[i].substr (t, v[i].size() - t);
			if (s.count(esq) > 0 and s.count(dir) > 0){
				ans ++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
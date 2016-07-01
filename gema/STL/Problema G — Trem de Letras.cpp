/* Problema G — Trem de Letras
Esse problema parece confuso no início. Processamos a sequência da esquerda para a direita. 
São dadas algumas regras para calcular a pontuação de uma sequência de letras — cada letra 
maiúscula perde 100 pontos. Para as letras minúsculas temos alguns casos, dependendo das letras 
maiúsculas que já apareceram até esse ponto
Se não apareceram letras maísculas ainda, ou se todas as que apareceram já foram utilizadas, 
perde-se 300 pontos
Se ainda há letras maísculas não processadas que aparecem antes da letra atual, pegue a letra que 
apareceu mais recentemente. Se ela for igual à letra minúscula em questão (por exemplo, A e a) 
ganha-se 200 pontos; se ela for diferente — perdem-se 100 pontos. Essa letra maiúscula que acabou 
de ser utilizada não pode ser mais utilizada pelas próximas letras minúsculas.
A descrição do procedimento para calcular a pontuação já nos fornece um algoritmo para calcular seu valor. 
Esse algoritmo não é bom, pois, como veremos, é muito lento — mas é interessante que você consiga implementá-lo. 
Vamos ao código.

const int N = 1000001;
int used[N];

int main (void) {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; ++i) {
       if (s[i] >= 'A' and s[i] <= 'Z') res -= 100;
       else {
           // Procuramos uma letra maiscula disponivel
           bool achou = false;
           for (int j = i - 1; j >= 0; --j) {
               if (s[j] >= 'A' and s[j] <= 'Z' and used[j] == false) {
                   if (s[j] - 'A' + 'a' == s[i]) res += 200;
                   else res -= 100;
                   achou = true;
                   used[j] = true;
                   break;
               }
           }
           if (!achou) res -= 300;
       }
    }
}
Aqui, utilizamos o truque de manter um vetor adicional dizendo, para cada posição, se ela já foi utilizada —
 e então ao encontrar uma letra minúscula literalmente procuramos alguma letra maíscula para trás (tomando o 
  cuidado de passar primeiro pelas mais recentes) que ainda não foi utilizada.
Com essa abordagem, podemos ter que fazer um número quadrático de operações. Imagine que o seu vetor só tem 
letras minúsculas — para cada letra minúscula, iremos passar por todos os elementos que aparecem antes. Esse 
é o mesmo número de operações da solução 'simples' do problema anterior — e é proporcional a n2.
É importante fazer uma pausa agora. Você pode pensar em, por exemplo, guardar quantas letras maísculas ainda 
estão disponíveis para trás, e só buscar quando realmente existirem letras maísculas para encontrar. De fato, 
se você fizer isso, para o caso onde só há letras minúsculas ('aaaaazsaflsaf', por exemplo), seu algoritmo vai 
ser rápido. É preciso tomar cuidado com esse tipo de 'otimização' — que resolve um problema específico, pois 
podem existir outros casos de teste que continuam lentos.
Um exemplo seria um caso de teste assim: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.
 Para as letras a que estão no final, ainda teremos que percorrer quase a string inteira para encontrar seu equivalente.
  Ou seja, a 'otimização' que encontramos não nos dá garantir nenhuma de que faremos menos operações.
O problema dessa solução é o fato de termos que percorrer coisas inúteis — letras minúsculas e letras maísculas já 
processadas. Para resolver isso, mantemos uma pilha (lembre-se: na pilha, o elemento que entrou mais recentemente é
 o próximo a sair) com as letras maísculas. Quando encontramos uma minúscula, basta checar o topo da pilha para ver 
se há uma letra maíscula correspondente — e, se houver, removemos essa letra maíscula da pilha — deixando no topo 
agora a letra que apareceu exatamente antes dela.
As operações de inserção e remoção na pilha levam tempo constante — ou seja, não dependem do tamanho da pilha. Então,
 em geral, faremos um número de operações proporcional apenas ao tamanho da sequuência — n. Segue a solução:
 */

#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string s;
    cin >> s;
    stack <char> v;
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' and s[i] <= 'Z') {
            v.push (s[i]);
            res -= 100;
        } else {
            if (v.empty()) res -= 300;
            else {
                char c = v.top(); v.pop();
                if (c == s[i]-'a'+'A') res += 200;
                else res -= 100;
            }
        }
    }
    cout << res << endl;
}

//Esse problema, no final, tinha uma estrutura similar ao problema da sequência de parênteses — resolvido em aulas. 
//Se quiser treinar algum outro problema assim, tente esse aqui: 
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614! :D
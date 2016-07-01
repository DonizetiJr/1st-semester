/*Loppa e seus amigos fizeram uma base secreta em cima de uma árvore para bolar planos malignos 
contra Samuel, seu arqui-inimigo. Com muito esforço, Team Loppa (o nome do grupo que Loppa criou) 
conseguiu bolar um plano que faria a noite do Samuel um inferno.

O plano que Team Loppa criou é: em uma certa noite, logo antes de Samuel dormir, um integrante do 
Team Loppa deixará tocando uma música perto de seu quarto durante um certo intervalo de tempo, alta 
o bastante para Samuel não conseguir dormir. Para organizar os períodos em que alguém tocaria uma 
música, Loppa construiu um quadro longo, traçando várias linhas a cada unidade de tempo, e cada 
integrante ai grudaria um papel da largura do intervalo em que deixaria a música tocando, grudando 
sua ponta esquerda na linha li e sua ponta direita na linha ri, estes valores escritos no papel, 
sendo que duas ou mais pessoas poderiam deixar sua música tocando ao mesmo tempo (ou seja, os papéis 
poderiam estar um em cima de outros).

Assim um grande recrutamento foi feito para novos integrantes do Team Loppa para fazer Samuel sofrer 
o máximo possível. Porém, como ter uma base secreta em cima de uma árvore é muito descolado, muita 
gente foi recrutada e o quadro estava cheio de papel, uns em cima de outros, e o peso fez com que 
todos caíssem.

Loppa teve que reorganizar todos os papéis e ficou tão pistola que decidiu pregar os papéis no quadro. 
Assim, decidiu comprar K pregos, porém ele gostaria que este fosse o menor número de pregos necessários 
para pregar todos sem mudar suas posições originais. Ajude-o a descobrir qual é o menor número de pregos 
para que ele não fique tão pistola.

Input
A entrada consiste de um inteiro N ≤ 106, o número de integrantes do Team Loppa. As próximas N linhas 
representam o tempo de início l e de término r que cada integrante irá deixar a música tocando, sendo 
que 0 ≤ l < r ≤ 109.

Output
Imprima um único inteiro K, que é o número de pregos que Loppa precisa para conseguir pregar todos os 
papeis no quadro de madeira.

Examples
input
2
1 3
2 4
output
1

input
3
0 4
1 2
2 4
output
2

input
3
10 15
16 20
30 40
output
3

Note
No caso 1, um prego entre as linhas 2 e 3 seria o bastante para deixar os dois papéis fixos em suas posições originais.

No caso 2, uma solução possível é por um prego entre as linhas 0 e 1 e outro entre em cima da linha 3. Perceba que colocar apenas um prego em cima da linha 2 não prenderia nem o papel 2 e nem o papel 3.

No caso 3, uma solução possível é por um prego na linha 12, outro prego na linha 17 e outro prego entre as linhas 32 e 33.
*/
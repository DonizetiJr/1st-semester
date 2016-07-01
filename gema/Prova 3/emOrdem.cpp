/*Viajando pelo mundo antigo, você encontrou um pergaminho com uma matriz N por M. Cada entrada dessa 
matriz é um número - correspondente a um hieróglifo. Você sabe que os números dos hieróglifos determinam
 sua ordem lexicográfica, ou seja, o hieróglifo 1 aparece no alfabeto antes do 2 e assim por diante.

Inspecionando a matriz, você percebeu que nenhum hieróglifo se repete. Além disso, no canto do pergaminho
 estavam os seguintes dizeres:

"As colunas dessa tabela aqui descrita formam palavras. Se você conseguir trocar as linhas dessa matriz 
de lugar de forma que as palavras formadas pelas colunas 1, 2..m estejam em ordem alfabética, farei de ti 
rei ou rainha da Babilônia." A palavra formada pela i-ésima coluna é a palavra formada pelos hieróglifos
 h0i, h1i, ..., hni.

Você claramente não quer ser rei nem rainha da Babilônia, mas o desafio pareceu legal. Responda se é possível 
resolver o desafio.

Input
A entrada começa com dois inteiros, N e M (1 ≤ N, M ≤ 1000), o número de linhas e colunas.

Seguem N linhas, cada uma contendo M números aij (1 ≤ aij ≤ N * M). Não há números repetidos na entrada.

Output
Imprima S se for possível mudar as linhas de lugar de forma a deixar as palavras geradas pelas colunas ordenadas
 e N caso contrário.

Examples
input
5 5
17 18 16 10 21
8 19 3 20 7
24 5 22 4 6
1 2 14 9 23
12 11 13 25 15

output
N

input
5 5
6 1 17 18 14
22 19 24 13 2
9 10 12 15 21
5 7 16 3 11
23 25 20 8 4

output
S
*/
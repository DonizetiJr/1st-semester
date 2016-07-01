/*Dado um vetor com N números, você deverá responder Q operações. Cada uma das operações 
te dará um intervalor (l, r), para o qual você deverá dizer a soma do número de divisores 
de cada um dos números no intervalo.

Input
A entrada começa com um inteiro, N (1 ≤ N ≤ 105), o número de elementos do vetor. Segue uma 
linha com N inteiros xi (1 ≤ xi ≤ 106). A linha seguinte contém um inteiro Q (1 ≤ Q ≤ 106), 
o número de perguntas. Seguem Q linhas com dois inteiros l, r cada, o intervalo em questão 
(1 ≤ l ≤ r ≤ N).

Output
Imprima, para cada pergunta, sua resposta em uma linha separada.

Example
input
10
4 10 37 84 3 81 3 32 36 52
4
5 9
3 9
1 10
2 10
output
24
38
51
48

Note
Como o input é muito grande, utilize scanf para ler a entrada.
*/
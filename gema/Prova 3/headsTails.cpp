/*Alice e Bob estão jogando um jogo de cara ou coroa, a cada rodada eles lançam uma moeda, 
que tem probabilidade p de sair cara e 1 - p de sair coroa. Se sair cara Bob ganha aquela 
rodada, se sair coroa Alice ganha.

Se a rodada n teve como vencedor Alice, ela ganha o jogo se o número de rodadas que Bob ganhou 
é maior que zero. Se a rodada n teve como vencedor Bob, ele vence o jogo se o número de rodadas 
que ele ganhou é maior do que o número de rodadas que Alice ganhou. Repare que o jogo pode não 
ter vencedor.

Dado N, o número máximo de rodadas jogadas e p, a probabilidade da moeda lançada sair cara, responda 
qual é a probabilidade de Bob ganhar o jogo.

Input
Um inteiro 0 < N ≤ 109 e um número ponto flutuante 0 ≤ p ≤ 1.

Output
Apenas um número, que representa a probabilidade de Bob vencer o jogo. Imprima-o com quatro casas decimais.

Examples
input
3 0.5
output
0.6250
input
5 0.81
output
0.9538
input
2 0.5
output
0.5000
input
1 0.777
output
0.7770
Note
No primeiro caso Bob só ganha se acontecer:

B (probabilidade 0.5)

ABB (probabilidade 0.53)
*/
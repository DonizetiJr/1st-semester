/*Pois é, mais uma fase do Super Mario GEMA.

Dessa vez, a fase é composta por plataformas horizontais voadoras. A fase pode ser 
representada por um retângulo de largura N situado na coordenada x = 0.

Você inicia a fase no canto esquerdo da plataforma superior esquerda. A cada instante, 
você pode andar até um dos limites da plataforma onde se encontra. Se estiver no limite 
de uma plataforma, duas ações são possíveis: cair, aterrissando na plataforma que estiver 
imediatamente abaixo ou pular para a plataforma do lado, se existir uma plataforma na mesma 
posição vertical que a atual.

Mario se move em 1m/s. As coordenadas das plataformas horizontais e suas posições verticais 
também são dadas em metros. Pular e cair têm a mesma velocidade que Mario. Descubra o tempo 
mínimo necessário para chegar no chão - em qualquer posição horizontal.

Se mario passar do limite esquerdo da fase, sairá do lado direito.

Input
A entrada começa com dois números, N e K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 105, a largura da fase e o 
número de plataformas.

Seguem K linhas, cada uma com três inteiros xe, xd e y (0 ≤ xe, xd ≤ 1000, 1 ≤ y ≤ 1000), as 
coordenadas da esquerda de uma plataforma, da direita e sua posição em y.

Output
Imprima o tempo mínimo necessário para Mario cair no chão. Se for impossível, imprima -1.

Examples
input
5 3
0 2 4
4 5 4
2 4 2
output
5

input
4 4
0 1 5
0 2 4
2 4 2
0 1 2
output
6

input
100 6
0 2 10
3 4 10
0 4 9
5 100 9
0 4 8
5 100 8
output
14
*/
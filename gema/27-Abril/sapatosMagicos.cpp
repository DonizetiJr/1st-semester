/*Um personagem de um jogo antigo está na coordenada (0, 0) de um grid bi-dimensional.

Você encontra um vendedor de sapatos misterioso misterioso, que afirma que para chegar à próxima cidade, 
precisará dos sapatos que ele vende. De fato, o mapa parece cheio de espinhos e os sapatos com certeza serão 
úteis - e você opta por compra todos.

Cada sapato mágico te permite dar saltos, porém de diferentes distâncias. Cada sapato possuí duas informações 
- a quantidade em x que ele pula e a quantidade em y. Ou seja, se um sapato for do tipo (2, 4), isso significa
 que, se você estiver na posição (0, 0) e pular utilizando esse sapato, irá parar na posição (2, 4).

Você sabe que dar um pulo leva 1 segundo, e trocar de sapato também leva 1 segundo. Descubra o tempo mínimo
 necessário para chegar na posição (N, M) - a entrada da próxima cidade. Considere que você não pode sair do 
 mapa - ou seja, não pode ir para posições com coordenadas negativas ou maiores que N em x d M em y.

Não conte o tempo de colocar o primeiro sapato.

Input
A entrada começa com três inteiros, N, M (1 ≤ N, M ≤ 100), a posição da entrada da cidade, e C (1 ≤ C ≤ 100), 
o número de sapatos. Seguem C linhas, cada uma com dois valores (x, y), (1 ≤ x, y ≤ 100), descrevendo o salto 
fornecido pelo i-ésimo sapato.

Output
Imprima o tempo mínimo para chegar na cidade. Se for impossível chegar, imprima -1.

Examples
input
3 3 3
1 2
1 1
2 2
output
3

input
15 5 10
1 2
6 3
3 3
3 1
3 1
1 5
4 5
5 3
6 1
7 1
output
4

input
3 3 2
1 1
3 3
output
1
*/
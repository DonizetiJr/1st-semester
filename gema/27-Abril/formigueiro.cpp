/*A colônia de formigas do seu quintal está se mudando. Para isso, resolveram buscar 
os materiais em uma árvore nas proximidades.

A árvore é composta por diversos galhos. O tronco principal encontra-se no chão, e as
 formigas sobem inicialmente por ele. À partir do tronco, cada galho pode possuír diversas
  bifurcações. A árvore é descrita por essas bifurcações (considerando que o chão é uma bifurcação)
   e o tamanho do tronco entre elas.

As formigas sabem que existem materiais espalhados em alguns troncos. Em específico, elas conhecem 
a localização de cada um dos materiais - a birfurcação onde eles estão.

A formiga-rainha gostaria de mandar algumas formigas coletar os materiais. Suas formigas, entretanto, 
andam uma determinada distância e depois morrem. Se elas estão carregando algum material no momento da
 morte, o material caí exatamente na posição onde a formiga estava. Cada formiga pode pegar no máximo
  um material - depois de atingir o chão ela volta para o formigueiro com o material.

A rainha gostaria de saber qual o número mínimo de formigas que ela precisa enviar para conseguir coletar 
todos os materiais, sabendo que ela vai enviar uma formiga por vez e que cada formiga coleta apenas um item 
por vez.

Se um material estiver mais longe do que uma formiga consiga alcançar, a rainha desconsiderará esse material.

Input
A entrada começa com dois números N(1 ≤ N ≤ 103) e K (1 ≤ K ≤ 1018), o número de bifurcações da árvore e o 
tempo que uma formiga passa viva. A bifurcação 1 é sempre a raíz. Seguem então N - 1 linhas, cada uma com 
três números: a, b, c (1 ≤ a, b ≤ 103, 1 ≤ c ≤ 109), indicando que há um tronco entre as bifurcações a e b 
e esse tronco mede c centímetros. A linha seguinte contém um inteiro, M (1 ≤ M ≤ 106), o número de materiais 
espalhado nas bifurcações. Seguem então M linhas, cada uma contendo um inteiro x (1 ≤ x ≤ N), indicando o 
índice da bifurcação do i-ésimo material.

Output
Imprima a quantidade mínima de formigas necessárias para realizar o trabalho.

Example
input
2 11
1 2 10
1
2
output
4
*/